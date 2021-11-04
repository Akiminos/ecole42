/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:00:30 by bdruez            #+#    #+#             */
/*   Updated: 2021/11/02 16:52:40 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philo philo, t_info *info)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	if (get_time_diff_milli(time, philo.last_eaten) < info->param.time_to_die)
		return (FALSE);
	else
		return (TRUE);
}
