/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_ldtoa.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/13 14:21:35 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/22 17:18:58 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pf_printf.h"

static inline int64_t	round_int_part(long double nbr)
{
	double value;

	value = (int64_t)nbr;
	nbr -= .5;
	value += nbr > value;
	return ((int64_t)value);
}

static inline int64_t	round_decimal_part(double nbr, int32_t precision,
	t_ldbltoa_vars *vars)
{
	double	value;
	int32_t	len_before;
	int32_t	len_after;

	nbr = (nbr - (long double)vars->integer_part) * pf_10_power_n(precision);
	len_before = pf_intlen((int64_t)nbr, 10);
	value = (int64_t)nbr;
	nbr -= .5;
	value += nbr > value;
	len_after = pf_intlen((int64_t)value, 10);
	if (len_before < len_after)
	{
		vars->integer_part += 1;
		value = 0;
		vars->decimal_part_leading_zeros = precision;
	}
	else
	{
		vars->decimal_part_leading_zeros = precision - len_after;
		if (value == 0)
			vars->decimal_part_leading_zeros++;
	}
	return ((int64_t)value);
}

static inline void		to_string(t_ldbltoa_vars *vars)
{
	vars->len--;
	while (vars->decimal_part > 0)
	{
		vars->to_return[vars->len] = vars->decimal_part % 10 + '0';
		vars->decimal_part /= 10;
		vars->len--;
		vars->to_return[vars->len] = (vars->decimal_part_leading_zeros == 0
		&& vars->decimal_part == 0) ? '.' : vars->to_return[vars->len];
		vars->len -= (vars->decimal_part_leading_zeros == 0
		&& vars->decimal_part == 0);
	}
	while (vars->decimal_part_leading_zeros > 0)
	{
		vars->to_return[vars->len] = '0';
		vars->decimal_part_leading_zeros--;
		vars->len--;
		vars->to_return[vars->len] = vars->decimal_part_leading_zeros ==
		0 ? '.' : vars->to_return[vars->len];
		vars->len -= vars->decimal_part_leading_zeros == 0;
	}
	while (vars->len >= 0)
	{
		vars->to_return[vars->len] = vars->integer_part % 10 + '0';
		vars->integer_part /= 10;
		vars->len--;
	}
	if (vars->is_negative)
		vars->to_return[0] = '-';
}

char					*pf_ldtoa(long double nbr, int32_t precision,
	int32_t *len)
{
	t_ldbltoa_vars vars;

	ft_memset((void *)&vars, 0, sizeof(t_ldbltoa_vars));
	vars.is_negative = nbr < 0 ? true : false;
	nbr = nbr < 0 ? -nbr : nbr;
	if (precision > 0)
	{
		vars.integer_part = (int64_t)nbr;
		vars.decimal_part = round_decimal_part(nbr, precision, &vars);
		vars.len = pf_intlen(vars.integer_part, 10) + 1 + precision +
			vars.is_negative;
	}
	else
	{
		vars.integer_part = round_int_part(nbr);
		vars.len = pf_intlen(vars.integer_part, 10) + vars.is_negative;
	}
	*len = vars.len;
	vars.to_return = TAKE_MULTI(char, vars.len + 1, "pf_ldbltoa");
	if (vars.to_return == NULL)
		return (NULL);
	to_string(&vars);
	return (vars.to_return);
}
