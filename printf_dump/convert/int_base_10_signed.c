/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   int_base_10_signed.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/09 17:53:17 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/10 19:05:19 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static inline void	set_res_str_len(t_conversion_input *inp,
	int *i, int64_t *value)
{
	*i = 0;
	*value = inp->int_value;
	if (*value < 0)
		*i += 1;
	if (value == 0)
		*i = 1;
	else
		while (*value != 0)
		{
			*value /= 10;
			*i += 1;
		}
}

static inline void	set_value(t_conversion_result *res, int64_t *value, int *i)
{
	if (*value < 0)
	{
		if (*value < -9223372036854775807LL)
		{
			*value = 922337203685477580LL;
			res->str[*i] = '8';
			i--;
		}
		else
			*value = -*value;
	}
}

t_bool				convert_int_base_10_signed(t_conversion_result *res,
	t_conversion_input *inp)
{
	int64_t		value;
	int			i;

	set_res_str_len(inp, &i, &value);
	res->len = i;
	res->str = TAKE_MULTI(char, i + 1, "convert_int_base_10_signed");
	if (res->str == NULL)
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