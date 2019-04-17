/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 11:05:25 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/17 11:07:38 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libpf.h"

void *pf_memcpy(char *dst, char *src, size_t n)
{
	return (ft_memcpy((void *)dst, (const void *)src, n));
}