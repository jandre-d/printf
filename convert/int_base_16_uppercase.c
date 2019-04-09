/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   int_base_16_uppercase.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/09 18:03:43 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/09 20:26:27 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static inline void set_res_str_len(t_conversion_data *inp, int *i, uint64_t *value)
{
	*i = 0;
	*value = inp->int_value;
	if (value == 0)
		*i = 1;
	else
		while (*value > 0)
		{
			*value /= 16;
			*i += 1;
		}
}

t_bool	convert_int_base_16_uppercase(t_conversion_result *res, t_conversion_data *inp)
{
	char		*character_set;
	uint64_t	value;
	int			i;

	character_set = "0123456789ABCDEF";
	set_res_str_len(inp, &i, &value);
	res->len = i;
	res->str = TAKE_MULTI(char, i + 1, "convert_int_base_16_uppercase");
	if (res->str == NULL)
		return (FALSE);
	i--;
	value = inp->int_value;
	while (i >= 0)
	{
		res->str[i] = character_set[value % 16];
		value /= 16;
		i--;
	}
	return (TRUE);
}