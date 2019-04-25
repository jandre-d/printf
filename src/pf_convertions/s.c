/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   s.c                                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 20:35:06 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/25 16:03:56 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pf_printf.h"

bool	set_null_text(t_conversion_out *c_out)
{
	char *nul = "(null)";
	
	c_out->len = 6;
	c_out->str = TAKE_MULTI(char, 7, "pf_s");
	if (c_out->str == NULL)
		return (false);
	pf_memcpy(c_out->str, nul, c_out->len);
	return (true);
}

bool	for_str(t_conversion_out *c_out, va_list *argl)
{
	char *str;

	str = va_arg(*argl, char *);
	if (str == NULL)
		return(set_null_text(c_out));
	c_out->len = ft_strlen(str);
	c_out->str = TAKE_MULTI(char, c_out->len + 1, "pf_s");
	if (c_out->str == NULL)
		return (false);
	pf_memcpy(c_out->str, str, c_out->len);
	return (true);
}

bool	for_wstr(t_conversion_out *c_out, va_list *argl)
{
	int *wstr;

	wstr = va_arg(*argl, int *);
	if (wstr == NULL)
		return (set_null_text(c_out));
	c_out->str = pf_wstr_to_str(wstr, &c_out->len);
	if (c_out->str == NULL)
		return (false);
	return (true);
}

bool	pf_s(t_conversion_in *c_in, t_conversion_out *c_out, va_list *argl)
{
	if (c_in->mod_l)
	{
		return (for_wstr(c_out, argl));
	}
	else
	{
		return (for_str(c_out, argl));
	}
}