/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/01 16:47:38 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/17 12:06:18 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "read_instruction.h"
#include <unistd.h>

static int64_t	n_till_instruction(char **str)
{
	int64_t n;

	n = 0;
	while (**str && **str != '%')
	{
		*str++;
		n++;
	}
	return (n);
}	

static void loop(char *str, va_list *argl, t_output *output)
{
	t_conversion_input c_in;
	t_conversion_result c_res;

	ft_bzero((void *)&c_in, sizeof(t_conversion_input));
	while (*str)
	{
		str += n_till_instruction(&str);
		if (read_instruction(&str, &c_in))
		{
			//do instruction
		}
		else if (str != '\0')
		{
			//incorect format
		}
	}
}

int	ft_printf(const char *str, ...)
{
	va_list argl;
	t_output output;
	output.str = TAKE(char, "ft_printf");
	output.str_size = 1;
	output.str_useage = 0;
	va_start(argl, str);
	loop(str, &argl, &output);
	va_end(argl);
	write(1, output.str, output.str_useage);
	GIVE(output.str, "ft_printf");
	return (output.str_useage);
}
