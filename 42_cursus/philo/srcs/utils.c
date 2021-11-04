/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:02:26 by bdruez            #+#    #+#             */
/*   Updated: 2021/11/04 12:30:11 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	if (str == NULL)
		return (0);
	while (str[len] != 0)
		len++;
	return (len);
}

int	ft_isdigit(char chr)
{
	if (chr >= 48 && chr <= 57)
		return (TRUE);
	return (FALSE);
}

int	is_number(char *number)
{
	int	is_digit;
	int	iter;
	int	size;

	is_digit = FALSE;
	iter = 0;
	size = ft_strlen(number);
	if (size < 1 || size > 10)
		return (FALSE);
	else if (size == 1 && ft_isdigit(number[0]) == FALSE)
		return (FALSE);
	else
	{
		if (number[0] == '-')
			iter++;
		while (iter < size)
			if (ft_isdigit(number[iter++]) == FALSE)
				return (FALSE);
	}
	return (TRUE);
}

int	is_valid_integer(char *number)
{
	long int	iter;
	long int	res;
	long int	sign;

	iter = 0;
	res = 0;
	sign = 1;
	if (number[iter] == '-')
	{
		sign = -1;
		iter++;
	}
	while (iter < ft_strlen(number))
	{
		res *= 10;
		res += (number[iter] - 48);
		iter++;
	}
	res *= sign;
	if (res < -2147483648 || res > 2147483647)
		return (FALSE);
	return (TRUE);
}

int	ascii_to_integer(char *number)
{
	long int	iter;
	long int	res;
	long int	sign;

	iter = 0;
	res = 0;
	sign = 1;
	if (number[iter] == '-')
	{
		sign = -1;
		iter++;
	}
	while (iter < ft_strlen(number))
	{
		res *= 10;
		res += (number[iter] - 48);
		iter++;
	}
	res *= sign;
	return ((int)res);
}
