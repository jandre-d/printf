/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   int_base_10.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jandre-d <jandre-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/09 17:53:17 by jandre-d       #+#    #+#                */
/*   Updated: 2019/04/09 17:53:22 by jandre-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void	convert_int_base_8(t_conversion_result *res, t_conversion_data *inp)
{
	char			*character_set;
	unsigned int	value;
	int				i;

	character_set = "0123456789ABCDEF";
	i = 0;
	value = inp->int_value;
	if (value = 0)
		i = 0;
	else
		while (value > 0)
		{
			value /= 16;
			i++;
		}
	res->str = TAKE_MULTI(char, i + 1, "ft_itoa_base");
	if (res->str == NULL)
		return ;
	i--;
	while (i >= 0)
	{
		res->str[i] = character_set[value % 16];
		value /= 16;
		i--;
	}
}
