/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 13:54:19 by bdruez            #+#    #+#             */
/*   Updated: 2021/09/17 00:22:53 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_and_exit(t_stack *stack_a, t_stack *stack_b, int error_code)
{
	if (stack_a != NULL)
		free_stack(stack_a);
	if (stack_b != NULL)
		free_stack(stack_b);
	if (error_code != 0)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	else
		exit(EXIT_SUCCESS);
}
