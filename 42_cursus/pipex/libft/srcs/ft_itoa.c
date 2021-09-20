/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 16:24:39 by bdruez            #+#    #+#             */
/*   Updated: 2021/09/13 20:48:34 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_nb_len(int n)
{
	size_t	len;

	len = 1;
	if (n < 0)
		len++;
	while (n / 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	get_res_digit(int n)
{
	int		digit;

	digit = 0;
	if (n % 10 < 0)
		digit = -(n % 10) + 48;
	else
		digit = (n % 10) + 48;
	return (digit);
}

char	*ft_itoa(int n)
{
	size_t	len;
	size_t	iter;
	char	*res;

	len = get_nb_len(n);
	res = malloc(sizeof(*res) * (len + 1));
	if (res == 0)
		return (0);
	res[len] = 0;
	iter = len - 1;
	if (n < 0)
	{
		res[0] = '-';
		len--;
	}
	while (len--)
	{
		res[iter] = get_res_digit(n);
		n /= 10;
		iter--;
	}
	return (res);
}
