/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 13:03:06 by bdruez            #+#    #+#             */
/*   Updated: 2020/02/28 14:49:03 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_ulong_len(unsigned long nbr)
{
	int res;

	res = 1;
	while ((nbr = nbr / 10) != 0)
		res++;
	return (res);
}

int	get_uint_len(unsigned int nbr)
{
	int res;

	res = 1;
	while ((nbr = nbr / 10) != 0)
		res++;
	return (res);
}

int	get_int_len(int nbr)
{
	int	res;

	res = 1;
	if (nbr == -2147483648)
		return (11);
	if (nbr < 0)
	{
		nbr = -nbr;
		res++;
	}
	while ((nbr = nbr / 10) != 0)
		res++;
	return (res);
}

int	get_hex_len(unsigned int nbr)
{
	int res;

	res = 1;
	while ((nbr = nbr / 16) != 0)
		res++;
	return (res);
}

int	get_ptr_len(unsigned long nbr)
{
	int res;

	res = 3;
	while ((nbr = nbr / 16) != 0)
		res++;
	return (res);
}
