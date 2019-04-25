/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testmain.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/18 20:53:19 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/25 13:55:54 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include "includes/pf_printf.h"
#include <stdio.h>
#include <limits.h>
#include <stdio.h>
#include <unistd.h>
#include <wchar.h>
#include "libft/libft.h"
#include <stdint.h>
#include <stdlib.h>


//https://stackoverflow.com/questions/32936646/getting-the-string-length-on-utf-8-in-c
//https://stackoverflow.com/questions/7108241/how-to-know-the-number-of-characters-in-utf8-string

//https://stackoverflow.com/questions/9356169/utf-8-continuation-bytes
//https://www.branah.com/unicode-converter
//https://www.utf8-chartable.de/unicode-utf8-table.pl
//https://mothereff.in/byte-counter


static inline int	wchar_byte_count(int wchar)
{
	if (wchar <= 0x7F)
		return (1);
	if (wchar <= 0x7FF)
		return (2);
	if (wchar <= 0xFFFF)
		return (3);
	return (4);
}

char				*pf_wchar_to_str(int wchar, int *size)
{
	char *to_return;

	*size = wchar_byte_count(wchar);
	to_return = ft_strnew(*size);
	if (*size == 1)
		to_return[0] = wchar;
	if (*size == 2)
	{
		to_return[1] = (char)(0x80 | (wchar & 0x3F));
		to_return[0] = (char)(0xC0 | ((wchar >> 6) & 0x1F));
	}
	if (*size == 3)
	{
		to_return[2] = (char)(0x80 | (wchar & 0x3F));
		to_return[1] = (char)(0x80 | ((wchar >> 6) & 0x3F));
		to_return[0] = (char)(0xE0 | ((wchar >> 12) & 0xF));
	}
	if (*size == 4)
	{
		to_return[3] = (char)(0x80 | (wchar & 0x3F));
		to_return[2] = (char)(0x80 | ((wchar >> 6) & 0x3F));
		to_return[1] = (char)(0x80 | ((wchar >> 12) & 0x3F));
		to_return[0] = (char)(0xF0 | ((wchar >> 12) & 0x7));
	}
	return (to_return);
}

static inline int	wstr_size(int *wstr)
{
	int i;
	int size;

	i = 0;
	size = 0;
	while (wstr[i])
	{
		size += wchar_byte_count(wstr[i]);
		i++;
	}
	return (size);
}

static inline int	wstr_len(int *wstr)
{
	int i;

	i = 0;
	while (wstr[i])
		i++;
	return (i);
}

char				*pf_wstr_to_str(int *wstr, int *size)
{
	char	*str;
	int		i;
	int		add_size;
	char	*add;

	str = ft_strnew(wstr_size(wstr));
	i = 0;
	while (wstr[i])
	{
		add = pf_wchar_to_str(wstr[i], &add_size);
		pf_memcpy(str + *size, add, add_size);
		*size += add_size;
		i++;
	}
	return (str);
}


void test()
{
	//int x;
	//char *hallo = wchar_to_writable_string(L'米', &x);

	// char a[4];
	//米 = ç±³

	//		target:
	// 			a[0] = 0Xe7; //11100111 
	// 			a[1] = 0X8c; //10001100
	// 			a[2] = 0Xab; //10101011
	// 			a[3] = 0;

	/* i get:
		input = 111110001110011


3f = 111111   = 63
e0 = 11100000 = 224
80 = 10000000 = 128


	// a[0] = 0Xe7; //11100111 
	// a[1] = 0Xb1; //10110001
	// a[2] = 0Xb3; //10110011
	// a[3] = 0;

	*/
}


void print_one()
{
	int b = 0;
	char *str = pf_wstr_to_str(L"力米緑力米力米力", &b);

	ft_putstr(str);
}



int main()
{
	print_one();

	// test();
	// int x;
	// printf("%s",pf_itoa_base(L'米', 2, &x, true));
	// printf("%d", w_char_byte_count((wchar_t)L'米'));

	return (0);
}