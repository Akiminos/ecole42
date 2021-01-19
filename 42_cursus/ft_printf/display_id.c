/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_id.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 19:42:04 by bdruez            #+#    #+#             */
/*   Updated: 2020/02/27 17:21:42 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int			get_abs_nbr_len(int nbr)
{
	if (nbr == -2147483648)
		return (10);
	if (nbr < 0)
		nbr = -nbr;
	return (get_int_len(nbr));
}

void		print_abs_nbr(int nbr)
{
	if (nbr == -2147483648)
	{
		ft_putchar_fd('2', 1);
		nbr = 147483648;
	}
	if (nbr < 0)
		nbr = -nbr;
	ft_putnbr_fd(nbr, 1);
}

static int	print_right_justify(t_data data, int nbr)
{
	int ret;

	if (data.has_dot)
		ret = print_id_right_prec(data, nbr, get_abs_nbr_len(nbr));
	else
		ret = print_id_right_no_prec(data, nbr, get_abs_nbr_len(nbr));
	return (ret);
}

static int	print_left_justify(t_data data, int nbr)
{
	int ret;

	if (data.has_dot)
		ret = print_id_left_prec(data, nbr, get_abs_nbr_len(nbr));
	else
		ret = print_id_left_no_prec(data, nbr, get_abs_nbr_len(nbr));
	return (ret);
}

int			display_id_conv(va_list ap, t_data data)
{
	int	nbr;
	int	ret;

	nbr = va_arg(ap, int);
	if (data.left_justify)
		ret = print_left_justify(data, nbr);
	else
		ret = print_right_justify(data, nbr);
	return (ret);
}
