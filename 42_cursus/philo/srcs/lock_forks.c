/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 20:37:45 by bdruez            #+#    #+#             */
/*   Updated: 2021/11/04 17:51:30 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	unlock_forks(t_philo *philo)
{
	int	pos_left;

	if (philo->position == 0)
		pos_left = philo->info->param.nb_philo - 1;
	else
		pos_left = philo->position - 1;
	if (philo->position % 2 == 1)
	{
		pthread_mutex_unlock(&philo->info->forks[philo->position].mutex);
		pthread_mutex_unlock(&philo->info->forks[pos_left].mutex);
	}
	else
	{
		pthread_mutex_unlock(&philo->info->forks[pos_left].mutex);
		pthread_mutex_unlock(&philo->info->forks[philo->position].mutex);
	}
	return (TRUE);
}

int	lock_forks(t_philo *philo)
{
	int	pos_left;

	if (philo->position == 0)
		pos_left = philo->info->param.nb_philo - 1;
	else
		pos_left = philo->position - 1;
	if (philo->position % 2 == 0)
	{
		usleep(1000);
		pthread_mutex_lock(&philo->info->forks[philo->position].mutex);
		print_fork_taken(philo);
		pthread_mutex_lock(&philo->info->forks[pos_left].mutex);
		print_fork_taken(philo);
	}
	else
	{
		pthread_mutex_lock(&philo->info->forks[pos_left].mutex);
		print_fork_taken(philo);
		pthread_mutex_lock(&philo->info->forks[philo->position].mutex);
		print_fork_taken(philo);
	}
	return (TRUE);
}
