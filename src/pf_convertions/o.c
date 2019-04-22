/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   o.c                                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 20:47:18 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/22 18:31:56 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pf_printf.h"

bool	pf_o(t_conversion_in *c_in, t_conversion_out *c_out, va_list *argl)
{
	c_out->str = pf_uitoa_base(va_arg(*argl, uint64_t), 8, &c_out->len, true);
	return (c_out->str != NULL);
}