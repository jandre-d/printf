/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   s_upper.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/22 18:05:21 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/25 14:21:14 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pf_printf.h"

bool	pf_s_upper(t_conversion_in *c_in, t_conversion_out *c_out,
	va_list *argl)
{
	int *x = va_arg(*argl, int *);
	char *nul = "(null)";
	if (x == NULL)
	{
		c_out->len = 6;
		c_out->str = TAKE_MULTI(char, 7, "pf_s");
		if (c_out->str == NULL)
			return (false);
		ft_strcpy(c_out->str, (const char *)nul);
	}
	else
	{
		c_out->str = pf_wstr_to_str(x, &c_out->len);
		if (c_out->str == NULL)
			return (false);
	}
	return (true);
}