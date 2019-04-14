/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/01 16:47:38 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/14 16:20:48 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <unistd.h>



int	printf(const char *format, ...)
{
	va_list argl;
	char *res;
	int	len;

	va_start(argl, format);

	va_end(argl);
	len = ft_strlen(res);
	write(1, res, len);
	return (len);
}
