/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrn_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 16:03:00 by bdruez            #+#    #+#             */
/*   Updated: 2021/09/13 21:00:28 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrn_fd(char *s, int max, int fd)
{
	int	count;

	count = 0;
	if (s)
	{
		while (s[count] && count < max)
		{
			ft_putchar_fd(s[count], fd);
			count++;
		}
	}
}
