/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_uintlen.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/12 14:09:33 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/13 21:41:21 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libpf.h"

int8_t	pf_uintlen(uint64_t value, uint8_t base)
{
	int8_t to_return;

	to_return = 0;
	if (value == 0)
	{
		to_return += 1;
	}
	else
		while (value != 0)
		{
			value /= base;
			to_return += 1;
		}
	return (to_return);
}