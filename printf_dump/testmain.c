/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testmain.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/09 17:31:35 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/13 21:49:50 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../ft_printf.h"
#include "../libpf/libpf.h"
#include <float.h>

//1.999 @ 2
//0.5 @ 0
//0.125 @ 2
//0.008 @ 2
int main()
{
	t_conversion_result res;
	t_conversion_input	input;

	// input.double_float_value = 0.0;
	printf("printf : \"%.5f\"\n", 3957667383453463638.35545);

	printf("result : \"%s\"\n", pf_ldtoa(3957667383453463638.35545, 5));

	// printf("%f", __FLT_MIN__);

	// __DBL_MAX__; //1.7976931348623157e+308
	// __DBL_MIN__; //2.2250738585072014e-308
	// __LDBL_MAX__; //1.18973149535723176502e+4932L
	// __INT64_MAX__; //9223372036854775807LL
	return (0);
}