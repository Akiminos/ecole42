/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack_action.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 15:13:35 by bdruez            #+#    #+#             */
/*   Updated: 2021/07/05 17:25:36 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	t_stack_ele	*tmp;
	t_stack_ele	*third;

	if (stack->size < 2)
		return ;
	tmp = stack->head->next;
	third = tmp->next;
	if (third != NULL)
		third->prev = stack->head;
	stack->head->next = third;
	tmp->prev = NULL;
	tmp->next = stack->head;
	stack->head->prev = tmp;
	stack->head = tmp;
}

void	push(t_stack *stack_from, t_stack *stack_to)
{
	int			val;
	t_stack_ele	*ele;

	if (stack_from->size < 1)
		return ;
	val = stack_from->head->value;
	ele = new_stack_ele(val);
	if (stack_from->size > 1)
	{
		stack_from->head = stack_from->head->next;
		free_stack_ele(stack_from->head->prev);
		stack_from->head->prev = NULL;
	}
	else
	{
		free_stack_ele(stack_from->head);
		stack_from->head = NULL;
		stack_from->tail = NULL;
	}
	add_ele_head(stack_to, ele);
	(stack_from->size)--;
}

void	rotate(t_stack *stack)
{
	t_stack_ele	*tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->head;
	stack->head = tmp->next;
	stack->head->prev = NULL;
	stack->tail->next = tmp;
	tmp->prev = stack->tail;
	tmp->next = NULL;
	stack->tail = tmp;
}

void	reverse_rotate(t_stack *stack)
{
	t_stack_ele	*tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->tail;
	stack->tail = tmp->prev;
	stack->tail->next = NULL;
	stack->head->prev = tmp;
	tmp->next = stack->head;
	tmp->prev = NULL;
	stack->head = tmp;
}
