/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 12:45:43 by bdruez            #+#    #+#             */
/*   Updated: 2021/11/04 12:39:12 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_fork_taken(t_philo *philo)
{
	struct timeval	time;

	pthread_mutex_lock(&(philo->info->mutex));
	gettimeofday(&time, NULL);
	if (philo->info->should_end != TRUE)
	{
		printf("%ld %d has taken a fork\n",
			get_time_diff_milli(time, philo->info->start), philo->position);
	}
	pthread_mutex_unlock(&(philo->info->mutex));
}

void	print_eating(t_philo *philo)
{
	struct timeval	time;

	pthread_mutex_lock(&(philo->info->mutex));
	gettimeofday(&time, NULL);
	if (philo->info->should_end != TRUE)
	{
		printf("%ld %d is eating\n",
			get_time_diff_milli(time, philo->info->start), philo->position);
	}
	pthread_mutex_unlock(&(philo->info->mutex));
}

void	print_sleeping(t_philo *philo)
{
	struct timeval	time;

	pthread_mutex_lock(&(philo->info->mutex));
	gettimeofday(&time, NULL);
	if (philo->info->should_end != TRUE)
	{
		printf("%ld %d is sleeping\n",
			get_time_diff_milli(time, philo->info->start), philo->position);
	}
	pthread_mutex_unlock(&(philo->info->mutex));
}

void	print_thinking(t_philo *philo)
{
	struct timeval	time;

	pthread_mutex_lock(&(philo->info->mutex));
	gettimeofday(&time, NULL);
	if (philo->info->should_end != TRUE)
	{
		printf("%ld %d is thinking\n",
			get_time_diff_milli(time, philo->info->start), philo->position);
	}
	pthread_mutex_unlock(&(philo->info->mutex));
}

void	print_died(t_philo *philo)
{
	struct timeval	time;

	pthread_mutex_lock(&(philo->info->mutex));
	gettimeofday(&time, NULL);
	printf("%ld %d died\n",
		get_time_diff_milli(time, philo->info->start), philo->position);
	pthread_mutex_unlock(&(philo->info->mutex));
}
