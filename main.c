/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/07 13:06:15 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/07 13:08:23 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
diouxX  The int (or appropriate variant) argument is converted to signed
		decimal (d and i), unsigned octal (o), unsigned decimal (u), or
		unsigned hexadecimal (x and X) notation.  The letters ``abcdef''
		are used for x conversions; the letters ``ABCDEF'' are used for X
		conversions.  The precision, if any, gives the minimum number of
		digits that must appear; if the converted value requires fewer
		digits, it is padded on the left with zeros.

C       Treated as c with the l (ell) modifier.

c       The int argument is converted to an unsigned char, and the
		resulting character is written.

		If the l (ell) modifier is used, the wint_t argument shall be
		converted to a wchar_t, and the (potentially multi-byte) sequence
		representing the single wide character is written, including any
		shift sequences.  If a shift sequence is used, the shift state is
		also restored to the original state after the character.

S       Treated as s with the l (ell) modifier.

s       The char * argument is expected to be a pointer to an array of
		character type (pointer to a string).  Characters from the array
		are written up to (but not including) a terminating NUL charac-
		ter; if a precision is specified, no more than the number speci-
		fied are written.  If a precision is given, no null character
		need be present; if the precision is not specified, or is greater
		than the size of the array, the array must contain a terminating
		NUL character.

		If the l (ell) modifier is used, the wchar_t * argument is
		expected to be a pointer to an array of wide characters (pointer
		to a wide string).  For each wide character in the string, the
		(potentially multi-byte) sequence representing the wide character
		is written, including any shift sequences.  If any shift sequence
		is used, the shift state is also restored to the original state
		after the string.  Wide characters from the array are written up
		to (but not including) a terminating wide NUL character; if a
		precision is specified, no more than the number of bytes speci-
		fied are written (including shift sequences).  Partial characters
		are never written.  If a precision is given, no null character
		need be present; if the precision is not specified, or is greater
		than the number of bytes required to render the multibyte repre-
		sentation of the string, the array must contain a terminating
		wide NUL character.

p       The void * pointer argument is printed in hexadecimal (as if by
		`%#x' or `%#lx').
*/
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	printf("");
	return (0);
}