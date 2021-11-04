/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 12:42:58 by bdruez            #+#    #+#             */
/*   Updated: 2021/11/03 16:00:43 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*run(void *philo)
{
	t_philo	*p_philo;

	p_philo = (t_philo *)philo;
	while (p_philo->info->should_end != TRUE)
	{
		routine(p_philo);
		usleep(WAIT_UTIME);
	}
	destroy_philo(p_philo);
	return (NULL);
}
