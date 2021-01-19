/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 19:42:35 by bdruez            #+#    #+#             */
/*   Updated: 2021/01/19 11:43:46 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	get_nb_printed(t_data data, char *str)
{
	int res;
	int len;

	res = 0;
	len = ft_strlen(str);
	if (data.has_dot)
		res = ft_min(data.dot_value, len);
	else
		res = len;
	return (res);
}

static int	print_str_right(t_data data, char *str)
{
	int	count;
	int nb_printed;

	count = data.min_width;
	nb_printed = get_nb_printed(data, str);
	while (count > nb_printed)
	{
		data.zeros ? ft_putchar_fd('0', 1) : ft_putchar_fd(' ', 1);
		count--;
	}
	if (data.has_dot)
		ft_putstrn_fd(str, data.dot_value, 1);
	else
		ft_putstr_fd(str, 1);
	return (ft_max(nb_printed, data.min_width));
}

static int	print_str_left(t_data data, char *str)
{
	int	count;
	int nb_printed;

	count = data.min_width;
	nb_printed = get_nb_printed(data, str);
	if (data.has_dot)
		ft_putstrn_fd(str, data.dot_value, 1);
	else
		ft_putstr_fd(str, 1);
	while (count > nb_printed)
	{
		ft_putchar_fd(' ', 1);
		count--;
	}
	return (ft_max(nb_printed, data.min_width));
}

int			display_s_conv(va_list ap, t_data data)
{
	char	*str;
	int		ret;

	str = va_arg(ap, char *);
	if (!str)
		str = "(null)";
	if (data.left_justify)
		ret = print_str_left(data, str);
	else
		ret = print_str_right(data, str);
	return (ret);
}
