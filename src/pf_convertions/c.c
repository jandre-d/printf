/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   c.c                                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 20:47:06 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/29 13:21:46 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pf_printf.h"

bool	pf_c(t_conversion_in *c_in, t_conversion_out *c_out, va_list *argl)
{
	int x;

	x = va_arg(*argl, int);
	if (c_in->mod_l)
	{
		c_out->str = pf_wchar_to_str(x, &c_out->len);
		if (c_out->str == NULL)
			return (false);
	}
	else
	{
		c_out->str = TAKE_MULTI(char, 2, "pf_c");
		if (c_out->str == NULL)
			return (false);
		c_out->len = 1;
		c_out->str[0] = x;
	}
	return (padding_general(c_in, c_out, false));
}
