/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   double.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/09 14:50:43 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/10 16:47:55 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static inline int64_t round_f(double *x)
{
	double y;

	printf("	input x : %.8f\n", *x);
	y = (int64_t)*x;
	*x -= .5f;
	printf("	x : %f\n", *x);
	printf("	y : %f\n", y);
	printf("	x > y ? : %d\n", *x > y);
	y += *x > y;
	printf("	y_new : %f\n", y);
	return ((int64_t)y);
}

static inline int	n_pow_10(int n)
{
	// while (n < 0)
	// {
		
	// }
	if (n == 0)
		return (1);
	if (n == 1)
		return (10);
	return (10 * n_pow_10(n - 1));
}

void convert_double(t_conversion_result *res, t_conversion_input *inp)
{
	int64_t	integer_part;
	int64_t decimal_part;

	printf("inptut : %f\n", inp->double_float_value);

	if (inp->precision > 0)
	{
		integer_part = (int64_t)inp->double_float_value;
		decimal_part = round_f((inp->double_float_value - (double)integer_part) * n_pow_10(inp->precision));
	}
	else
		integer_part = round_f(inp->double_float_value);
	if (decimal_part > 0)
		printf("result : %lld.%lld\n", integer_part, decimal_part);
	else
		printf("result : %lld\n", integer_part);
}

void *convert_double(t_conversion_result *res, t_conversion_input *inp)
{

}