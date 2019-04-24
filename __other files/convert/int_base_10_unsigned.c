/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   int_base_10_unsigned.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/09 18:49:44 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/17 20:31:04 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static inline void set_res_str_len(t_conversion_in *inp,
	int *i, uint64_t *value)
{
	*i = 0;
	*value = inp->int_value;
	if (value == 0)
		*i = 1;
	else
		while (*value > 0)
		{
			*value /= 10;
			*i += 1;
		}
}

t_bool	convert_int_base_10_unsigned(t_conversion_out *res,
	t_conversion_in *inp)
{
	uint64_t	value;
	int			i;

	set_res_str_len(inp, &i, &value);
	res->len = i;
	res->str = TAKE_MULTI(char, i + 1, "convert_int_base_10_unsigned");
	if (res->str == NULL)
		return (FALSE);
	i--;
	value = inp->int_value;
	while (i >= 0)
	{
		res->str[i] = value % 10 + '0';
		value /= 10;
		i--;
	}
	return (TRUE);
}