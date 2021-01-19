/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_x_printing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 15:22:20 by bdruez            #+#    #+#             */
/*   Updated: 2020/03/10 10:38:10 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	get_x_total_len(t_data data, unsigned int hex)
{
	int ret;

	if (hex == 0 && data.has_dot && data.dot_value == 0)
		return (data.min_width);
	ret = get_hex_len(hex);
	if (data.has_dot)
		ret = ft_max(ret, data.dot_value);
	ret = ft_max(ret, data.min_width);
	return (ret);
}

int			print_x_left_no_prec(t_data data, unsigned int hex, int is_upper)
{
	int iter;

	ft_putnbr_hex_fd(hex, is_upper, 1);
	iter = data.min_width - get_hex_len(hex);
	while (iter-- > 0)
		data.zeros ? ft_putchar_fd('0', 1) : ft_putchar_fd(' ', 1);
	return (get_x_total_len(data, hex));
}

int			print_x_left_prec(t_data data, unsigned int hex, int is_upper)
{
	int	iter_zeros;
	int	iter_space;

	iter_zeros = ft_max(0, data.dot_value - get_hex_len(hex));
	if (hex == 0 && data.dot_value == 0)
		iter_space = data.min_width;
	else
	{
		iter_space = ft_max(0,
				data.min_width - (iter_zeros + get_hex_len(hex)));
	}
	while (iter_zeros-- > 0)
		ft_putchar_fd('0', 1);
	if (hex != 0 || data.dot_value != 0)
		ft_putnbr_hex_fd(hex, is_upper, 1);
	while (iter_space-- > 0)
		ft_putchar_fd(' ', 1);
	return (get_x_total_len(data, hex));
}

int			print_x_right_no_prec(t_data data, unsigned int hex, int is_upper)
{
	int iter;

	iter = data.min_width - get_hex_len(hex);
	while (iter-- > 0)
		data.zeros ? ft_putchar_fd('0', 1) : ft_putchar_fd(' ', 1);
	ft_putnbr_hex_fd(hex, is_upper, 1);
	return (get_x_total_len(data, hex));
}

int			print_x_right_prec(t_data data, unsigned int hex, int is_upper)
{
	int	iter_zeros;
	int	iter_space;

	iter_zeros = ft_max(0, data.dot_value - get_hex_len(hex));
	if (hex == 0 && data.dot_value == 0)
		iter_space = data.min_width;
	else
	{
		iter_space = ft_max(0,
				data.min_width - (iter_zeros + get_hex_len(hex)));
	}
	while (iter_space-- > 0)
		ft_putchar_fd(' ', 1);
	while (iter_zeros-- > 0)
		ft_putchar_fd('0', 1);
	if (hex != 0 || data.dot_value != 0)
		ft_putnbr_hex_fd(hex, is_upper, 1);
	return (get_x_total_len(data, hex));
}
