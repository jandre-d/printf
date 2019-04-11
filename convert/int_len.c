/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   int_len.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/11 16:07:38 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/11 16:10:11 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static inline int64_t	int_len(int64_t value)
{
	int64_t i;

	i = 0;
	if (value < 0)
		i += 1;
	if (value == 0)
		i = 1;
	else
		while (value != 0)
		{
			value /= 10;
			i += 1;
		}
	return (i);
}