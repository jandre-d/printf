/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   di.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 15:07:22 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/26 20:54:59 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pf_printf.h"

static inline bool flags_and_mods(t_conversion_in *c_in, t_conversion_out *c_out)
{
	if (c_in->precision_default == false)
		c_in->flag_0 = false;
	if ((c_in->flag_plus || c_in->flag_space) && c_in->flag_0)
		c_in->padding -= 1;
	if (c_in->flag_0)
		if (padding_general(c_in, c_out, false) == false)
			return (false);
	if (c_in->flag_plus && c_out->is_negative == false)
	{
		if (pf_prepend_to_c_out(c_out, "+", 1) == false)
			return (false);
	}
	else if (c_in->flag_space && c_out->is_negative == false)
	{
		if (pf_prepend_to_c_out(c_out, " ", 1) == false)
			return (false);
	}
	if (c_out->is_negative)
		if (pf_prepend_to_c_out(c_out, "-", 1) == false)
			return (false);
	if (padding_general(c_in, c_out, false) == false)
			return (false);
	return (true);
}

bool	pf_di(t_conversion_in *c_in, t_conversion_out *c_out, va_list *argl)
{
	if (c_in->mod_l)
		c_out->str = pf_itoa_base(va_arg(*argl, long), 10, c_out, true);
	else if (c_in->mod_ll)
		c_out->str = pf_itoa_base(va_arg(*argl, long long), 10, c_out, true);
	else
		c_out->str = pf_itoa_base(va_arg(*argl, int), 10, c_out, true);
	if (c_out->str == NULL)
		return (false);
	return (flags_and_mods(c_in, c_out));
}
