/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_id_printing.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 13:38:30 by bdruez            #+#    #+#             */
/*   Updated: 2020/03/10 10:31:43 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		get_total_len(t_data data, int nbr, int nbr_len)
{
	int ret;

	if (nbr == 0 && data.has_dot && data.dot_value == 0)
		return (data.min_width);
	ret = nbr_len;
	if (data.has_dot)
		ret = ft_max(ret, data.dot_value);
	if (nbr < 0)
		ret++;
	ret = ft_max(ret, data.min_width);
	return (ret);
}

int		print_id_left_no_prec(t_data data, int nbr, int nbr_len)
{
	int iter;

	iter = data.min_width - get_int_len(nbr);
	ft_putnbr_fd(nbr, 1);
	while (iter-- > 0)
		ft_putchar_fd(' ', 1);
	return (get_total_len(data, nbr, nbr_len));
}

int		print_id_left_prec(t_data data, int nbr, int nbr_len)
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
		iter_prec = (data.dot_value - nbr_len >= 0 ?
				data.dot_value - nbr_len : 0);
		iter = data.min_width - (get_int_len(nbr) + iter_prec);
	}
	if (nbr < 0)
		ft_putchar_fd('-', 1);
	while (iter_prec-- > 0)
		ft_putchar_fd('0', 1);
	if (nbr != 0 || data.dot_value != 0)
		print_abs_nbr(nbr);
	while (iter-- > 0)
		ft_putchar_fd(' ', 1);
	return (get_total_len(data, nbr, nbr_len));
}

int		print_id_right_no_prec(t_data data, int nbr, int nbr_len)
{
	int iter;

	iter = data.min_width - get_int_len(nbr);
	if (!data.zeros)
		while (iter-- > 0)
			ft_putchar_fd(' ', 1);
	if (nbr < 0)
		ft_putchar_fd('-', 1);
	if (data.zeros)
		while (iter-- > 0)
			ft_putchar_fd('0', 1);
	print_abs_nbr(nbr);
	return (get_total_len(data, nbr, nbr_len));
}

int		print_id_right_prec(t_data data, int nbr, int nbr_len)
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
		iter_prec = (data.dot_value - nbr_len >= 0 ?
				data.dot_value - nbr_len : 0);
		iter = data.min_width - (get_int_len(nbr) + iter_prec);
	}
	while (iter-- > 0)
		ft_putchar_fd(' ', 1);
	if (nbr < 0)
		ft_putchar_fd('-', 1);
	while (iter_prec-- > 0)
		ft_putchar_fd('0', 1);
	if (nbr != 0 || data.dot_value != 0)
		print_abs_nbr(nbr);
	return (get_total_len(data, nbr, nbr_len));
}
