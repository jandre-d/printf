/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/06 10:46:48 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/14 18:37:39 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "stdint.h"
#include "ft_printf.h"

static int32_t	len(int32_t value, int32_t base)
{
	int32_t	i;

	if (value == 0)
		return (1);
	i = 0;
	while (value > 0)
	{
		value /= base;
		i++;
	}
	return (i);
}

char			*ft_itoa_base(int32_t value, int32_t base)
{
	char	*to_return;
	char	*character_set;
	int32_t	copy;
	int32_t	i;
	bool	is_negative;

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

#include <stdio.h>

int		main(int ac, char **av)
{
	if (ac == 3)
		printf("%s", ft_itoa_base(ft_atoi(av[1]), ft_atoi(av[2])));
	return (0);
}