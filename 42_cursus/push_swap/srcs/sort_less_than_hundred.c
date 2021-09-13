/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less_than_hundred.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 17:54:12 by bdruez            #+#    #+#             */
/*   Updated: 2021/09/12 18:06:55 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		sort_hundred(t_stack *primary, t_stack *secondary)
{
	int		chunk_size;

	chunk_size = primary->size / 6;
	while (primary->size > chunk_size)
		sort_chunk(primary, secondary, get_chunk_max(primary, chunk_size));
	sort_chunk(primary, secondary, get_chunk_max(primary, primary->size));
	move_element_at_pos(secondary, find_highest_value_pos(secondary), 'b');
	while (secondary->size > 0)
	{
		push(secondary, primary);
		ft_putstr_fd("pa\n", 1);
	}
	free_stack(primary);
	free_stack(secondary);
	return (0);
}

int		sort_chunk(t_stack *primary, t_stack *secondary, int chunk_max)
{
	int		pos;

	pos = find_lowest_weight_pos(primary, chunk_max);
	while (pos > -1 && primary->size > 0)
	{
		move_element_at_pos(primary, pos, 'a');
		prepare_secondary(secondary, primary->head->value);
		push(primary, secondary);
		ft_putstr_fd("pb\n", 1);
		if (primary->size > 0)
			pos = find_lowest_weight_pos(primary, chunk_max);
	}
	return (0);
}

int		prepare_secondary(t_stack *secondary, int value)
{
	int		pos;

	pos = find_closest_lower_value_pos(secondary, value);
	move_element_at_pos(secondary, pos, 'b');
	return (0);
}

int		find_closest_lower_value_pos(t_stack *stack, int value)
{
	int			pos;
	int			val;
	int			iter;
	t_stack_ele	*tmp;

	tmp = stack->head;
	pos = -1;
	iter = 0;
	val = -2147483648;
	while (tmp != NULL)
	{
		if (tmp->value < value && tmp->value > val)
		{
			pos = iter;
			val = tmp->value;
		}
		iter++;
		tmp = tmp->next;
	}
	if (pos == -1)
		return (find_highest_value_pos(stack));
	else
		return (pos);
}

int		find_highest_value_pos(t_stack *stack)
{
	int			pos;
	int			val;
	int			iter;
	t_stack_ele	*tmp;

	tmp = stack->head;
	pos = -1;
	iter = 0;
	val = 0;
	if (tmp != NULL)
		val = tmp->value;
	while (tmp != NULL)
	{
		if (tmp->value > val)
		{
			val = tmp->value;
			pos = iter;
		}
		iter++;
		tmp = tmp->next;
	}
	return (pos);
}
