/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_fork.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 12:26:25 by bdruez            #+#    #+#             */
/*   Updated: 2021/11/02 20:42:19 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_fork	init_fork(void)
{
	t_fork	fork;
	int		ret;

	fork.position = 0;
	fork.is_free = TRUE;
	ret = pthread_mutex_init(&fork.mutex, NULL);
	if (ret != 0)
		fork.is_valid = FALSE;
	else
		fork.is_valid = TRUE;
	return (fork);
}

void	destroy_fork(t_fork *fork)
{
	pthread_mutex_destroy(&(fork->mutex));
	fork->position = -1;
	fork->is_free = FALSE;
	fork->is_valid = FALSE;
}
