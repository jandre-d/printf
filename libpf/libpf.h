/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libpf.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/12 13:44:40 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/17 20:44:29 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPF_H
# define LIBPF_H
# include "../libft/libft.h"
# include <stdint.h>
# include <stdbool.h>
# include <stdarg.h>

typedef struct	s_pf_output
{
	char 	*str;
	size_t	str_size;
	size_t	str_useage;
}				t_pf_output;

typedef struct	s_conversion_output
{
	char	*str;
	int		len;
	bool	is_negative;
	bool	has_decimal;
}				t_conversion_out;

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
}				t_conversion_in;

typedef struct	s_ldbltoa_vars
{
	int64_t	integer_part;
	int64_t	decimal_part;
	int32_t	decimal_part_leading_zeros;
	bool	is_negative;
	int32_t len;
	char 	*to_return;
}				t_ldbltoa_vars;

int8_t	pf_intlen(int64_t value, uint8_t base);
char	*pf_itoa_base(int64_t value, int8_t base, bool lowercase);
int8_t	pf_uintlen(uint64_t value, uint8_t base);
char	*pf_uitoa_base(uint64_t value, int8_t base, bool lowercase);
int64_t pf_10_power_n(int32_t n);
char	*pf_ldtoa(long double nbr, int32_t precision);
void	*pf_memmove(char *dst, char *src, size_t len);
void	*pf_memcpy(char *dst, char *src, size_t n);
bool	pf_append_right(t_pf_output *output, char *str, size_t str_len, bool free_str);
bool	pf_append_left(t_pf_output *output, char *str, size_t str_len, bool free_str);

#endif