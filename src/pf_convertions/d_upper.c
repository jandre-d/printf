/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   d_upper.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/22 18:03:53 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/22 18:43:25 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pf_printf.h"

bool	pf_d_upper(t_conversion_in *c_in, t_conversion_out *c_out,
	va_list *argl)
{
	c_out->str = pf_itoa_base(va_arg(*argl, int64_t), 10, &c_out->len, true);
	return (c_out->str != NULL);
}