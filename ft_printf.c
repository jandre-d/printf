/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/01 16:47:38 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/18 16:07:51 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "conversions/conversions.h"
#include "ft_printf.h"
#include "read_instruction.h"
#include "libft/libft.h"
#include "libpf/libpf.h"
#include <unistd.h>

static inline bool do_instruction(t_conversion_in *c_in,
	t_conversion_out *c_out, va_list *argl)
{
	return (
	(c_in->conversion_type == 'c' && pf_c(c_in, c_out, argl)) ||
	(c_in->conversion_type == 's' && pf_s(c_in, c_out, argl)) ||
	(c_in->conversion_type == 'p' && pf_p(c_in, c_out, argl)) ||
	(c_in->conversion_type == 'd' && pf_d(c_in, c_out, argl)) ||
	(c_in->conversion_type == 'i' && pf_i(c_in, c_out, argl)) ||
	(c_in->conversion_type == 'o' && pf_o(c_in, c_out, argl)) ||
	(c_in->conversion_type == 'u' && pf_u(c_in, c_out, argl)) ||
	(c_in->conversion_type == 'x' && pf_x(c_in, c_out, argl)) ||
	(c_in->conversion_type == 'X' && pf_x_upper(c_in, c_out, argl)) ||
	(c_in->conversion_type == 'f' && pf_f(c_in, c_out, argl)) ||
	(c_in->conversion_type == '%' && pf_percent(c_in, c_out, argl)));
}

static int64_t	n_till_instruction(char *str)
{
	int64_t n;

	n = 0;
	while (str[n] && str[n] != '%')
	{
		n++;
	}
	return (n);
}	

static void loop(char *str, va_list *argl, t_pf_output *output)
{
	t_conversion_in c_in;
	t_conversion_out c_out;
	int64_t till_instruction;

	till_instruction = 0;
	while (*str)
	{
		ft_bzero((void *)&c_in, sizeof(t_conversion_in));
		ft_bzero((void *)&c_out, sizeof(t_conversion_out));
		till_instruction = n_till_instruction(str);
		pf_append_right(output, str, till_instruction, false);
		str += till_instruction;
		if (*str == '\0')
			return ;
		if (read_instruction(&str, &c_in))
		{
			if (do_instruction(&c_in, &c_out, argl))
				pf_append_right(output, c_out.str, c_out.len, true);
			else
				ft_putstr("specerijen malloc NULL");
		}
		else
			ft_putstr("incorect formant");
		str++;
	}
}

int	ft_printf(const char *str, ...)
{
	va_list argl;
	t_pf_output output;
	output.str = TAKE(char, "ft_printf");
	output.str_size = 1;
	output.str_useage = 0;
	va_start(argl, str);
	loop((char *)str, &argl, &output);
	va_end(argl);
	write(1, output.str, output.str_useage);
	GIVE(output.str, "ft_printf");
	return (output.str_useage);
}

// #include <stdio.h>

// int main()
// {
// 	//ft_printf("%.24s%s %42sxxxx", "waaaat", "second", "where am i");
// 	//ft_printf("hello %c %d %i %o %% %s %u %x %X\n", 't', 42, 24, 9, "banaan", 10, 15, 15);
// 	double xx = 5.3;
// 	int32_t len = 0;
// 	//ft_printf("%f", xx);
// 	printf("\"%s\"", pf_ldtoa(xx, 6, &len));
// 	//printf("\"%+.7d\"\n", 42);
// }