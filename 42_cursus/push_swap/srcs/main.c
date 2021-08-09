/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 15:24:07 by bdruez            #+#    #+#             */
/*   Updated: 2021/08/06 19:33:52 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	int		status;
	t_stack	*stack;

	status = TRUE;
	stack = NULL;
	if (argc <= 1 || argv == NULL)
		free_and_exit_message(NULL, NULL, "Not enough arguments");
	else
	{
		stack = create_stack_from_input(argc, argv, &status);
		if (status == FALSE)
		{
			free_and_exit_message(stack, NULL, "Parsing error");
		}
		else
		{
			print_stack(stack);
			check_doublons(stack);
			printf("lower element position : '%d'\n",
				get_lowest_ele_pos(stack));
			free_stack(stack);
		}
	}
	return (0);
}
