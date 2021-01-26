/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 09:45:23 by bdruez            #+#    #+#             */
/*   Updated: 2019/11/07 10:53:04 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			iter;
	long long	res;
	int			sign;

	iter = 0;
	res = 0;
	sign = 1;
	while (ft_isspace(str[iter]))
		iter++;
	if (str[iter] == '+')
		iter++;
	else if (str[iter] == '-')
	{
		sign = -sign;
		iter++;
	}
	while (ft_isdigit(str[iter]))
	{
		res *= 10;
		res += (str[iter] - 48);
		iter++;
	}
	return ((int)(res * sign));
}
