/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/12 13:42:11 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/13 21:44:48 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libpf.h"

static inline void	max_negative_value_case(int64_t *value, int8_t *i, char *str)
{
	if (*value < 0)
	{
		if (*value < -9223372036854775807LL)
		{
			*value = 922337203685477580LL;
			str[*i] = '8';
			*i -= 1;
		}
		else
			*value = -*value;
	}
}

char			*pf_itoa_base(int64_t value, int8_t base, t_bool lowercase)
{
	char	*to_return;
	char	*character_set;
	int8_t	i;
	t_bool	is_negative;

	if (base < 2 || base > 16)
		return (NULL);
	is_negative = value < 0;
	character_set = lowercase ? "0123456789abcdef" : "0123456789ABCDEF";
	i = pf_intlen(value, base);
	to_return = TAKE_MULTI(char, i + 1, "pf_itoa_base");
	if (to_return == NULL)
		return (NULL);
	i--;
	max_negative_value_case(&value, &i, to_return);
	while (i >= 0)
	{
		to_return[i] = character_set[value % base];
		value /= base;
		i--;
	}
	if (is_negative)
		to_return[0] = '-';
	return (to_return);
}