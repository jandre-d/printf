/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_instruction.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 11:38:33 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/22 18:50:02 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pf_printf.h"

// /*
// ** delete ?
// */
// static void overwrite_flags(t_conversion_in *c_in)
// {
// 	char c_ty;

// 	c_ty = c_in->conversion_type;
// 	if (c_ty == 'c' || c_ty == 'd' || c_ty == 'i' || c_ty == 'n' ||
// 	c_ty == 'p' || c_ty == 's' || c_ty == 'u')
// 		c_in->flag_hash = false;
// 	if (c_ty == 'n' || c_in->flag_min || (c_in->precision > 0 && (c_ty == 'd' ||
// 	c_ty == 'i' || c_ty == 'o' || c_ty == 'u' || c_ty == 'i' || c_ty == 'x')))
// 		c_in->flag_0 = false;
// 	if (c_ty == 'n')
// 		c_in->flag_min = false;
// 	if (((c_ty == 'd' || c_ty == 'f') == false && c_in->flag_space) ||
// 	c_in->flag_plus)
// 		c_in->flag_space = false;
// }

/*
** b: boolean --- bonus ?
** csp diouxX f %%
*/
static inline bool set_conversion(char **str, t_conversion_in *c_in)
{
	if (**str == 'C' ||
		**str == 'c' ||
		**str == 'S' ||
		**str == 's' ||
		**str == 'p' ||
		**str == 'D' ||
		**str == 'd' ||
		**str == 'i' ||
		**str == 'O' ||
		**str == 'o' ||
		**str == 'U' ||
		**str == 'u' ||
		**str == 'X' ||
		**str == 'x' ||
		**str == 'f' ||
		**str == '%')
		{
			c_in->conversion_type = **str;
			return (true);
		}
		return (false);
}

/*
** ll hh
*/
static inline uint8_t set_flag_double_char(char **str, t_conversion_in *c_in)
{
	if (**str == 'l' && c_in->flag_l)
	{
		if (*(*str -1) == 'l')
		{
			c_in->flag_ll = true;
			c_in->flag_l = false;
			return (true);
		}
		return (false);
	}
	if (**str == 'h' && c_in->flag_h)
	{
		if (*(*str -1) == 'h')
		{
			c_in->flag_hh = true;
			c_in->flag_h = false;
			return (true);
		}
		return (false);
	}
	return (42);
}

static inline bool set_nbr_param(char **str, t_conversion_in *c_in)
{
	bool	is_precision;
	int32_t i;

	i = 0;
	is_precision = **str == '.';
	if (is_precision)
		*str += 1;
	while (**str && **str >= '0' && **str <= '9')
	{
		i *= 10;
		i += **str - '0';
		*str += 1;
	}
	if (is_precision)
		c_in->precision = i;
	else
		c_in->padding = i;
	*str -= 1;
	return (true);
}

/*
** # 0 - + space h l L
*/
static inline bool set_flag(char **str, t_conversion_in *c_in)
{
	uint8_t double_char_flag_result;

	double_char_flag_result = set_flag_double_char(str, c_in);
	if (double_char_flag_result == 42)
		return (
			(**str == '#' && (c_in->flag_hash = true)) ||
			(**str == '0' && (c_in->flag_0 = true)) ||
			(**str == '-' && (c_in->flag_min = true)) ||
			(**str == '+' && (c_in->flag_plus = true)) ||
			(**str == ' ' && (c_in->flag_space = true)) ||
			(**str == 'h' && (c_in->flag_h = true)) ||
			(**str == 'l' && (c_in->flag_l = true)) ||
			(**str == 'L' && (c_in->flag_L = true)) ||
			(**str == '.' && set_nbr_param(str, c_in)) ||
			((**str >= '0' && **str <= '9') && set_nbr_param(str, c_in)));
	else
		return (double_char_flag_result);
}

/*
** the first character in str should be a '%'
*/
bool read_instruction(char **str, t_conversion_in *c_in)
{
	if (**str != '\0')
	{
		while (true)
		{
			*str += 1;
			if (**str == '\0')
				return (false);
			if (set_flag(str, c_in))
				continue;
			else if (set_conversion(str, c_in))
				return (true);
			else
				return (false);
		}
	}
	return (false);
}