/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more_than_hundred.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 17:45:18 by bdruez            #+#    #+#             */
/*   Updated: 2021/09/12 18:02:15 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		sort_more_than_hundred(t_stack *primary, t_stack *secondary)
{
	int		chunk_size;

	chunk_size = primary->size / 12;
	while (primary->size > chunk_size)
		sort_chunk(primary, secondary, get_chunk_max(primary, chunk_size));
	sort_chunk(primary, secondary, get_chunk_max(primary, primary->size));
	move_element_at_pos(secondary, find_highest_value_pos(secondary), 'b');
	while (secondary->size > 0)
	{
		push(secondary, primary);
		ft_putstr_fd("pa\n", 1);
	}
	free_stack(primary);
	free_stack(secondary);
	return (0);
}
