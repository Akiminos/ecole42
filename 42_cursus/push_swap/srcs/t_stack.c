/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:38:52 by bdruez            #+#    #+#             */
/*   Updated: 2021/07/05 15:07:23 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(void)
{
	t_stack *stack;

	stack = malloc(sizeof(*stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
	return (stack);
}

void	add_ele_head(t_stack *stack, t_stack_ele *ele)
{
	if (stack->size == 0)
	{
		stack->head = ele;
		stack->tail = ele;
		(stack->size)++;
	}
	else
	{
		ele->next = stack->head;
		stack->head->prev = ele;
		stack->head = ele;
		(stack->size)++;
	}
}

void	add_ele_tail(t_stack *stack, t_stack_ele *ele)
{
	if (stack->size == 0)
	{
		stack->head = ele;
		stack->tail = ele;
		(stack->size)++;
	}
	else
	{
		ele->prev = stack->tail;
		stack->tail->next = ele;
		stack->tail = ele;
		(stack->size)++;
	}
}

void	print_stack(t_stack *stack)
{
	int			iter;
	t_stack_ele	*tmp;

	iter = 0;
	tmp = stack->head;
	while (iter < stack->size)
	{
		printf("%d\n", tmp->value);
		tmp = tmp->next;
		iter++;
	}
}

void	free_stack(t_stack *stack)
{
	int			iter;
	t_stack_ele	*tmp_curr;
	t_stack_ele	*tmp_prev;

	iter = 0;
	tmp_curr = stack->tail;
	tmp_prev = NULL;
	while (iter < stack->size)
	{
		tmp_prev = tmp_curr->prev;
		free_stack_ele(tmp_curr);
		tmp_curr = tmp_prev;
		iter++;
	}
	tmp_curr = NULL;
	tmp_prev = NULL;
	stack->head = NULL;
	stack->tail = NULL;
	free(stack);
	stack = NULL;
}
