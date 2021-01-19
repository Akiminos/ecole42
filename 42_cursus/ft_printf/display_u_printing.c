/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_u_printing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 13:25:06 by bdruez            #+#    #+#             */
/*   Updated: 2020/02/28 14:08:26 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	get_u_total_len(t_data data, unsigned int nbr)
{
	int ret;

	if (nbr == 0 && data.has_dot && data.dot_value == 0)
		return (data.min_width);
	ret = get_uint_len(nbr);
	if (data.has_dot)
		ret = ft_max(ret, data.dot_value);
	ret = ft_max(ret, data.min_width);
	return (ret);
}

int			print_u_right_no_prec(t_data data, unsigned int nbr)
{
	int iter;

	iter = data.min_width - get_int_len(nbr);
	if (!data.zeros)
		while (iter-- > 0)
			ft_putchar_fd(' ', 1);
	if (data.zeros)
		while (iter-- > 0)
			ft_putchar_fd('0', 1);
	ft_putnbr_uint_fd(nbr, 1);
	return (get_u_total_len(data, nbr));
}

int			print_u_right_prec(t_data data, unsigned int nbr)
{
	int iter;
	int iter_prec;

	if (nbr == 0 && data.dot_value == 0)
	{
		iter_prec = 0;
		iter = data.min_width;
	}
	else
	{
		iter_prec = (data.dot_value - get_uint_len(nbr) >= 0 ?
				data.dot_value - get_uint_len(nbr) : 0);
		iter = data.min_width - (get_uint_len(nbr) + iter_prec);
	}
	while (iter-- > 0)
		ft_putchar_fd(' ', 1);
	while (iter_prec-- > 0)
		ft_putchar_fd('0', 1);
	if (nbr != 0 || data.dot_value != 0)
		ft_putnbr_uint_fd(nbr, 1);
	return (get_u_total_len(data, nbr));
}

int			print_u_left_no_prec(t_data data, unsigned int nbr)
{
	int iter;

	iter = data.min_width - get_uint_len(nbr);
	ft_putnbr_uint_fd(nbr, 1);
	while (iter-- > 0)
		ft_putchar_fd(' ', 1);
	return (get_u_total_len(data, nbr));
}

int			print_u_left_prec(t_data data, unsigned int nbr)
{
	int iter;
	int iter_prec;

	if (nbr == 0 && data.dot_value == 0)
	{
		iter_prec = 0;
		iter = data.min_width;
	}
	else
	{
		iter_prec = (data.dot_value - get_uint_len(nbr) >= 0 ?
				data.dot_value - get_uint_len(nbr) : 0);
		iter = data.min_width - (get_uint_len(nbr) + iter_prec);
	}
	while (iter_prec-- > 0)
		ft_putchar_fd('0', 1);
	if (nbr != 0 || data.dot_value != 0)
		ft_putnbr_uint_fd(nbr, 1);
	while (iter-- > 0)
		ft_putchar_fd(' ', 1);
	return (get_u_total_len(data, nbr));
}
