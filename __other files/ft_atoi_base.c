/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/06 10:48:28 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/14 18:37:30 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "stdint.h"
#include "libft/libft.h"

static int32_t	number_strlen(const char *str)
{
	int32_t i;

	i = 0;
	while (str[i] && (\
		(str[i] >= '0' && str[i] <= '9') || \
		(str[i] >= 'a' && str[i] <= 'z') || \
		(str[i] >= 'A' && str[i] <= 'Z')))
		i++;
	return (i);
}

static int32_t	denary_value(const char c, int32_t char_base)
{
	char max;

	if (c >= '0' && c <= '9')
	{
		max = char_base + '0';
		return (c <= max ? c - '0' : -1);
	}
	if (c >= 'a' && c <= 'f')
	{
		max = char_base - 10 + 'a';
		return (c <= max ? c - 'a' + 10 : -1);
	}
	if (c >= 'A' && c <= 'F')
	{
		max = char_base - 10 + 'A';
		return (c <= max ? c - 'A' + 10 : -1);
	}
	return (-1);
}

int32_t			ft_atoi_base(const char *str, int32_t str_base)
{
	int32_t	to_return;
	bool	negative;
	int32_t	power;
	int32_t	add;
	int32_t	i;

	if (str_base < 2 || str_base > 16)
		return (-1);
	to_return = 0;
	negative = *str == '-';
	while (*str && ((*str > 8 && *str < 14) || *str == '-' || *str == '+' || \
	*str == ' '))
		str++;
	i = number_strlen(str) - 1;
	power = 1;
	while (i >= 0)
	{
		add = denary_value(str[i], str_base);
		if (add == -1)
			return (-1);
		to_return += add * power;
		power *= str_base;
		i--;
	}
	return (negative ? -to_return : to_return);
}

#include <stdio.h>

int		main(int ac, char **av)
{
	if (ac == 3)
		printf("%d", ft_atoi_base(av[1], ft_atoi(av[2])));
	return (1);
}