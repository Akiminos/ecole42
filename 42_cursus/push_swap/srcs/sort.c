/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 13:07:17 by bdruez            #+#    #+#             */
/*   Updated: 2021/09/13 21:39:12 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	move_lowest_ele(t_stack *primary, t_stack *secondary)
{
	int		pos;

	pos = get_lowest_ele_pos(primary);
	if (pos > primary->size / 2 - 1 && primary->size > 2)
		pos -= primary->size;
	while (pos != 0)
	{
		if (pos < 0)
		{
			reverse_rotate(primary);
			ft_putstr_fd("rra\n", 1);
			pos++;
		}
		else
		{
			rotate(primary);
			ft_putstr_fd("ra\n", 1);
			pos--;
		}
	}
	push(primary, secondary);
	ft_putstr_fd("pb\n", 1);
	return (0);
}

int	move_highest_ele(t_stack *primary, t_stack *secondary)
{
	int		pos;

	pos = get_highest_ele_pos(primary);
	if (pos > primary->size / 2 - 1 && primary->size > 2)
		pos -= primary->size;
	while (pos != 0)
	{
		if (pos < 0)
		{
			reverse_rotate(primary);
			ft_putstr_fd("rra\n", 1);
			pos++;
		}
		else
		{
			rotate(primary);
			ft_putstr_fd("ra\n", 1);
			pos--;
		}
	}
	push(primary, secondary);
	ft_putstr_fd("pb\n", 1);
	return (0);
}

int	move_element_at_pos(t_stack *stack, int pos, char stack_name)
{
	int		size;
	int		iter;

	iter = 0;
	size = stack->size;
	if (pos <= size / 2)
	{
		while (iter++ < pos)
		{
			rotate(stack);
			print_rotate(stack_name);
		}
	}
	else
	{
		while (iter++ < size - pos)
		{
			reverse_rotate(stack);
			print_reverse_rotate(stack_name);
		}
	}
	return (0);
}

int	solve(t_stack *primary, t_stack *secondary)
{
	if (primary->size <= 5)
		sort_less_than_five(primary, secondary);
	else if (primary-> size <= 100)
		sort_hundred(primary, secondary);
	else
		sort_more_than_hundred(primary, secondary);
	return (0);
}

int	is_sorted(t_stack *a_stack)
{
	int			iter;
	t_stack_ele	*element;

	iter = 0;
	element = a_stack->head;
	while (iter < a_stack->size - 1)
	{
		if (element->value >= element->next->value)
			return (-1);
		element = element->next;
		iter++;
	}
	return (0);
}
