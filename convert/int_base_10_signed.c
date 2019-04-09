/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   int_base_10_signed.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/09 17:53:17 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/09 19:49:57 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

// static inline void set_res_str_len(t_conversion_input *inp, int *i, int64_t *value)
// {
// 	int64_t my_value;

// 	*i = 0;
// 	my_value = inp->int_value;
// 	if (my_value < 0)
// 	{
// 		*i = 1;
// 		my_value = my_value < -9223372036854775807 ?
// 			9223372036854775807 : -my_value;
// 	}
// 	else if (value == 0)
// 		*i = 1;
// 	else
// 		while (*value > 0)
// 		{
// 			*value /= 10;
// 			*i += 1;
// 		}
// }

// t_bool	convert_int_base_10_signed(t_conversion_result *res, t_conversion_input *inp)
// {
// 	char		*character_set;
// 	int64_t	value;
// 	int			i;

// 	set_res_str_len(inp, &i, &value);
// 	res->len = i;
// 	res->str = TAKE_MULTI(char, i + 1, "convert_int_base_10_unsigned");
// 	if (res->str == NULL)
// 		return (FALSE);
// 	i--;
// 	value = inp->int_value;
// 	while (i >= 0)
// 	{
// 		res->str[i] = value % 10 + '0';
// 		value /= 10;
// 		i--;
// 	}
// 	if ((int64_t)inp->int_value < 0)
// 		res->str[i] = '-';
// 	return (TRUE);
// }

static inline void set_res_str_len(t_conversion_input *inp, int *i, int64_t *value)
{
	*i = 0;
	*value = inp->int_value;
	if (*value < 0)
	{
		*i++;
		*value = *value < -9223372036854775807 ?
 			9223372036854775807 : -*value;
	}
	if (value == 0)
		*i = 1;
	else
		while (*value > 0)
		{
			*value /= 10;
			*i += 1;
		}
}

t_bool	convert_int_base_10_signed(t_conversion_result *res, t_conversion_input *inp)
{
	char		*character_set;
	int64_t		value;
	int			i;

	set_res_str_len(inp, &i, &value);
	res->len = i;
	res->str = TAKE_MULTI(char, i + 1, "convert_int_base_10_unsigned");
	if (res->str == NULL)
		return (FALSE);
	i--;
	value = inp->int_value;
	if (value < 0)
	{
		value = value < -9223372036854775807 ?
 			9223372036854775807 : -value;
	}
	while (i >= 0)
	{
		res->str[i] = value % 10 + '0';
		value /= 10;
		i--;
	}
	return (TRUE);
}