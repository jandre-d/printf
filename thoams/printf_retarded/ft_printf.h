/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: twoerdem <twoerdem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/07 15:36:50 by twoerdem       #+#    #+#                */
/*   Updated: 2019/04/03 19:08:30 by twoerdem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdarg.h>
# include "./libft/libft.h"

typedef struct		s_pf
{
	char			*str;
	int				pos;
	size_t			len;
}					t_pf;

int		ft_printf(const char *format, ...);

#endif
