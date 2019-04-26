/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ouxX.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 15:07:43 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/26 20:53:59 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pf_printf.h"

static inline bool flags_and_mods(t_conversion_in *c_in, t_conversion_out *c_out)
{
	if (c_in->precision_default == false)
		c_in->flag_0 = false;
	if ((c_in->flag_plus) && c_in->flag_0)
		c_in->padding -= 1;
	if (c_in->flag_0)
		if (padding_general(c_in, c_out, false) == false)
			return (false);
	if (c_in->flag_plus)
	{
		if (pf_prepend_to_c_out(c_out, "+", 1) == false)
			return (false);
	}
	if (padding_general(c_in, c_out, false) == false)
			return (false);
	return (true);
}

bool	pf_ouxX(t_conversion_in *c_in, t_conversion_out *c_out, va_list *argl)
{
	int8_t	base;
	bool	lowercase;

	lowercase = c_in->conversion_type != 'X';
	if (c_in->conversion_type == 'o')
		base = 8;
	else if (c_in->conversion_type == 'u')
		base = 10;
	else
		base = 16;
	if (c_in->mod_hh || c_in->mod_h)
		c_out->str = pf_uitoa_base(va_arg(*argl, int), base, c_out, lowercase);
	else if (c_in->mod_l)
		c_out->str = pf_uitoa_base(va_arg(*argl, unsigned long), base, c_out, lowercase);
	else if (c_in->mod_ll)
		c_out->str = pf_uitoa_base(va_arg(*argl, unsigned long long), base, c_out, lowercase);
	else
		c_out->str = pf_uitoa_base(va_arg(*argl, unsigned int), base, c_out, lowercase);
	if (c_out->str == NULL)
		return (false);
	if ((c_in->conversion_type == 'x' || c_in->conversion_type == 'X') && c_in->flag_hash && c_out->str[0] != '0')
	{
		if (c_in->conversion_type == 'x')
			pf_prepend_to_c_out(c_out, "0x", 2);
		else
			pf_prepend_to_c_out(c_out, "0X", 2);
	}
	if (c_in->conversion_type == 'o' && c_in->flag_hash && c_out->len >= c_in->precision)
		c_in->precision = c_out->len + 1;
	padding(c_out, '0', true, c_in->precision);
	return (flags_and_mods(c_in, c_out));
}
