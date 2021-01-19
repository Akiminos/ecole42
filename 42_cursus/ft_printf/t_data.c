/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_data.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 14:46:25 by bdruez            #+#    #+#             */
/*   Updated: 2020/03/10 13:15:16 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

t_data	ft_new_data(void)
{
	t_data data;

	data.zeros = FALSE;
	data.left_justify = FALSE;
	data.min_width = 0;
	data.has_dot = FALSE;
	data.dot_value = 0;
	data.conv = '\0';
	return (data);
}

int		ft_get_nbr(va_list ap, const char **str)
{
	int res;

	res = 0;
	if (**str == '*')
	{
		res = va_arg(ap, int);
		(*str)++;
		return (res);
	}
	while (ft_isdigit(**str))
	{
		res *= 10;
		res += **str - 48;
		(*str)++;
	}
	return (res);
}

t_data	ft_get_flags(t_data data, const char **to_print)
{
	while (**to_print == '-' || **to_print == '0')
	{
		if (**to_print == '0')
			data.zeros = TRUE;
		else
			data.left_justify = TRUE;
		(*to_print)++;
	}
	return (data);
}

t_data	ft_check_and_set_min_width(t_data data, int min_width)
{
	if (data.min_width == 0)
		data.min_width = min_width;
	return (data);
}

t_data	ft_get_data_info(va_list ap, const char **to_print)
{
	t_data data;

	data = ft_new_data();
	(*to_print)++;
	data = ft_get_flags(data, to_print);
	data.min_width = ft_get_nbr(ap, to_print);
	if (data.min_width < 0)
	{
		data.min_width = -data.min_width;
		data.left_justify = TRUE;
	}
	if (**to_print == '.')
	{
		data.has_dot = TRUE;
		(*to_print)++;
	}
	data.dot_value = ft_get_nbr(ap, to_print);
	if (data.dot_value < 0)
		data.has_dot = FALSE;
	while (is_flag(**to_print))
		(*to_print)++;
	if (**to_print)
		data.conv = *(*to_print)++;
	return (data);
}
