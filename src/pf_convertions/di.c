/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   di.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 15:07:22 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/25 15:51:01 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pf_printf.h"

bool	pf_di(t_conversion_in *c_in, t_conversion_out *c_out, va_list *argl)
{
	if (c_in->mod_hh || c_in->mod_h)
		c_out->str = pf_itoa_base(va_arg(*argl, int), 10, &c_out->len, true);
	else if (c_in->mod_l)
		c_out->str = pf_itoa_base(va_arg(*argl, long), 10, &c_out->len, true);
	else if (c_in->mod_ll)
		c_out->str = pf_itoa_base(va_arg(*argl, long long), 10, &c_out->len, true);
	return (c_out->str != NULL);
}
