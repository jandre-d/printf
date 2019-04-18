/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   f.c                                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 20:47:14 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/18 12:46:28 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "conversions.h"

bool	pf_f(t_conversion_in *c_in, t_conversion_out *c_out, va_list *argl)
{
	c_out->str = pf_ldtoa(va_arg(*argl, long double), c_in->precision, &c_out->len);
	return (c_out->str != NULL);
}