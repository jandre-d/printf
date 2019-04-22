/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   c_upper.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/22 18:49:17 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/22 18:51:42 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pf_printf.h"

bool	pf_c_upper(t_conversion_in *c_in, t_conversion_out *c_out,
	va_list *argl)
{
	return (pf_c(c_in, c_out, argl));
}