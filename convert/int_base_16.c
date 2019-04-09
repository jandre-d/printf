/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   int_base_16.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/09 16:36:31 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/09 16:37:47 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	len(int value)
{
	int	i;

	if (value == 0)
		return (1);
	i = 0;
	while (value > 0)
	{
		value /= 16;
		i++;
	}
	return (i);
}

static char			*ft_itoa_base(int value, int base)
{
	char	*to_return;
	char	*character_set;
	int	copy;
	int	i;
	int	is_negative;

	if (base < 2 || base > 16)
		return (NULL);
	character_set = "0123456789ABCDEF";
	is_negative = value < 0 && base == 10;
	value = is_negative ? -value : value;
	i = len(value, base);
	to_return = TAKE_MULTI(char, i + 1 + is_negative, "ft_itoa_base");
	if (to_return == NULL)
		return (NULL);
	i--;
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

void *convert_int_base_16(t_conversion_result *res, t_conversion_options *inp)
{
	
}