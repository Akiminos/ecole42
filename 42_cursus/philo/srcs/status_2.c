/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:34:45 by bdruez            #+#    #+#             */
/*   Updated: 2021/11/04 12:37:19 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_all_eaten(t_philo *philo)
{
	struct timeval	time;

	pthread_mutex_lock(&(philo->info->mutex));
	gettimeofday(&time, NULL);
	printf("%ld All philos have eaten %d times\n",
		get_time_diff_milli(time, philo->info->start),
		philo->info->param.nb_times_to_eat);
	pthread_mutex_unlock(&(philo->info->mutex));
}
