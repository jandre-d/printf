/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/06 12:29:23 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/17 11:00:22 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include "libpf/libpf.h"
# include <stdint.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdarg.h>
//https://www.lix.polytechnique.fr/~liberti/public/computing/prog/c/C/FUNCTIONS/format.html

typedef struct	s_conversion_result
{
	char	*str;
	int		len;
	bool	is_negative;
	bool	has_decimal;
}				t_conversion_result;

typedef struct	s_output
{
	char 		*str;
	size_t		str_size;
	size_t		str_useage;
}				t_output;

typedef struct	s_conversion_input
{
	char		conversion_type;
	bool		flag_h;
	bool		flag_hh;
	bool		flag_l;
	bool		flag_ll;
	bool		flag_L;
	bool		flag_hash;
	bool		flag_0;
	bool		flag_min;
	bool		flag_plus;
	bool		flag_space;
	int			padding;
	int64_t 	int_value;
	int			precision;
	long double	long_double_float_value;
}				t_conversion_input;

#endif