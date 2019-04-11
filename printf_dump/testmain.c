/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testmain.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/09 17:31:35 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/11 15:36:15 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../ft_printf.h"
#include <float.h>

static inline int64_t round_f(double x)
{
	double y;

	y = (int64_t)x;
	x -= .5;
	y += x > y;
	return ((int64_t)y);
}

static inline int64_t	int_len(int64_t value)
{
	int64_t to_return;

	to_return = 0;
	if (value < 0)
		to_return += 1;
	if (value == 0)
		to_return = 1;
	else
		while (value != 0)
		{
			value /= 10;
			to_return += 1;
		}
	return (to_return);
}

static inline int64_t round_f_overflow(int64_t *integer_part, double x)
{
	double y;
	int32_t len_a;

	y = (int64_t)x;
	len_a = int_len(y);
	x -= .5;
	y += x > y;
	if (len_a < int_len(y))
	{
		*integer_part += 1;
		y = 0;
	}
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
	int32_t	decimal_part_leading_zeros;
	t_bool 	is_negative;

	is_negative = 0;
	if (inp->double_float_value < 0)
	{
		is_negative = 1;
		inp->double_float_value = -inp->double_float_value;
	}
	if (inp->precision > 0)
	{
		integer_part = (int64_t)inp->double_float_value;
		decimal_part = round_f_overflow(&integer_part,
(inp->double_float_value - (double)integer_part) * n_pow_10(inp->precision));
	}
	else
		integer_part = round_f(inp->double_float_value);
	decimal_part_leading_zeros = inp->precision - int_len(decimal_part);

	printf("result : ");

	int i = 0;
	if (is_negative)
		printf("-");
	if (inp->precision > 0)
	{
		printf("%lld.", integer_part);
		while (i < decimal_part_leading_zeros)
		{
			printf("0");
			i++;
		}
		printf("%lld\n", decimal_part);
	}
	else
		printf("%lld\n", integer_part);
	return (TRUE);
}
//1.999 @ 2
//0.5 @ 0
//0.125 @ 2
//0.008 @ 2
int main()
{
	t_conversion_result res;
	t_conversion_input	input;

	input.double_float_value = -1.008;
	input.precision = 2;
	printf("inptut : %f\n", input.double_float_value);
	convert_double(&res, &input);
	printf("printf : %f\n", input.double_float_value);


	// printf("%f", __FLT_MIN__);

	// __DBL_MAX__; //1.7976931348623157e+308
	// __DBL_MIN__; //2.2250738585072014e-308
	// __LDBL_MAX__; //1.18973149535723176502e+4932L
	// __INT64_MAX__; //9223372036854775807LL
	return (0);
}