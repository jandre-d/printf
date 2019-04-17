/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_instruction.h                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 11:38:31 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/17 18:45:35 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_INSTRUCTION_H
# define READ_INSTRUCTION_H
# include "libpf/libpf.h"

bool read_instruction(char **str, t_conversion_input *c_in);

#endif