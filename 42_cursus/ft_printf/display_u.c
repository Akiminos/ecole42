/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 19:45:31 by bdruez            #+#    #+#             */
/*   Updated: 2020/02/28 14:09:25 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	print_right_justify(t_data data, unsigned int nbr)
{
	int ret;

	if (data.has_dot)
		ret = print_u_right_prec(data, nbr);
	else
		ret = print_u_right_no_prec(data, nbr);
	return (ret);
}

static int	print_left_justify(t_data data, unsigned int nbr)
{
	int ret;

	if (data.has_dot)
		ret = print_u_left_prec(data, nbr);
	else
		ret = print_u_left_no_prec(data, nbr);
	return (ret);
}

int			display_u_conv(va_list ap, t_data data)
{
	unsigned int	nbr;
	int				ret;

	nbr = va_arg(ap, unsigned int);
	if (data.left_justify)
		ret = print_left_justify(data, nbr);
	else
		ret = print_right_justify(data, nbr);
	return (ret);
}
