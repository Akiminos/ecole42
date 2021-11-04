/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 12:07:08 by bdruez            #+#    #+#             */
/*   Updated: 2021/11/04 17:53:06 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "limits.h"

int	all_have_eaten(t_philo **philos, t_info *info)
{
	int	iter;
	int	ret;

	iter = 0;
	ret = TRUE;
	if (info->param.nb_times_to_eat == -1)
		return (FALSE);
	while (iter < info->param.nb_philo)
	{
		pthread_mutex_lock(&info->mutex);
		if (philos[0][iter].nb_times_eaten < info->param.nb_times_to_eat)
			ret = FALSE;
		pthread_mutex_unlock(&info->mutex);
		if (ret == FALSE)
			break ;
		iter++;
	}
	return (ret);
}

int	loop(t_philo **philos, t_info *info)
{
	int		ret;

	usleep(WAIT_UTIME);
	ret = check_philos(philos);
	if (ret != -1)
	{
		pthread_mutex_lock(&info->mutex);
		info->should_end = TRUE;
		pthread_mutex_unlock(&info->mutex);
		print_died(&philos[0][ret]);
	}
	if (all_have_eaten(philos, info) == TRUE)
	{
		pthread_mutex_lock(&info->mutex);
		info->should_end = TRUE;
		pthread_mutex_unlock(&info->mutex);
		print_all_eaten(&philos[0][0]);
	}
	return (ret);
}

void	print_elapsed_time(struct timeval start)
{
	struct timeval	current;

	gettimeofday(&current, NULL);
	current = get_time_diff(current, start);
	printf("Time elapsed : %ld.%06ld seconds\n", current.tv_sec,
		current.tv_usec);
}

void	clear_philos(t_philo **philos)
{
	if (philos[0] != NULL)
	{
		join_philos(philos);
		free(philos[0]);
	}
}

int	main(int argc, char **argv)
{
	struct timeval	start;
	t_info			info;
	t_param			param;
	t_philo			*philos;

	gettimeofday(&start, NULL);
	if (argc >= 5 && argc <= 6)
	{
		param = parse_params(argc, argv);
		if (check_invalid_params(param) == 1)
			return (1);
		info = init_info(param, start);
		philos = create_philos(&info);
		if (philos != NULL)
			start_philos(&philos);
		while (info.should_end != TRUE)
			loop(&philos, &info);
		clear_philos(&philos);
		destroy_info(&info);
	}
	else
		printf("Error: Invalid number of arguments\n");
	print_elapsed_time(start);
}
