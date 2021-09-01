/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 19:14:39 by bdruez            #+#    #+#             */
/*   Updated: 2021/08/31 20:14:52 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_lowest_ele_pos(t_stack *stack)
{
	int			pos;
	int			value;
	int			iter;
	t_stack_ele	*tmp;

	pos = 0;
	iter = 1;
	if (stack->size < 1)
		return (-1);
	tmp = stack->head;
	value = tmp->value;
	while (iter < stack->size)
	{
		tmp = tmp->next;
		if (tmp->value < value)
		{
			value = tmp->value;
			pos = iter;
		}
		iter++;
	}
	return (pos);
}

int		get_highest_ele_pos(t_stack *stack)
{
	int			pos;
	int			value;
	int			iter;
	t_stack_ele	*tmp;

	pos = 0;
	iter = 1;
	if (stack->size < 1)
		return (-1);
	tmp = stack->head;
	value = tmp->value;
	while (iter < stack->size)
	{
		tmp = tmp->next;
		if (tmp->value > value)
		{
			value = tmp->value;
			pos = iter;
		}
		iter++;
	}
	return (pos);
}

int		get_lowest_ele_val(t_stack *stack)
{
	int			value;
	int			iter;
	t_stack_ele	*tmp;

	iter = 1;
	if (stack->size == 1)
		return (stack->head->value);
	else if (stack->size < 1)
		return (-1);
	tmp = stack->head;
	value = tmp->value;
	while (iter < stack->size)
	{
		if (value > tmp->next->value)
			value = tmp->next->value;
		tmp = tmp->next;
		iter++;
	}
	return (value);
}

int		get_highest_ele_val(t_stack *stack)
{
	int			value;
	int			iter;
	t_stack_ele	*tmp;

	iter = 1;
	if (stack->size == 1)
		return (stack->head->value);
	else if (stack->size < 1)
		return (-1);
	tmp = stack->head;
	value = tmp->value;
	while (iter < stack->size)
	{
		if (value < tmp->next->value)
			value = tmp->next->value;
		tmp = tmp->next;
		iter++;
	}
	return (value);
}
