/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ouxX.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 15:07:43 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/25 15:51:01 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pf_printf.h"

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
		c_out->str = pf_uitoa_base(va_arg(*argl, int), base, &c_out->len, lowercase);
	else if (c_in->mod_l)
		c_out->str = pf_uitoa_base(va_arg(*argl, unsigned long), base, &c_out->len, lowercase);
	else if (c_in->mod_ll)
		c_out->str = pf_uitoa_base(va_arg(*argl, unsigned long long), base, &c_out->len, lowercase);
	return (c_out->str != NULL);
}
