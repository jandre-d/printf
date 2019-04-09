/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   int_base_16_lowercase.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/09 16:36:31 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/09 18:13:15 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	convert_int_base_16(t_conversion_result *res, t_conversion_data *inp)
{
	char					*character_set;
	unsigned long long int	value;
	int						i;

	character_set = "0123456789abcdef";
	i = -1;
	value = inp->int_value;
	if (value == 0)
		i = 0;
	else
		while (value > 0)
		{
			value /= 16;
			i++;
		}
	value = inp->int_value;
	res->str = TAKE_MULTI(char, i + 2, "ft_itoa_base");
	if (res->str == NULL)
		return ;
	while (i >= 0)
	{
		res->str[i] = character_set[value % 16];
		value /= 16;
		i--;
	}
}
