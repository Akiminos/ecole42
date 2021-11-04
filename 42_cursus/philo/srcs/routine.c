/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:32:31 by bdruez            #+#    #+#             */
/*   Updated: 2021/11/04 12:49:49 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_grab_forks(t_philo *philo)
{
	if (philo->info->param.nb_philo <= 1)
		return (FALSE);
	lock_forks(philo);
	pthread_mutex_lock(&(philo->info->mutex));
	gettimeofday(&philo->last_eaten, NULL);
	pthread_mutex_unlock(&(philo->info->mutex));
	philo->is_thinking = FALSE;
	philo->is_eating = TRUE;
	print_eating(philo);
	return (TRUE);
}

int	philo_eat(t_philo *philo)
{
	struct timeval	time;
	int				pos_left;
	int				pos_right;

	if (philo->position == 0)
		pos_left = philo->info->param.nb_philo - 1;
	else
		pos_left = philo->position - 1;
	pos_right = philo->position;
	gettimeofday(&time, NULL);
	if (get_time_diff_milli(time, philo->last_eaten)
		>= philo->info->param.time_to_eat)
	{
		pthread_mutex_lock(&philo->info->mutex);
		pthread_mutex_unlock(&philo->info->forks[pos_left].mutex);
		pthread_mutex_unlock(&philo->info->forks[pos_right].mutex);
		philo->is_eating = FALSE;
		philo->is_sleeping = TRUE;
		philo->info->forks[pos_left].is_free = TRUE;
		philo->info->forks[pos_right].is_free = TRUE;
		pthread_mutex_unlock(&philo->info->mutex);
		philo->nb_times_eaten++;
		print_sleeping(philo);
	}
	return (0);
}

int	philo_sleep(t_philo *philo)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	if (get_time_diff_milli(time, philo->last_eaten)
		>= philo->info->param.time_to_eat + philo->info->param.time_to_sleep)
	{
		philo->is_sleeping = FALSE;
		philo->is_thinking = TRUE;
		print_thinking(philo);
	}
	return (0);
}

int	routine(t_philo *philo)
{
	if (philo->is_thinking == TRUE)
		philo_grab_forks(philo);
	else if (philo->is_eating == TRUE)
		philo_eat(philo);
	else if (philo->is_sleeping == TRUE)
		philo_sleep(philo);
	return (0);
}
