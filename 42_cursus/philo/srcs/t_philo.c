/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_philo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 12:31:19 by bdruez            #+#    #+#             */
/*   Updated: 2021/11/04 15:34:27 by bdruez           ###   ########.fr       */
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
	pthread_mutex_lock(&(philo->info->mutex));
	if (philo->is_eating == TRUE)
		unlock_forks(philo);
	pthread_mutex_unlock(&(philo->info->mutex));
	pthread_mutex_destroy(&philo->mutex);
}
