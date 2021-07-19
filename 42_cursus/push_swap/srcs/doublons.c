/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doublons.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 16:04:01 by bdruez            #+#    #+#             */
/*   Updated: 2021/07/19 12:00:13 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		check_doublons(t_stack *stack)
{
	int		*array;
	int		bool_has_doublons;

	array = create_int_array(stack, stack->size);
	bool_has_doublons = has_doublons(array, stack->size);
	if (array != NULL)
		free(array);
	array = NULL;
	if (bool_has_doublons == TRUE)
		free_and_exit_message(stack, NULL, "Input has doublons");
}

int			*create_int_array(t_stack *stack, int length)
{
	int			*array;
	int			iter;
	t_stack_ele	*ele;

	ele = stack->head;
	iter = 0;
	array = ft_calloc(sizeof(*array), length);
	if (array == NULL)
		free_and_exit_message(stack, NULL, "Allocation error");
	while (iter < length)
	{
		array[iter] = ele->value;
		ele = ele->next;
		iter++;
	}
	return (array);
}

int			has_doublons(int *array, int length)
{
	int		tmp;
	int		iter_array;
	int		iter_check;

	iter_array = 0;
	while (iter_array < length)
	{
		iter_check = iter_array + 1;
		tmp = array[iter_array];
		while (iter_check < length)
		{
			if (tmp == array[iter_check])
				return (TRUE);
			iter_check++;
		}
		iter_array++;
	}
	return (FALSE);
}
