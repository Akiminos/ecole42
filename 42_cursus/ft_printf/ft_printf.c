/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 15:57:45 by bdruez            #+#    #+#             */
/*   Updated: 2020/03/10 13:42:34 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		call_display(va_list ap, t_data data)
{
	int		nb_printed;

	nb_printed = 0;
	if (data.conv == 's')
		nb_printed = display_s_conv(ap, data);
	else if (data.conv == 'd' || data.conv == 'i')
		nb_printed = display_id_conv(ap, data);
	else if (data.conv == 'c')
		nb_printed = display_c_conv(ap, data);
	else if (data.conv == 'x')
		nb_printed = display_x_conv(ap, HEX_LOWER, data);
	else if (data.conv == 'X')
		nb_printed = display_x_conv(ap, HEX_UPPER, data);
	else if (data.conv == 'u')
		nb_printed = display_u_conv(ap, data);
	else if (data.conv == 'p')
		nb_printed = display_p_conv(ap, data);
	else
		nb_printed = display_wrong_conv(ap, data);
	return (nb_printed);
}

int		check_char(const char **to_print, va_list ap)
{
	t_data data;

	data = ft_new_data();
	if (**to_print != '%')
	{
		ft_putchar_fd(*(*to_print)++, 1);
		return (1);
	}
	else
	{
		data = ft_get_data_info(ap, to_print);
		return (call_display(ap, data));
	}
}

int		ft_printf(const char *to_print, ...)
{
	va_list	ap;
	int		nb_printed;

	nb_printed = 0;
	va_start(ap, to_print);
	while (*to_print)
		nb_printed += check_char(&to_print, ap);
	va_end(ap);
	return (nb_printed);
}
