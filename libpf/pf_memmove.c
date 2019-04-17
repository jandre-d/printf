/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 10:48:56 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/17 10:50:49 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libpf.h"

void	*pf_memmove(char *dst, char *src, size_t len)
{
	return (ft_memmove((void *)dst, (const void *)src, len));
}