/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   padding.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: twoerdem <twoerdem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/10 17:22:47 by twoerdem       #+#    #+#                */
/*   Updated: 2019/04/16 12:03:56 by twoerdem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

void	padding(t_conversion_result *res, t_conversion_input *inp)
{
	int		i;
	char	*new;
	int 	sign;
	
	i = 0;
	sign = 0;
	new = ft_strnew(inp->padding);
	new[inp->padding] = '\0';
	while (i < inp->padding)
	{
		if (inp->flag_0 == 1)
			new[i] = '0';
		else
			new[i] = ' ';
		i++;
	}
	i = 0;
	if (inp->flag_plus == 1 && res->str[0] != '-' && (inp->flag_min == 1 || inp->flag_0 == 1))
	{
		new[i] = '+';
		sign = 1;
	}
	else if (inp->flag_plus == 1 && res->str[0] != '-' && inp->flag_min == 0)
	{
		new[inp->padding - res->len - 1] = '+';
		sign = 1;
	}
	while (i < res->len)
	{
		if (inp->flag_min == 1 && inp->flag_0 == 0)
			new[i + sign] = res->str[i];
		else
			new[inp->padding - res->len + i] = res->str[i];
		i++;
	}
	if (res->str[0] == '-' && inp->flag_0 == 1)
	{
		new[inp->padding - res->len] = '0';
		new[0] = '-';
	}
	res->str = new;
}

int		main(void)
{
	printf("'%5s'\n", "H");
	printf("'%-5s'\n\n", "H");

	printf("'%5d'\n", -10);
	printf("'%-5d'\n", -10);
	printf("'%05d'\n", -10);
	printf("'%+5d'\n", -10);
	printf("'%-+5d'\n\n", -10);
	
	printf("'%5d'\n", 10);
	printf("'%-5d'\n", 10);
	printf("'%05d'\n", 10);
	printf("'%+05d'\n", 10);
	printf("'%-+5d'\n\n", 10);

	printf("'%5X'\n", 15);
	printf("'%-5X'\n", 15);
	printf("'%05X'\n\n", 15);
	
	t_conversion_result	*res;
	t_conversion_input	*inp;

	res = (t_conversion_result *)malloc(sizeof(t_conversion_result *));
	inp = (t_conversion_input *)malloc(sizeof(t_conversion_input *));
	inp->padding = 50;
	res->str = "HELLO";
	res->len = ft_strlen(res->str);
	padding(res, inp);
	printf("'%s'\n", res->str);
	inp->flag_min = 1;
	res->str = "HELLO";
	padding(res, inp);
	printf("'%s'\n", res->str);
}
