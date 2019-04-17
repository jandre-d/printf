/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_append_right.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 18:39:55 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/17 18:40:33 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libpf.h"

/*
**if (output->str_useage + str_len > output->str_size - 1) //-1 = keep '\0' norm
*/
bool append_right(t_output *output, char *str, size_t str_len, bool free_str)
{
	char *new_output_str;
	size_t temp_size;
	
	if (output->str_useage + str_len > output->str_size - 1)
	{
		temp_size = output->str_useage + str_len + 50;
		new_output_str = TAKE_MULTI(char, temp_size, "append_right");
		if (new_output_str == NULL)
			return (false);
		pf_memcpy(new_output_str, output->str, output->str_useage);
		pf_memcpy(new_output_str + output->str_useage, str, str_len);
		GIVE(output->str, "append_right");
		output->str_size = temp_size;
		output->str_useage = temp_size - 50;
		output->str = new_output_str;
	}
	else
	{
		pf_memcpy(output->str + output->str_useage, str, str_len);
		output->str_useage += str_len;
	}
	if (free_str)
		GIVE(str, "append_right");
	return (true);
}