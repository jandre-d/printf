/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   atoi_base.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/05 15:57:56 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/05 18:44:01 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "stdint.h"
#include "libft/libft.h"

int value_base10(int c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	return (c - 'A' + 10);
}

int to_base10(char *str, int base)
{
	int to_return;
	int i;
	int power;

	power = 1;
	i = ft_strlen(str);
	while (i >= 0)
	{
		to_return += value_base10(str[i]) * power;
		power = power * base;
		i--;
	}
	return (to_return);
}





char get_char(int c)
{
	 if (c >= 0 && c <= 9)
		return (c + '0');
	return (c + 'A' - 10);
}

int get_len(int nbr, int base)
{
	int to_return;

	to_return = 0;
	while (nbr > base)
	{
		nbr /= base;
		to_return++;
	}
	return (to_return);
}

char *itoa_base(int nbr, int base)
{
	int i;
	char *to_return;
	
	i = get_len(nbr, base);
	to_return = ft_strnew(i);
	while (nbr > base)
	{
		to_return[i] = get_char(nbr % base);
		nbr /= base;
		i--;
	}
	to_return[i] = get_char(nbr % base);
	return (to_return);
}

int main()
{
	ft_putstr(itoa_base(242, 8));
	return (0);
}