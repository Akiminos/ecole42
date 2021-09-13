/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 21:34:32 by bdruez            #+#    #+#             */
/*   Updated: 2021/09/13 21:39:16 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_rotate(char stack)
{
	if (stack == 'a')
		ft_putstr_fd("ra\n", 1);
	else
		ft_putstr_fd("rb\n", 1);
}

void	print_reverse_rotate(char stack)
{
	if (stack == 'a')
		ft_putstr_fd("rra\n", 1);
	else
		ft_putstr_fd("rrb\n", 1);
}
