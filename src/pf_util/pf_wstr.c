/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_wstr.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 13:56:47 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/25 13:57:36 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pf_printf.h"

static inline int	wstr_size(int *wstr)
{
	int i;
	int size;

	i = 0;
	size = 0;
	while (wstr[i])
	{
		size += wchar_byte_count(wstr[i]);
		i++;
	}
	return (size);
}

static inline int	wstr_len(int *wstr)
{
	int i;

	i = 0;
	while (wstr[i])
		i++;
	return (i);
}

char				*pf_wstr_to_str(int *wstr, int *size)
{
	char	*str;
	int		i;
	int		add_size;
	char	*add;

	str = ft_strnew(wstr_size(wstr));
	i = 0;
	while (wstr[i])
	{
		add = pf_wchar_to_str(wstr[i], &add_size);
		pf_memcpy(str + *size, add, add_size);
		*size += add_size;
		i++;
	}
	return (str);
}
