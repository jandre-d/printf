/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/01 16:47:38 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/16 14:13:55 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void append(t_output *output, char *str, size_t str_len)
{

}

static void loop(char *str, va_list argl, t_output *output)
{
	int64_t i;
	t_conversion_input c_in;

	ft_bzero((void *)&c_in, sizeof(t_conversion_input));

	i = 0;

}

int	ft_printf(const char *str, ...)
{
	va_list argl;
	t_output output;
	output.str_size = 0;
	output.str_useage = 0;
	output.str = TAKE(char, "ft_printf");
	va_start(argl, str);

	va_end(argl);
	write(1, output.str, output.str_useage);
	GIVE(output.str, "ft_printf");
	return (output.str_useage);
}
