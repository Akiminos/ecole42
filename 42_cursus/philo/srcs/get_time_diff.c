/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time_diff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 13:04:06 by bdruez            #+#    #+#             */
/*   Updated: 2021/11/02 13:41:36 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

struct timeval	get_time_diff(struct timeval time, struct timeval time_to_sub)
{
	struct timeval	res;

	res.tv_sec = time.tv_sec - time_to_sub.tv_sec;
	res.tv_usec = time.tv_usec - time_to_sub.tv_usec;
	if (res.tv_usec < 0)
	{
		res.tv_sec--;
		res.tv_usec += 1000000;
	}
	return (res);
}

long int	get_time_diff_milli(struct timeval time, struct timeval time_to_sub)
{
	long int		res;
	struct timeval	time_diff;

	time_diff = get_time_diff(time, time_to_sub);
	res = 0;
	res += time_diff.tv_sec * 1000;
	res += time_diff.tv_usec / 1000;
	return (res);
}
