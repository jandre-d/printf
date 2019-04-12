/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testmain.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/09 17:31:35 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/12 13:36:30 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../ft_printf.h"
#include <float.h>

#define blalal(baseeeee) {\
	char		*character_set; \
	uint64_t	value;\
	int			i;\
	character_set = "01234567";\
	set_res_str_len(inp, &i, &value);\
	res->len = i;\
	res->str = TAKE_MULTI(char, i + 1, "convert_int_base_8");\
	if (res->str == NULL)\
		return (FALSE);\
	i--;\
	value = inp->int_value;\
	while (i >= 0)\
	{\
		res->str[i] = character_set[value % baseeeee];\
		value /= baseeeee;\
		i--;\
	}\
	return (TRUE);\
}

static inline void set_res_str_len(t_conversion_input *inp,
	int *i, uint64_t *value)
{
	*i = 0;
	*value = inp->int_value;
	if (value == 0)
		*i = 1;
	else
		while (*value > 0)
		{
			*value /= 8;
			*i += 1;
		}
}

t_bool	convert_int_base_8(t_conversion_result *res, t_conversion_input *inp)
{
	blalal(8)
}

//1.999 @ 2
//0.5 @ 0
//0.125 @ 2
//0.008 @ 2
int main()
{
	t_conversion_result res;
	t_conversion_input	input;

	input.int_value = 20;
	//input.double_float_value = 1.545f;
	//input.precision = 0;
	//printf("printf : %.0f\n", input.double_float_value);
	//convert_double(&res, &input);
	convert_int_base_8(&res, &input);
	printf("%s", res.str);


	// printf("%f", __FLT_MIN__);

	// __DBL_MAX__; //1.7976931348623157e+308
	// __DBL_MIN__; //2.2250738585072014e-308
	// __LDBL_MAX__; //1.18973149535723176502e+4932L
	// __INT64_MAX__; //9223372036854775807LL
	return (0);
}