/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/18 16:49:21 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/25 15:17:16 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_PRINTF_H
#define PF_PRINTF_H
# include <stdint.h>
# include <stdbool.h>
# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

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
	int32_t		padding;
	int32_t		precision;
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

/*conversions*/
bool	pf_c(t_conversion_in *c_in, t_conversion_out *c_out, va_list *argl);
bool	pf_c_upper(t_conversion_in *c_in, t_conversion_out *c_out,
	va_list *argl);

bool	pf_di(t_conversion_in *c_in, t_conversion_out *c_out, va_list *argl);
bool	pf_f(t_conversion_in *c_in, t_conversion_out *c_out, va_list *argl);
bool	pf_ouxX(t_conversion_in *c_in, t_conversion_out *c_out, va_list *argl);
bool	pf_p(t_conversion_in *c_in, t_conversion_out *c_out, va_list *argl);
bool	pf_percent(t_conversion_in *c_in, t_conversion_out *c_out,
	va_list *argl);

bool	pf_s(t_conversion_in *c_in, t_conversion_out *c_out, va_list *argl);
bool	pf_s_upper(t_conversion_in *c_in, t_conversion_out *c_out,
	va_list *argl);

/*util*/
int64_t pf_10_power_n(int32_t n);
int8_t	pf_intlen(int64_t value, uint8_t base);
char	*pf_itoa_base(int64_t value, int8_t base, int32_t *len, bool lowercase);
char	*pf_ldtoa(long double nbr, int32_t precision, int32_t *len);
char	*pf_memcpy(char *dst, char *src, size_t n);
char	*pf_memmove(char *dst, char *src, size_t len);
int8_t	pf_uintlen(uint64_t value, uint8_t base);
char	*pf_uitoa_base(uint64_t value, int8_t base, int32_t *len, bool lowercase);
int		wchar_byte_count(int wchar);
char	*pf_wchar_to_str(int wchar, int *size);
char	*pf_wstr_to_str(int *wstr, int *size);

/* src other */
bool read_instruction(char **str, t_conversion_in *c_in);
bool	pf_append_right(t_pf_output *output, char *str, size_t str_len, bool free_str);
bool	pf_append_left(t_pf_output *output, char *str, size_t str_len, bool free_str);

#endif
