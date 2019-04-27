/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testmain.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/18 20:53:19 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/27 20:46:33 by jandre-d      ########   odam.nl         */
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
/*
         `#'          For o conversions, the precision of the num-
                      ber is increased to force the first character of the
                      output string to a zero.

					  For x and X conversions, a non-zero result has the string `0x' (or `0X' for X con-
                      versions) prepended to it.

					  For f conversions, the result will always contain a decimal
                      point, even if no digits follow it (normally, a decimal
                      point appears in the results of those conversions only
                      if a digit follows).

         `0' (zero)   For all conversions except n, the converted value is padded on
                      the left with zeros rather than blanks.  If a precision is given with a
                      numeric conversion (d, i, o, u, i, x, and X), the 0 flag is ignored.

         `-'          the converted value is padded on the right
                      with blanks, rather than on the left with blanks or
                      zeros.
					  - overrides a 0 if both are given.

         ` ' (space)  A blank should be left before a positive number produced
                      by a signed conversion and d f i

         `+'          A sign must always be placed before a number produced by
                      a signed conversion. d f i
					  + overrides a space

*/
// #0-+ and space
int main()
{
	//short x = (short)(__SHRT_MAX__ *2  +1);
	ft_printf("%.0j\n", "hello");
	//printf("%s %C %d %p %x %% %ls", "bonjour ", L'該', 42, &free, 42, L"لحم خنزير");

	// int x = 22;
	//    printf("\"%8.0u\"\n", x);
	// ft_printf("\"%8.0u\"\n", x);

	//    printf("\"%08.0u\"\n", x);
	// ft_printf("\"%08.0u\"\n", x);

	//    printf("\"%#20x\"\n", x);
	// ft_printf("\"%#20x\"\n", x);

	// x = 22;
	//     printf("\"%10.15x\"\n", x);
	// ft_printf("\"%10.15x\"\n", x);

	return (0);
}