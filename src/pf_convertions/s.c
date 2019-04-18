/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   s.c                                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 20:35:06 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/18 17:15:12 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pf_printf.h"

bool	pf_s(t_conversion_in *c_in, t_conversion_out *c_out, va_list *argl)
{
	char *x = va_arg(*argl, char *);
	c_out->len = ft_strlen(x);
	c_out->str = TAKE_MULTI(char, c_out->len + 1, "pf_s");
	ft_strcpy(c_out->str, (const char *)x);
	return (true);
}