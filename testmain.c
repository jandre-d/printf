/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testmain.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/18 20:53:19 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/22 18:45:42 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main()
{
	//ft_printf("\"% Zoooo\"\n");
	// printf("\"%s\"\n", "42");
	// printf("\"%S\"\n", "42");
	printf("%u\n", 42);
	printf("%U\n", 42);
	ft_printf("%u\n", 42);
	ft_printf("%U\n", 42);

	return (0);
}