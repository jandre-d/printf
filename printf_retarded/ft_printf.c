/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: twoerdem <twoerdem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/28 17:38:39 by twoerdem       #+#    #+#                */
/*   Updated: 2019/04/04 14:13:08 by twoerdem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	char_add(t_pf *pf, char c)
{
	char tmp[2];

	tmp[0] = c;
	tmp[1] = '\0';
	pf->str = ft_strjoin(pf->str, tmp);
}

void	convert_formats(const char *format, va_list args, t_pf *pf)
{
	pf->pos++;
	if (format[pf->pos] == 's')
		pf->str = ft_strjoin(pf->str, (va_arg(args, char *)));
	if (format[pf->pos] == 'd')
		pf->str = ft_strjoin(pf->str, ft_itoa(va_arg(args, int)));
	if (format[pf->pos] == 'i')
		pf->str = ft_strjoin(pf->str, ft_itoa(va_arg(args, int)));
	if (format[pf->pos] == 'c')
		char_add(pf, (char)va_arg(args, int));
	if (format[pf->pos] == '%')
		char_add(pf, '%');
	pf->pos++;
}

int		parse_format(const char *format, va_list args)
{
	t_pf	*pf;
	char	tmp[2];

	pf = (t_pf *)malloc(sizeof(t_pf *));
	tmp[1] = '\0';
	pf->pos = 0;
	pf->str = ft_strnew(1);
	while (format[pf->pos] && args)
	{
		if (format[pf->pos] == '%')
		{
			convert_formats(format, args, pf);
		}
		tmp[0] = format[pf->pos];
		pf->str = ft_strjoin(pf->str, tmp);
		pf->pos++;
	}
	ft_putstr(pf->str);
	return (pf->pos);
}

int		ft_printf(const char *format, ...)
{
	va_list	args;
	int		ret;

	va_start(args, format);
	ret = parse_format(format, args);
	va_end(args);
	return (ret);
}
