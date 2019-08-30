/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 20:16:44 by bdruez            #+#    #+#             */
/*   Updated: 2019/08/29 12:11:04 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_put_char(char var)
{
	write(1, &var, 1);
}

void	int_char(int var)
{
	ft_put_char((var / 10) + 48);
	ft_put_char((var % 10) + 48);
}

void	print_ints(int left, int right)
{
	int_char(left);
	ft_put_char(32);
	int_char(right);
	if (left != 98 || right != 99)
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb2(void)
{
	int left;
	int right;

	left = 0;
	right = 0;
	while (left <= 98)
	{
		right = left + 1;
		while (right <= 99)
		{
			print_ints(left, right);
			right++;
		}
		left++;
	}
}
