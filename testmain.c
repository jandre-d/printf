/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testmain.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/18 20:53:19 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/22 21:33:30 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include "includes/pf_printf.h"
#include <stdio.h>
#include <limits.h>
#include <stdio.h>
#include <unistd.h>
#include <wchar.h>
#include "libft.h"
#include <stdint.h>
#include <stdlib.h>


//https://stackoverflow.com/questions/32936646/getting-the-string-length-on-utf-8-in-c
//https://stackoverflow.com/questions/7108241/how-to-know-the-number-of-characters-in-utf8-string

//https://stackoverflow.com/questions/9356169/utf-8-continuation-bytes
//https://www.branah.com/unicode-converter
//https://www.utf8-chartable.de/unicode-utf8-table.pl
//https://mothereff.in/byte-counter

//useless
int64_t w_strlen_ehm(uint8_t *str)
{
	int64_t i;
	int64_t to_return;

	i = 0;
	to_return = 0;
	// while (str[i])
	// {
	// 	if (str[i] < 0x80 || str[i] > 0xbf)
	// 		to_return++;
	// 	i++;
	// }
	while (str[i])
	{
		if (0b00000010 != (uint8_t)(str[i] >> 6))
			to_return++;
		i++;
	}
	return (to_return);
}

//broken
int w_char_byte_count(wchar_t wchar)
{
	if (wchar >> 31 == 0b00000000000000000000000000000000)
		return (1);
	if (wchar >> 29 == 0b00000000000000000000000000000110)
		return (2);
	if (wchar >> 28 == 0b00000000000000000000000000001110)
		return (3);
	if (wchar >> 27 == 0b00000000000000000000000000011110)
		return (4);
	return (-1);
}


char *w_char_to_writable_string(wchar_t wc, int *size)
{
	char *to_return;
	int i;

	*size = w_char_byte_count(wc);
	to_return = ft_strnew(*size);
	i = 1;
	while (i <= *size)
	{
		if (i == 1)
			to_return[i] = wc & 0b11111111000000000000000000000000;
		if (i == 2)
			to_return[i] = wc & 0b00000000111111110000000000000000;
		if (i == 3)
			to_return[i] = wc & 0b00000000000000001111111100000000;
		if (i == 4)
			to_return[i] = wc & 0b00000000000000000000000011111111;
		i++;
	}
	return (to_return);
}

int w_str_size(wchar_t *wchar,int wchar_count)
{
	int i;
	int size;

	i = 0;
	size = 0;
	while (i < wchar_count)
	{
		size += w_char_byte_count(wchar[i]);
		i++;
	}
	return (size);
}

int wstr_len(wchar_t *wstr)
{
	int i;

	i = 0;
	while (wstr[i] != 0)
		i++;
	return (i);
}

char *w_str_to_writable_string(wchar_t *wchar, int *size)
{
	char	*to_return;
	int		to_return_usage;
	int		i;
	int		char_count;
	char	*wchar_add;
	int		wchar_add_size;
	
	char_count = wstr_len(wchar);
	*size = w_str_size(wchar, char_count);
	to_return = ft_strnew(*size);
	to_return_usage = 0;
	i = 0;
	while (i < char_count)
	{
		wchar_add = w_char_to_writable_string(wchar[i], &wchar_add_size);
		pf_memcpy(to_return + to_return_usage, wchar_add, wchar_add_size);
		free(wchar_add);
		i++;
	}
	return (to_return);
}

//米 = ç±³
/*
** 米 = 0Xe7 0X8c 0Xab
** 米 = 11100111 \
**		10001100 \
**		10101011
*/

void test()
{
	int x;
	char *hallo = w_char_to_writable_string(L'米', &x);

	// char a[4];

	// a[3] = 0;
	// a[0] = 0Xe7; //11100111
	// a[1] = 0X8c; //10001100
	// a[2] = 0Xab; //10101011
	// ft_putstr(a);

	// wchar_t x[2];
	// __darwin_wchar_t a;

	// x[0] = "米";
	// x[1] = "米";
	// printf("%lld", w_strlen_ehm((uint8_t *)x));
}

int main()
{
	test();
	// uint8_t x[7];
	// x[0] = 231;
	// x[1] = 140;
	// x[2] = 171;
	// x[3] = 231;
	// x[4] = 140;
	// x[5] = 171;
	// x[6] = 0;

	//printf("%lld", w_strlen(x));
	//ft_printf("\"% Zoooo\"\n");
	// printf("\"%s\"\n", "42");
	// printf("\"%S\"\n", "42");
	// printf("%u\n", 42);
	// printf("%U\n", 42);
	// ft_printf("%u\n", 42);
	// ft_printf("%U\n", 42);

	return (0);
}