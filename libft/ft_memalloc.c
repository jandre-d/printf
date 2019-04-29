/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memalloc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 10:54:03 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/29 16:55:00 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include "stdint.h"

static int8_t	xxpf_uintlen(uint64_t value, uint8_t base)
{
	int8_t to_return;

	to_return = 0;
	if (value == 0)
	{
		to_return += 1;
	}
	else
		while (value != 0)
		{
			value /= base;
			to_return += 1;
		}
	return (to_return);
}


static char			*xxpf_uitoa_base(uint64_t value, int8_t base)
{
	char	*to_return;
	char	*character_set;
	int8_t	i;

	if (base < 2 || base > 16)
		return (NULL);
	character_set = "0123456789ABCDEF";
	i = xxpf_uintlen(value, base);
	to_return = malloc(i + 1);
	if (to_return == NULL)
		return (NULL);
	i--;
	while (i >= 0)
	{
		to_return[i] = character_set[value % base];
		value /= base;
		i--;
	}
	return (to_return);
}

void	*ft_memallocx(size_t size, char *name)
{
	void	*to_return;
	char 	*ja;

	ft_putstr(name);
	ft_putstr("\n MALLOC : ");
	to_return = malloc(size);
	ja = xxpf_uitoa_base((uint64_t)to_return, 16);
	ft_putstr(ja);
	ft_putchar('\n');
	free(ja);
	if (to_return != NULL)
		ft_bzero(to_return, size);
	return (to_return);
}


void	*ft_memalloc(size_t size)
{
	void	*to_return;

	to_return = malloc(size);
	if (to_return != NULL)
		ft_bzero(to_return, size);
	return (to_return);
}
