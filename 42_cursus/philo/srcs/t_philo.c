/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_philo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 12:31:19 by bdruez            #+#    #+#             */
/*   Updated: 2021/11/04 12:34:12 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	init_philo(void)
{
	t_philo	philo;

	philo.thread = 0;
	philo.is_eating = FALSE;
	philo.is_sleeping = FALSE;
	philo.is_thinking = TRUE;
	philo.position = 0;
	philo.nb_times_eaten = 0;
	philo.info = NULL;
	philo.thread = 0;
	return (philo);
}

t_philo	create_philo(int pos, t_info *info)
{
	t_philo	philo;

	philo = init_philo();
	philo.position = pos;
	philo.info = info;
	return (philo);
}

void	destroy_philo(t_philo *philo)
{
	int	left;
	int	right;

	right = philo->position;
	if (philo->position == 0)
		left = philo->info->param.nb_philo - 1;
	else
		left = philo->position - 1;
	if (philo->is_eating == TRUE)
	{
		pthread_mutex_unlock(&philo->info->forks[left].mutex);
		pthread_mutex_unlock(&philo->info->forks[right].mutex);
	}
	pthread_mutex_destroy(&philo->mutex);
}
