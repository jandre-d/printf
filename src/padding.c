/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   padding.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/26 13:40:46 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/26 17:28:25 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pf_printf.h"

bool	padding(t_conversion_out *c_out, char padd_char, bool padd_left,
	int32_t min_width)
{
	char *new_str;

	if (c_out->len >= min_width)
		return (true);
	new_str = TAKE_MULTI(char, min_width, "padding");
	pf_memset(new_str, padd_char, min_width);
	if (padd_left)
		pf_memcpy(new_str + (min_width - c_out->len), c_out->str, c_out->len);
	else
		pf_memcpy(new_str, c_out->str, c_out->len);
	GIVE(c_out->str, "padding");
	c_out->str = new_str;
	c_out->len = min_width;
	return (true);
}

bool	padding_general(t_conversion_in *c_in, t_conversion_out *c_out,
	bool ignore_zero_flag)
{
	if (c_in->flag_min)
		return (padding(c_out, ' ', false, c_in->padding));
	else if (c_in->flag_0 && !ignore_zero_flag)
		return (padding(c_out, '0', true, c_in->padding));
	else
		return (padding(c_out, ' ', true, c_in->padding));
}