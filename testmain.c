/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testmain.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/18 20:53:19 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/25 14:36:24 by jandre-d      ########   odam.nl         */
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


int main()
{
	// int x;
	// printf("%s",pf_itoa_base(L'米', 2, &x, true));
	// printf("%d", w_char_byte_count((wchar_t)L'米'));
	char c;
	ft_printf("%ld\n", (long)INT_MAX + 1);
	printf("%ld", (long)INT_MAX + 1);
	return (0);
}