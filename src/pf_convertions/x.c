/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   x.c                                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 20:47:31 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/18 17:14:46 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pf_printf.h"

bool	pf_x(t_conversion_in *c_in, t_conversion_out *c_out, va_list *argl)
{
	c_out->str = pf_uitoa_base(va_arg(*argl, unsigned int), 16, &c_out->len, true);
	return (c_out->str != NULL);
}