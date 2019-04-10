/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   int_base_8.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/09 16:31:19 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/10 13:25:27 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static inline void set_res_str_len(t_conversion_input *inp, int *i, uint64_t *value)
{
	*i = 0;
	*value = inp->int_value;
	if (value == 0)
		*i = 1;
	else
		while (*value > 0)
		{
			*value /= 8;
			*i += 1;
		}
}

t_bool	convert_int_base_8(t_conversion_result *res, t_conversion_input *inp)
{
	char		*character_set;
	uint64_t	value;
	int			i;

	character_set = "01234567";
	set_res_str_len(inp, &i, &value);
	res->len = i;
	res->str = TAKE_MULTI(char, i + 1, "convert_int_base_8");
	if (res->str == NULL)
		return (FALSE);
	i--;
	value = inp->int_value;
	while (i >= 0)
	{
		res->str[i] = character_set[value % 8];
		value /= 8;
		i--;
	}
	return (TRUE);
}