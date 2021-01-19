/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 18:50:12 by bdruez            #+#    #+#             */
/*   Updated: 2020/02/28 14:48:35 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	get_p_total_len(t_data data, unsigned long ptr)
{
	int ret;

	if (ptr == 0 && data.has_dot && data.dot_value == 0)
		return (ft_max(2, data.min_width));
	ret = get_ptr_len(ptr);
	ret = ft_max(ret, data.min_width);
	return (ret);
}

static int	print_left_justify(t_data data, unsigned long ptr)
{
	int iter;

	if (ptr == 0 && data.has_dot && !data.dot_value)
		iter = data.min_width - 2;
	else
		iter = data.min_width - get_ptr_len(ptr);
	ft_putstr_fd("0x", 1);
	if (!(ptr == 0 && data.has_dot && !data.dot_value))
		ft_putnbr_hex_fd(ptr, 0, 1);
	while (iter-- > 0)
		ft_putchar_fd(' ', 1);
	return (get_p_total_len(data, ptr));
}

static int	print_right_justify(t_data data, unsigned long ptr)
{
	int iter;

	if (ptr == 0 && data.has_dot && !data.dot_value)
		iter = data.min_width - 2;
	else
		iter = data.min_width - get_ptr_len(ptr);
	while (iter-- > 0)
		ft_putchar_fd(' ', 1);
	ft_putstr_fd("0x", 1);
	if (!(ptr == 0 && data.has_dot && !data.dot_value))
		ft_putnbr_hex_fd(ptr, 0, 1);
	return (get_p_total_len(data, ptr));
}

int			display_p_conv(va_list ap, t_data data)
{
	unsigned long	ptr;
	int				ret;

	ptr = va_arg(ap, unsigned long);
	if (data.left_justify)
		ret = print_left_justify(data, ptr);
	else
		ret = print_right_justify(data, ptr);
	return (ret);
}
