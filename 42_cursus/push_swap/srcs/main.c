/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 15:24:07 by bdruez            #+#    #+#             */
/*   Updated: 2021/09/13 21:28:16 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		status;
	t_stack	*primary;
	t_stack	*secondary;

	status = TRUE;
	primary = NULL;
	if (argc <= 1 || argv == NULL)
		free_and_exit(NULL, NULL, 0);
	else
	{
		primary = create_stack_from_input(argc, argv, &status);
		if (status == FALSE)
			free_and_exit(primary, NULL, 1);
		check_doublons(primary);
		if (is_sorted(primary) == 0)
			free_and_exit(primary, NULL, 0);
		secondary = init_stack();
		solve(primary, secondary);
	}
	return (0);
}
