/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/12 13:42:11 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/12 21:31:50 by jandre-d      ########   odam.nl         */
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
			*i--;
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
	i = pf_st
	to_return = TAKE_MULTI(char, i + 1, "pf_itoa_base");
	if (to_return == NULL)
		return (FALSE);



	i--;
	value = inp->int_value;
	set_value(res, &value, &i);
	while (i >= 0)
	{
		res->str[i] = value % 10 + '0';
		value /= 10;
		i--;
	}
	if (inp->int_value < 0)
		res->str[i] = '-';
	return (TRUE);
}