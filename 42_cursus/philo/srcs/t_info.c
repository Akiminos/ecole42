/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_info.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:51:13 by bdruez            #+#    #+#             */
/*   Updated: 2021/11/04 09:22:30 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_info	init_info(t_param param, struct timeval start)
{
	t_info	info;
	int		iter;

	info.should_end = FALSE;
	info.param = param;
	info.start = start;
	pthread_mutex_init(&info.mutex, NULL);
	info.forks = malloc(sizeof(*info.forks) * param.nb_philo);
	if (info.forks != NULL)
	{
		iter = 0;
		while (iter < param.nb_philo)
		{
			info.forks[iter] = init_fork();
			info.forks[iter].position = iter;
			iter++;
		}
	}
	return (info);
}

void	destroy_info(t_info *info)
{
	int	iter;

	iter = 0;
	while (iter < info->param.nb_philo)
	{
		destroy_fork(&(info->forks[iter]));
		iter++;
	}
	if (info->forks != NULL)
		free(info->forks);
	pthread_mutex_destroy(&(info->mutex));
}
