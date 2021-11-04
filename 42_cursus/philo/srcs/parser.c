/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:40:05 by bdruez            #+#    #+#             */
/*   Updated: 2021/11/04 12:21:10 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_parsable_as_integer(char *number)
{
	if (is_number(number) == FALSE)
		return (FALSE);
	if (is_valid_integer(number) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	check_param(t_param *param, int argc)
{
	if (param->nb_philo < 1)
		param->nb_philo = -1;
	if (param->time_to_die < 1)
		param->nb_philo = -1;
	if (param->time_to_eat < 1)
		param->nb_philo = -1;
	if (param->time_to_sleep < 1)
		param->nb_philo = -1;
	if (argc == 6)
	{
		if (param->nb_times_to_eat < 1)
			param->nb_philo = -1;
	}
	else
		param->nb_times_to_eat = -1;
	return (0);
}

t_param	parse_params(int argc, char **argv)
{
	t_param	param;

	param = init_param();
	if (is_parsable_as_integer(argv[1]) == TRUE)
		param.nb_philo = ascii_to_integer(argv[1]);
	if (is_parsable_as_integer(argv[2]) == TRUE)
		param.time_to_die = ascii_to_integer(argv[2]);
	if (is_parsable_as_integer(argv[3]) == TRUE)
		param.time_to_eat = ascii_to_integer(argv[3]);
	if (is_parsable_as_integer(argv[4]) == TRUE)
		param.time_to_sleep = ascii_to_integer(argv[4]);
	if (argc == 6 && is_parsable_as_integer(argv[5]) == TRUE)
		param.nb_times_to_eat = ascii_to_integer(argv[5]);
	check_param(&param, argc);
	return (param);
}
