/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/01 16:47:38 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/14 14:20:30 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <unistd.h>

int	printf(const char *format, ...)
{
	va_list argl;
	char *res;
	int res_len;

	va_start(argl, format);

	va_end(argl);
	write(1, res, res_len);
	return (res_len);
}
