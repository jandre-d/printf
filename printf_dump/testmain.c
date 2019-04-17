/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testmain.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/09 17:31:35 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/17 12:19:40 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../ft_printf.h"
#include "../libpf/libpf.h"
#include <float.h>
#include "../append.c"
#include <stdio.h>

//1.999 @ 2
//0.5 @ 0
//0.125 @ 2
//0.008 @ 2
int main()
{
	t_conversion_result res;
	t_conversion_input	input;

	t_output x;
	x.str = ft_strnew(2);
	x.str_size = 2;
	x.str_useage = 2;
	x.str[0] = 'x';
	x.str[1] = 'v';
	
	printf("\" d\"");

	// printf("size = %zu, useage = %zu, str = \"%s\"\n", x.str_size, x.str_useage, x.str);

	// append_left(&x, "hoiiii", 3, false);
	
	// printf("size = %zu, useage = %zu, str = \"%s\"\n", x.str_size, x.str_useage, x.str);
	
	// append_right(&x, " ja", 3, false);

	// printf("size = %zu, useage = %zu, str = \"%s\"\n", x.str_size, x.str_useage, x.str);
	// int i = 0;
	// while (i < 70)
	// {
	// 	printf("%d result \33[0;100m : \"%s\"\n", i, pf_ldtoa(3957667383453463638.35545, 5));
	// 	i++;
	// }
	return (0);
}