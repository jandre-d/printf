/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_str_append.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/14 15:03:11 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/14 15:44:36 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libpf.h"

char	*pf_str_append(char *str, char *add)
{
	char	*to_return;
	int32_t len_str;
	int32_t len_add;

	len_str = ft_strlen(str);
	len_add = ft_strlen(add);
	to_return = TAKE_MULTI(char, len_str + len_add + 1, "pf_str_append");
	if (to_return == NULL)
		return (NULL);
	to_return[len_str + len_add] = '\0';
	ft_memcpy((void *)to_return, (const void *)str, len_str);
	ft_memcpy((void *)to_return + len_str, (const void *)add, len_add);
	GIVE(str, "pf_str_append");
	return (to_return);
}