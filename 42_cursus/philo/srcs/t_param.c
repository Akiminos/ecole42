/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_param.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 12:24:28 by bdruez            #+#    #+#             */
/*   Updated: 2021/11/04 12:29:38 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_param	init_param(void)
{
	t_param	param;

	param.nb_philo = -1;
	param.time_to_die = -1;
	param.time_to_eat = -1;
	param.time_to_sleep = -1;
	param.nb_times_to_eat = -2;
	return (param);
}

int	check_invalid_params(t_param param)
{
	if (param.nb_philo == -1)
	{
		printf("Error: Invalid arguments\n");
		return (1);
	}
	else
		return (0);
}

void	destroy_param(t_param *param)
{
	param->nb_philo = -1;
	param->time_to_die = -1;
	param->time_to_eat = -1;
	param->time_to_sleep = -1;
	param->nb_times_to_eat = -1;
}
