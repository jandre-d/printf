/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   padding.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: twoerdem <twoerdem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/10 17:22:47 by twoerdem       #+#    #+#                */
/*   Updated: 2019/04/26 18:16:44 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libpf/libpf.h"
#include <stdio.h>
#include <stdlib.h>

void	zero_padding(t_conversion_out *res, t_conversion_in *inp)
{
	if (inp->flag_plus == true)
	{
		if (res->is_negative == true)
		{
			ft_putchar('-');
			res->str++;
		}
		else
		{
			ft_putchar('+');
			inp->padding--;
		}
	}
	if (inp->conversion_type != 'i' && inp->conversion_type != 'd' &&\
	inp->flag_hash == true)
	{
		if (inp->conversion_type == 'o')
		{
			ft_putchar('0');
			inp->padding--;
		}
		if (inp->conversion_type == 'x')
		{
			ft_putstr("0x");
			inp->padding -= 2;
		}
		if (inp->conversion_type == 'X')
		{
			ft_putstr("0X");
			inp->padding -= 2;
		}
	}
	while (inp->padding > res->len)
	{
		ft_putchar('0');
		inp->padding--;
	}
	ft_putstr(res->str);
}

void	padding(t_conversion_out *res, t_conversion_in *inp)
{
	if (inp->flag_0 == true)
		zero_padding(res, inp);
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

	t_conversion_out	*res;
	t_conversion_in		*inp;

	res = (t_conversion_out *)malloc(sizeof(t_conversion_out *));
	inp = (t_conversion_in *)malloc(sizeof(t_conversion_in *));
	inp->padding = 5;
	res->str = "FFF";
	res->len = ft_strlen(res->str);
	inp->flag_0 = true;
	inp->conversion_type = 'x';
	inp->flag_hash = false;
	ft_putchar('\'');
	padding(res, inp);
	ft_putchar('\'');
	ft_putchar('\n');
}
