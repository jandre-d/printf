/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 10:48:56 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/18 16:58:15 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libpf.h"

char	*pf_memmove(char *dst, char *src, size_t len)
{
	size_t i;

	if (len == 0)
		return (dst);
	if (src < dst)
	{
		len--;
		while (1)
		{
			*((unsigned char *)dst + len) = *((unsigned char *)src + len);
			if (len == 0)
				break ;
			len--;
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			*((unsigned char *)dst + i) = *((unsigned char *)src + i);
			i++;
		}
	}
	return (dst);
}