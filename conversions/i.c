/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   i.c                                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 20:47:16 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/18 12:32:17 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "conversions.h"

bool	pf_i(t_conversion_in *c_in, t_conversion_out *c_out, va_list *argl)
{
	return (pf_d(c_in, c_out, argl));
}