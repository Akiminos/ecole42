/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 16:24:39 by bdruez            #+#    #+#             */
/*   Updated: 2019/11/11 15:31:14 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_nb_len(int n)
{
	size_t len;

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

char			*ft_itoa(int n)
{
	size_t	len;
	size_t	iter;
	char	*res;

	len = get_nb_len(n);
	if (!(res = malloc(sizeof(*res) * (len + 1))))
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
		res[iter] = (n % 10 < 0 ? -(n % 10) + 48 : (n % 10) + 48);
		n /= 10;
		iter--;
	}
	return (res);
}
