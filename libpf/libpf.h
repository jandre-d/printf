/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libpf.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/12 13:44:40 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/13 20:08:56 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPF_H
# define LIBPF_H
# include "../libft/libft.h"
# include <stdint.h>

typedef uint8_t t_bool;

typedef struct	s_ldbltoa_vars
{
	int64_t	integer_part;
	int64_t	decimal_part;
	int32_t	decimal_part_leading_zeros;
	t_bool	is_negative;
	int32_t len;
	char 	*to_return;
}				t_ldbltoa;


int8_t	pf_intlen(int64_t value, uint8_t base);
char	*pf_itoa_base(int64_t value, int8_t base, t_bool lowercase);
int8_t	pf_uintlen(uint64_t value, uint8_t base);
char	*pf_uitoa_base(uint64_t value, int8_t base, t_bool lowercase);
int64_t pf_10_power_n(int32_t n);
char	*pf_ldtoa(long double nbr, int32_t precision);
#endif