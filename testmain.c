/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testmain.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/18 20:53:19 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/24 20:56:38 by jandre-d      ########   odam.nl         */
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


int w_char_byte_count(wchar_t wchar)
{
	if (wchar <= 0x7F)
		return (1);
	if (wchar <= 0x7FF)
		return (2);
	if (wchar <= 0xFFFF)
		return (3);
	return (4);
}

char *w_char_to_writable_string(wchar_t wc, int *size)
{
	char *to_return;
	int i;

	*size = w_char_byte_count(wc);
	to_return = ft_strnew(*size);
	if (*size == 1)
		to_return[0] = wc;
	if (*size == 2)
	{
		to_return[1] = (char)(0b00000000000000000000000010000000 |
						(wc & 0b00000000000000000000000000111111));
		to_return[0] = (char)(0b00000000000000000000000011000000 |
				 ((wc >> 6) & 0b00000000000000000000000000011111));
	}
	if (*size == 3)
	{
		to_return[2] = (char)(0x80 | (wc & 0x3f));
		to_return[1] = (char)(0x80 | ((wc >> 6) & 0x3f));
		to_return[0] = (char)(0xe0 | ((wc >> 12) & 0b00000000000000000000000000001111));
	}
	if (*size == 4)
	{
		to_return[3] = (char)(0b00000000000000000000000010000000 |
						(wc & 0b00000000000000000000000000111111));
		to_return[2] = (char)(0b00000000000000000000000010000000 |
				 ((wc >> 6) & 0b00000000000000000000000000111111));
		to_return[1] = (char)(0b00000000000000000000000010000000 |
				((wc >> 12) & 0b00000000000000000000000000111111));
		to_return[0] = (char)(0b00000000000000000000000011110000 |
				((wc >> 12) & 0b00000000000000000000000000000111));
	}

	char str0 = to_return[0];
	char str1 = to_return[1];
	char str2 = to_return[2];
	char str3 = to_return[3];

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

void test()
{
	int x;
	char *hallo = w_char_to_writable_string(L'米', &x);

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

int main()
{
	test();
	int x;
	printf("%s",pf_itoa_base(L'米', 2, &x, true));
	printf("%d", w_char_byte_count((wchar_t)L'米'));

	return (0);
}