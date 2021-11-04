/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 20:37:45 by bdruez            #+#    #+#             */
/*   Updated: 2021/11/04 10:12:39 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	lock_forks(t_philo *philo)
{
	int	pos_left;

	if (philo->position == 0)
		pos_left = philo->info->param.nb_philo - 1;
	else
		pos_left = philo->position - 1;
	pthread_mutex_lock(&philo->info->forks[philo->position].mutex);
	print_fork_taken(philo);
	pthread_mutex_lock(&philo->info->forks[pos_left].mutex);
	print_fork_taken(philo);
	return (TRUE);
}
