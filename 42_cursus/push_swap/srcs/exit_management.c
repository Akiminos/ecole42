/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 13:54:19 by bdruez            #+#    #+#             */
/*   Updated: 2021/07/19 13:02:54 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_and_exit(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a != NULL)
		free_stack(stack_a);
	if (stack_b != NULL)
		free_stack(stack_b);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	free_and_exit_message(t_stack *stack_a, t_stack *stack_b,
		const char* message)
{
	if (stack_a != NULL)
		free_stack(stack_a);
	if (stack_b != NULL)
		free_stack(stack_b);
	write(2, "ERROR : ", 8);
	write(2, message, ft_strlen(message));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}
