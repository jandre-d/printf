/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/01 16:47:38 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/17 18:42:52 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "read_instruction.h"
# include "libft/libft.h"
# include "libpf/libpf.h"
#include <stdio.h>

static int64_t	n_till_instruction(char **str)
{
	int64_t n;

	n = 0;
	while (**str && **str != '%')
	{
		*str += 1;
		n++;
	}
	return (n);
}	

static void loop(char *str, va_list *argl, t_output *output)
{
	t_conversion_input c_in;
	t_conversion_result c_res;

	while (*str)
	{
		ft_bzero((void *)&c_in, sizeof(t_conversion_input));
		ft_bzero((void *)&c_res, sizeof(t_conversion_result));
		str += n_till_instruction(&str);
		if (*str == '\0')
			return ;
		if (read_instruction(&str, &c_in))
		{
			int x = 2;
			//do instruction
		}
		else
		{
			//incorect format
		}
		str++;
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
	loop((char *)str, &argl, &output);
	va_end(argl);
	write(1, output.str, output.str_useage);
	GIVE(output.str, "ft_printf");
	return (output.str_useage);
}

int main()
{
	ft_printf("%- +d");
	printf("hello");
}