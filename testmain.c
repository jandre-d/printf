/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testmain.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/18 20:53:19 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/25 17:31:36 by jandre-d      ########   odam.nl         */
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

         `0' (zero)   For (s, c, p) conversions the converted value is padded on the left with zeros rather
                      than blanks.

         `-'          the converted value is padded on the right
                      with blanks, rather than on the left with blanks or
                      zeros.
					  - overrides a 0 if both are given.

         ` ' (space)  A blank should be left before a positive number produced
                      by a signed conversion diouxX and f

         `+'          A sign must always be placed before a number produced by
                      a signed conversion.
					  + overrides a space

*/
// #0-+ and space
int main()
{
	double x = 23245;

	//printf("%#.8lf", x);
	printf("%-20s", "hello");


	return (0);
}