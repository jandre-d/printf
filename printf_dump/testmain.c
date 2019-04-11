/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testmain.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/09 17:31:35 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/10 23:07:42 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../ft_printf.h"
#include <float.h>

static inline int64_t round_f(int64_t *integer_part, double x)
{
	double y;

	y = (int64_t)x;
	x -= .5;
	y += x > y;
	return ((int64_t)y);
}

static inline int	set_res_str_len(t_conversion_input *inp,
	int *i, int64_t *value)
{
	*i = 0;
	*value = inp->int_value;
	if (*value < 0)
		*i += 1;
	if (value == 0)
		*i = 1;
	else
		while (*value != 0)
		{
			*value /= 10;
			*i += 1;
		}
}

static inline int64_t round_f_overflow(int64_t *integer_part, double x)
{
	double y;

	y = (int64_t)x;
	x -= .5;
	y += x > y;
	return ((int64_t)y);
}

static inline int	n_pow_10(int n)
{
	if (n == 0)
		return (1);
	if (n == 1)
		return (10);
	return (10 * n_pow_10(n - 1));
}

t_bool convert_double(t_conversion_result *res, t_conversion_input *inp)
{
	int64_t	integer_part;
	int64_t decimal_part;
	int		leading_zeros_in_decimal_part;
	t_bool 	is_negative;

	leading_zeros_in_decimal_part = 0;
	if (inp->double_float_value < 0)
	{
		is_negative = 1;
		inp->double_float_value = -inp->double_float_value;
	}
	printf("inptut : %f\n", inp->double_float_value);

	if (inp->precision > 0)
	{
		integer_part = (int64_t)inp->double_float_value;
		decimal_part = round_f_overflow(&integer_part, (inp->double_float_value - (double)integer_part) * n_pow_10(inp->precision));
	}
	else
		integer_part = round_f(NULL, inp->double_float_value);

	if (is_negative)
	{
		if (inp->precision > 0)
			printf("result : -%lld.%lld\n", integer_part, decimal_part);
		else
			printf("result : -%lld\n", integer_part);
	}
	else
	{
		if (inp->precision > 0)
			printf("result : %lld.%lld\n", integer_part, decimal_part);
		else
			printf("result : %lld\n", integer_part);
	}
	return (TRUE);
}
//1.999 @ 2
//0.5 @ 0
//0.125 @ 2
//0.008 @ 2
int main()
{
	// t_conversion_result res;
	// t_conversion_input	input;

	// input.double_float_value = 0.008;
	// input.precision = 2;
	// convert_double(&res, &input);
	// printf("printf	 %.2f\n", input.double_float_value);


	printf("%f", __FLT_MIN__);

	__DBL_MAX__; //1.7976931348623157e+308
	__DBL_MIN__; //2.2250738585072014e-308
	__LDBL_MAX__; //1.18973149535723176502e+4932L
	__INT64_MAX__; //9223372036854775807LL
	return (0);
}