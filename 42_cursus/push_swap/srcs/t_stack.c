/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:38:52 by bdruez            #+#    #+#             */
/*   Updated: 2021/07/01 18:35:06 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_stack(int value)
{
	t_stack	*node;

	node = NULL;
	node = malloc(sizeof(*node));
	if (!node)
		return (0);
	node->value = value;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

int		stack_size(t_stack *ele)
{
	int	res;

	res = 0;
	while (ele)
	{
		ele = ele->next;
		res++;
	}
	return (res);
}

void	rotate(t_stack *head)
{
	(void)head;
}

void	r_rotate(t_stack *tail)
{
	(void)tail;
}

