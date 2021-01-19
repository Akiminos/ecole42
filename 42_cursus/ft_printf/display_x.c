/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 13:21:18 by bdruez            #+#    #+#             */
/*   Updated: 2020/03/10 10:39:10 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	print_left_justify(t_data data, unsigned int hex, int is_upper)
{
	int ret;

	if (data.has_dot)
		ret = print_x_left_prec(data, hex, is_upper);
	else
		ret = print_x_left_no_prec(data, hex, is_upper);
	return (ret);
}

static int	print_right_justify(t_data data, unsigned int hex, int is_upper)
{
	int ret;

	if (data.has_dot)
		ret = print_x_right_prec(data, hex, is_upper);
	else
		ret = print_x_right_no_prec(data, hex, is_upper);
	return (ret);
}

int			display_x_conv(va_list ap, int is_upper, t_data data)
{
	unsigned int	hex;
	int				ret;

	hex = va_arg(ap, unsigned int);
	if (data.left_justify)
		ret = print_left_justify(data, hex, is_upper);
	else
		ret = print_right_justify(data, hex, is_upper);
	return (ret);
}
