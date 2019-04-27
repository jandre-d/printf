/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ouxX.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 15:07:43 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/27 19:57:58 by jandre-d      ########   odam.nl         */
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
	if (c_in->flag_plus && c_in->conversion_type != 'o')
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
	uint64_t value;
	int8_t	base;
	bool	lowercase;
	bool	res_empty;
	bool	not_zero;

	res_empty = false;
	lowercase = c_in->conversion_type != 'X';
	if (c_in->conversion_type == 'o')
		base = 8;
	else if (c_in->conversion_type == 'u')
		base = 10;
	else
		base = 16;
	if (
		(c_in->mod_hh && ((value = (unsigned char)va_arg(*argl, unsigned int)) || 1)) ||
		(c_in->mod_h && ((value = (unsigned short)va_arg(*argl, unsigned int)) || 1)) ||
		(c_in->mod_l && ((value = va_arg(*argl, unsigned long)) || 1)) ||
		(c_in->mod_ll && ((value = va_arg(*argl, unsigned long long)) || 1)) ||
		((value = va_arg(*argl, unsigned int)) || 1)
	)
	;
	if (value == 0 && c_in->precision_default == false && c_in->precision == 0)
	{
		res_empty = true;
		c_out->str = TAKE(char, "pf_di");
		if (c_out->str == NULL)
			return (false);
		c_out->len = 0;
	}
	else
		c_out->str = pf_uitoa_base(value, base, c_out, lowercase);
	if (c_out->str == NULL)
		return (false);
	not_zero = c_out->str[0] != '0';
	if (padding(c_out, '0', true, c_in->precision) == false)
		return (false);
	if (c_in->flag_hash && not_zero)
	{
		if (c_in->conversion_type == 'X' && res_empty == false)
			pf_prepend_to_c_out(c_out, "0X", 2);
		else if (c_in->conversion_type == 'x' && res_empty == false)
			pf_prepend_to_c_out(c_out, "0x", 2);
		else if (c_in->conversion_type == 'o' && c_out->str[0] != '0')
			pf_prepend_to_c_out(c_out, "0", 1);
	}
	return (flags_and_mods(c_in, c_out));
}
