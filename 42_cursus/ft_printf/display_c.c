/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 19:44:29 by bdruez            #+#    #+#             */
/*   Updated: 2020/01/10 16:47:32 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	print_c(t_data data, char chr)
{
	if (data.left_justify == TRUE)
		ft_putchar_fd(chr, 1);
	while ((data.min_width)-- > 1)
		ft_putchar_fd(' ', 1);
	if (data.left_justify == FALSE)
		ft_putchar_fd(chr, 1);
}

int			display_c_conv(va_list ap, t_data data)
{
	char	chr;
	int		ret;

	chr = va_arg(ap, int);
	data = ft_check_and_set_min_width(data, 1);
	ret = ((data.min_width > 0) ? data.min_width : 1);
	print_c(data, chr);
	return (ret);
}
