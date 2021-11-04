/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 12:42:58 by bdruez            #+#    #+#             */
/*   Updated: 2021/11/04 14:51:14 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_should_end(t_philo *philo)
{
	int	ret;

	pthread_mutex_lock(&(philo->info->mutex));
	ret = philo->info->should_end;
	pthread_mutex_unlock(&(philo->info->mutex));
	return (ret);
}

void	*run(void *philo)
{
	t_philo	*p_philo;

	p_philo = (t_philo *)philo;
	while (check_should_end(p_philo) != TRUE)
	{
		routine(p_philo);
		usleep(WAIT_UTIME);
	}
	destroy_philo(p_philo);
	return (NULL);
}
