/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libpf.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/12 13:44:40 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/12 14:06:58 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPF_H
# define LIBPF_H
# include "../libft/libft.h"
# include <stdint.h>

typedef uint8_t t_bool;

int8_t	pf_intlen(int64_t value, uint8_t base);
char	*pf_itoa_base(int64_t value, int8_t base, t_bool lowercase);

#endif