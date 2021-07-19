/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack_ele.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 15:54:11 by bdruez            #+#    #+#             */
/*   Updated: 2021/07/05 14:10:24 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_ele	*new_stack_ele(int value)
{
	t_stack_ele	*node;

	node = NULL;
	node = malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->value = value;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void		free_stack_ele(t_stack_ele *stack_ele)
{
	if (stack_ele != NULL)
	{
		stack_ele->value = 0;
		stack_ele->prev = NULL;
		stack_ele->next = NULL;
		free(stack_ele);
		stack_ele = NULL;
	}
}
