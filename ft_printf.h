/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/06 12:29:23 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/09 16:51:57 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdint.h>
//https://www.lix.polytechnique.fr/~liberti/public/computing/prog/c/C/FUNCTIONS/format.html
typedef uint8_t	t_bool;

typedef struct	s_conversion_result
{
	char	*str;
	int		len;
}				t_conversion_result;

typedef struct	s_conversion_data
{
	char	conversion_type;
	t_bool	flag_h;
	t_bool	flag_hh;
	t_bool	flag_l;
	t_bool	flag_ll;
	t_bool	flag_L;
	t_bool	flag_hash;
	t_bool	flag_0;
	t_bool	flag_min;
	t_bool	flag_plus;
	t_bool	flag_32;
	int		padding;
	int		precision;
	long long int_value;
	double		float_value;

}				t_conversion_data;

#endif