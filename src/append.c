/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   append.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/18 16:47:59 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/29 13:59:52 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pf_printf.h"

bool	pf_append_to_c_out(t_conversion_out *c_out, char *str, int32_t len)
{
	char	*new_str;

	new_str = TAKE_MULTI(char, c_out->len + len + 1, "pf_append_to_c_out");
	if (new_str == NULL)
		return (false);
	pf_memcpy(new_str, c_out->str, c_out->len);
	pf_memcpy(new_str + c_out->len, str, len);
	c_out->len += len;
	GIVE(c_out->str, "pf_append_to_c_out");
	c_out->str = new_str;
	return (true);
}

bool	pf_append(t_pf_output *output, char *str, size_t str_len,
	bool free_str)
{
	char	*new_output_str;
	size_t	temp_size;

	if (output->str_useage + str_len > output->str_size - 1)
	{
		temp_size = output->str_useage + str_len + 50;
		new_output_str = TAKE_MULTI(char, temp_size, "pf_append");
		if (new_output_str == NULL)
			return (false);
		pf_memcpy(new_output_str, output->str, output->str_useage);
		pf_memcpy(new_output_str + output->str_useage, str, str_len);
		GIVE(output->str, "pf_append");
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
		GIVE(str, "pf_append");
	return (true);
}
