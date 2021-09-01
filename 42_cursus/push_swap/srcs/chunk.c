/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 18:55:31 by bdruez            #+#    #+#             */
/*   Updated: 2021/09/01 17:34:10 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_chunk_max(t_stack *primary, int size)
{
	int		max;
	int		iter;

	max = get_lowest_ele_val(primary);
	iter = 0;
	while (iter < size - 1)
	{
		max = find_value_just_above(primary, max);
		iter++;
	}
	return (max);
}

int		find_value_just_above(t_stack *stack, int current)
{
	int			result;
	int			iter;
	t_stack_ele	*tmp;
	
	tmp = stack->head;
	result = current;
	iter = 0;
	while (result == current && iter < stack->size)
	{
		if (tmp->value > result)
			result = tmp->value;
		tmp = tmp->next;
		iter++;
	}
	while (iter < stack->size)
	{
		if (tmp->value < result && tmp->value > current)
			result = tmp->value;
		tmp = tmp->next;
		iter++;
	}
	return (result);
}

int		find_lowest_weight_pos(t_stack *stack, int chunk_max)
{
	int			pos;
	int			weight;
	int			res_pos;
	int			res_weight;
	t_stack_ele *tmp;

	pos = 0;
	weight = 0;
	res_pos = -1;
	res_weight = stack->size / 2 + 1;
	tmp = stack->head;
	if (tmp->value <= chunk_max)
		return (0);
	while (tmp != NULL)
	{
		weight = get_weight_from_pos(stack, pos);
		if (weight < res_weight && tmp->value <= chunk_max)
		{
			res_pos = pos;
			res_weight = weight;
		}
		pos++;
		tmp = tmp->next;
	}
	return (res_pos);
}

int		get_weight_from_pos(t_stack *stack, int pos)
{
	int		size;

	size = stack->size;
	if (pos <= size / 2)
		return (pos);
	else
		return (size - pos);
}
