/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/01 16:47:38 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/29 17:18:57 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pf_printf.h"

static inline bool		do_instruction(t_conversion_in *c_in,
	t_conversion_out *c_out, va_list *argl)
{
	return (
	(c_in->conversion_type == 'c' && pf_c(c_in, c_out, argl)) ||
	(c_in->conversion_type == 's' && pf_s(c_in, c_out, argl)) ||
	(c_in->conversion_type == 'p' && pf_p(c_in, c_out, argl)) ||
	(c_in->conversion_type == 'd' && pf_di(c_in, c_out, argl)) ||
	(c_in->conversion_type == 'i' && pf_di(c_in, c_out, argl)) ||
	(c_in->conversion_type == 'o' && pf_ouxx(c_in, c_out, argl)) ||
	(c_in->conversion_type == 'u' && pf_ouxx(c_in, c_out, argl)) ||
	(c_in->conversion_type == 'X' && pf_ouxx(c_in, c_out, argl)) ||
	(c_in->conversion_type == 'x' && pf_ouxx(c_in, c_out, argl)) ||
	(c_in->conversion_type == 'f' && pf_f(c_in, c_out, argl)) ||
	(c_in->conversion_type == 'b' && pf_b(c_in, c_out, argl)) ||
	(c_in->conversion_type == 'r' && pf_r(c_in, c_out, argl)) ||
	(c_in->conversion_type == 'j' && pf_j(c_in, c_out, argl)) ||
	(c_in->conversion_type == '%' && pf_percent(c_in, c_out)));
}

static inline int64_t	n_till_instruction(char *str)
{
	int64_t n;

	n = 0;
	while (str[n] && str[n] != '%')
	{
		n++;
	}
	return (n);
}

static inline bool		start_instruction(t_conversion_in *c_in,
	t_conversion_out *c_out, va_list *argl, t_pf_output *output)
{
	if (do_instruction(c_in, c_out, argl))
		return (pf_append(output, c_out->str, c_out->len, true));
	else
		return (false);
}

static inline bool		loop(char *str, va_list *argl, t_pf_output *output)
{
	t_conversion_in		c_in;
	t_conversion_out	c_out;
	int64_t				till_instruction;

	while (*str)
	{
		ft_bzero((void *)&c_in, sizeof(t_conversion_in));
		ft_bzero((void *)&c_out, sizeof(t_conversion_out));
		till_instruction = n_till_instruction(str);
		if (pf_append(output, str, till_instruction, false) == false)
			return (false);
		str += till_instruction;
		if (*str == '\0')
			return (true);
		if (read_instruction(&str, &c_in) == false)
			return (false);
		if (start_instruction(&c_in, &c_out, argl, output) == false)
			return (false);
		if (*str == '\0')
			return (true);
		str++;
	}
	return (true);
}

int						ft_printf(const char *format, ...)
{
	va_list		argl;
	t_pf_output	output;

	output.str = TAKE(char, "ft_printf");
	output.str_size = 1;
	output.str_useage = 0;
	va_start(argl, format);
	if (loop((char *)format, &argl, &output) == false)
	{
		GIVE(output.str, "ft_printf");
		return (-1);
	}
	va_end(argl);
	write(1, output.str, output.str_useage);
	GIVE(output.str, "ft_printf");
	return (output.str_useage);
}
