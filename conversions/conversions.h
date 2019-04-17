/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conversions.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 17:00:25 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/17 18:52:09 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSIONS_H
# define CONVERSIONS_H

# include "../libpf/libpf.h"
# include "../ft_printf_structs.h"

bool	pf_c(t_conversion_input *c_in, t_conversion_result *c_out);
bool	pf_s(t_conversion_input *c_in, t_conversion_result *c_out);
bool	pf_p(t_conversion_input *c_in, t_conversion_result *c_out);

bool	pf_d(t_conversion_input *c_in, t_conversion_result *c_out);
bool	pf_i(t_conversion_input *c_in, t_conversion_result *c_out);
bool	pf_o(t_conversion_input *c_in, t_conversion_result *c_out);
bool	pf_u(t_conversion_input *c_in, t_conversion_result *c_out);
bool	pf_x(t_conversion_input *c_in, t_conversion_result *c_out);
bool	pf_x_upper(t_conversion_input *c_in, t_conversion_result *c_out);

bool	pf_f(t_conversion_input *c_in, t_conversion_result *c_out);

bool	pf_percent(t_conversion_input *c_in, t_conversion_result *c_out);

#endif