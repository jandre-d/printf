/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_uitoa_base.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/12 14:09:36 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/14 18:36:34 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libpf.h"

char			*pf_uitoa_base(uint64_t value, int8_t base, bool lowercase)
{
	char	*to_return;
	char	*character_set;
	int8_t	i;

	if (base < 2 || base > 16)
		return (NULL);
	character_set = lowercase ? "0123456789abcdef" : "0123456789ABCDEF";
	i = pf_uintlen(value, base);
	to_return = TAKE_MULTI(char, i + 1, "ft_itoa_base");
	if (to_return == NULL)
		return (NULL);
	i--;
	while (i >= 0)
	{
		to_return[i] = character_set[value % base];
		value /= base;
		i--;
	}
	return (to_return);
}
