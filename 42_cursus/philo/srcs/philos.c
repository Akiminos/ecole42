/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:40:30 by bdruez            #+#    #+#             */
/*   Updated: 2021/11/04 12:46:05 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start_philos(t_philo **philos)
{
	int	iter;
	int	max;

	iter = 0;
	max = philos[0][0].info->param.nb_philo;
	while (iter < max)
	{
		pthread_create(&philos[0][iter].thread, NULL, run,
			(void *)&philos[0][iter]);
		iter++;
	}
	return (0);
}

t_philo	*create_philos(t_info *info)
{
	t_philo	*philos;
	int		iter;

	philos = malloc(sizeof(*philos) * info->param.nb_philo);
	if (philos == NULL)
		return (NULL);
	iter = 0;
	while (iter < info->param.nb_philo)
	{
		philos[iter] = init_philo();
		philos[iter].last_eaten = info->start;
		philos[iter].position = iter;
		pthread_mutex_init(&philos[iter].mutex, NULL);
		philos[iter].info = info;
		iter++;
	}
	return (philos);
}

int	join_philos(t_philo **philos)
{
	int	iter;
	int	max;

	iter = 0;
	max = philos[0][0].info->param.nb_philo;
	while (iter < max)
	{
		pthread_join(philos[0][iter].thread, NULL);
		iter++;
	}
	return (0);
}

void	destroy_philos(t_philo **philos)
{
	int	iter;
	int	max;

	iter = 0;
	max = philos[0][0].info->param.nb_philo;
	while (iter < max)
	{
		destroy_philo(&philos[0][iter]);
		iter++;
	}
}

int	check_philos(t_philo **philos)
{
	int	iter;
	int	max;
	int	ret;

	iter = 0;
	ret = -1;
	max = philos[0][0].info->param.nb_philo;
	pthread_mutex_lock(&(philos[0][0].info->mutex));
	while (iter < max)
	{
		if (check_death(philos[0][iter], philos[0][iter].info) == TRUE)
		{
			ret = iter;
			break ;
		}
		iter++;
	}
	pthread_mutex_unlock(&(philos[0][0].info->mutex));
	return (ret);
}
