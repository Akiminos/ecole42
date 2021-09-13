/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:57:22 by bdruez            #+#    #+#             */
/*   Updated: 2021/09/13 20:58:39 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	nbr;

	nbr = n;
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = -nbr;
	}
	if (nbr <= 9)
		ft_putchar_fd(nbr + 48, fd);
	else
	{
		ft_putnbr_fd((int)(nbr / 10), fd);
		ft_putchar_fd(nbr % 10 + 48, fd);
	}
}
