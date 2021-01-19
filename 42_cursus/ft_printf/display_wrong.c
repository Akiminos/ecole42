/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_wrong.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 14:55:51 by bdruez            #+#    #+#             */
/*   Updated: 2020/01/10 16:47:47 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	print_char(t_data data, char chr)
{
	char sep;

	sep = ' ';
	if (data.zeros && !data.left_justify)
		sep = '0';
	if (data.left_justify == TRUE)
		ft_putchar_fd(chr, 1);
	while ((data.min_width)-- > 1)
		ft_putchar_fd(sep, 1);
	if (data.left_justify == FALSE)
		ft_putchar_fd(chr, 1);
}

int			display_wrong_conv(va_list ap, t_data data)
{
	int ret;

	(void)ap;
	data = ft_check_and_set_min_width(data, 1);
	ret = ((data.min_width > 0) ? data.min_width : 1);
	print_char(data, data.conv);
	return (ret);
}
