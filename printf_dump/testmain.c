/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testmain.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/09 17:31:35 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/09 18:41:55 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
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
			*value /= 8;
			*i += 1;
		}
}

void	convert_int_base_8(t_conversion_result *res, t_conversion_data *inp)
{
	char		*character_set;
	uint64_t	value;
	int			i;

	character_set = "0123456789abcdef";
	set_res_str_len(inp, &i, &value);
	res->str = TAKE_MULTI(char, i + 1, "convert_int_base_8");
	if (res->str == NULL)
		return ;
	i--;
	value = inp->int_value;
	while (i >= 0)
	{
		res->str[i] = character_set[value % 8];
		value /= 8;
		i--;
	}
}

int main()
{
	t_conversion_result res;
	t_conversion_data	input;
	
	input.int_value = 7;
	convert_int_base_8(&res, &input);
	printf("%s", res.str);
	return (0);
}