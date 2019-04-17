/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conversions.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 17:00:25 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/17 20:44:51 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSIONS_H
# define CONVERSIONS_H

# include "../libpf/libpf.h"
# include <stdarg.h>

bool	pf_c(t_conversion_in *c_in, t_conversion_out *c_out, va_list *argl);
bool	pf_s(t_conversion_in *c_in, t_conversion_out *c_out, va_list *argl);
bool	pf_p(t_conversion_in *c_in, t_conversion_out *c_out, va_list *argl);

bool	pf_d(t_conversion_in *c_in, t_conversion_out *c_out, va_list *argl);
bool	pf_i(t_conversion_in *c_in, t_conversion_out *c_out, va_list *argl);
bool	pf_o(t_conversion_in *c_in, t_conversion_out *c_out, va_list *argl);
bool	pf_u(t_conversion_in *c_in, t_conversion_out *c_out, va_list *argl);
bool	pf_x(t_conversion_in *c_in, t_conversion_out *c_out, va_list *argl);
bool	pf_x_upper(t_conversion_in *c_in, t_conversion_out *c_out,
	va_list *argl);

bool	pf_f(t_conversion_in *c_in, t_conversion_out *c_out, va_list *argl);

bool	pf_percent(t_conversion_in *c_in, t_conversion_out *c_out,
	va_list *argl);

#endif