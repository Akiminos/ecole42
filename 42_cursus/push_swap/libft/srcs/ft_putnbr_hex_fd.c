/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:57:22 by bdruez            #+#    #+#             */
/*   Updated: 2021/09/13 20:59:11 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_hex(unsigned long n, int is_upper, int fd)
{
	if (n <= 9)
		ft_putchar_fd(n + 48, fd);
	else if (is_upper)
		ft_putchar_fd(n + 55, fd);
	else
		ft_putchar_fd(n + 87, fd);
}

void	ft_putnbr_hex_fd(unsigned long n, int is_upper, int fd)
{
	if (n <= 15)
		print_hex(n, is_upper, fd);
	else
	{
		ft_putnbr_hex_fd((n / 16), is_upper, fd);
		print_hex(n % 16, is_upper, fd);
	}
}
