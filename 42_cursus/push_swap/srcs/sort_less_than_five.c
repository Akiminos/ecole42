/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less_than_five.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 17:02:52 by bdruez            #+#    #+#             */
/*   Updated: 2021/09/13 21:30:24 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_less_than_five(t_stack *primary, t_stack *secondary)
{
	if (primary->size == 2)
		sort_two(primary);
	else if (primary->size == 3)
		sort_three(primary);
	else if (primary->size == 4)
		sort_four(primary, secondary);
	else
		sort_five(primary, secondary);
	free_stack(primary);
	free_stack(secondary);
	return (0);
}

int	sort_two(t_stack *primary)
{
	if (primary->head->value > primary->head->next->value)
		ft_putstr_fd("sa\n", 1);
	return (0);
}

int	sort_three(t_stack *primary)
{
	int		pos;

	pos = get_highest_ele_pos(primary);
	if (pos == 1)
	{
		reverse_rotate(primary);
		ft_putstr_fd("rra\n", 1);
	}
	else if (pos == 0)
	{
		rotate(primary);
		ft_putstr_fd("ra\n", 1);
	}
	if (primary->head->value > primary->head->next->value)
		ft_putstr_fd("sa\n", 1);
	return (0);
}

int	sort_four(t_stack *primary, t_stack *secondary)
{
	move_lowest_ele(primary, secondary);
	sort_three(primary);
	ft_putstr_fd("pa\n", 1);
	return (0);
}

int	sort_five(t_stack *primary, t_stack *secondary)
{
	move_lowest_ele(primary, secondary);
	move_lowest_ele(primary, secondary);
	if (secondary->head->value < secondary->head->next->value)
	{
		swap(secondary);
		ft_putstr_fd("sb\n", 1);
	}
	sort_three(primary);
	ft_putstr_fd("pa\n", 1);
	ft_putstr_fd("pa\n", 1);
	return (0);
}
