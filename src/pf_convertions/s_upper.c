/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   s_upper.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/22 18:05:21 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/22 18:05:55 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pf_printf.h"

bool	pf_s_upper(t_conversion_in *c_in, t_conversion_out *c_out,
	va_list *argl)
{
	return (pf_s(c_in, c_out, argl));
}