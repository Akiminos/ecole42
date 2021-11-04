/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 12:08:12 by bdruez            #+#    #+#             */
/*   Updated: 2021/11/04 15:34:46 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

//----- Defines --------------------------------------------------------------//
# define TRUE 0
# define FALSE 1

# define WAIT_UTIME 500

//----- Enums ----------------------------------------------------------------//

//----- Structures -----------------------------------------------------------//
typedef struct s_fork
{
	int				is_valid;
	int				is_free;
	int				position;
	pthread_mutex_t	mutex;
}	t_fork;

typedef struct s_param
{
	int			nb_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			nb_times_to_eat;
}	t_param;

typedef struct s_info
{
	struct timeval	start;
	t_fork			*forks;
	t_param			param;
	int				should_end;
	pthread_mutex_t	mutex;
}	t_info;

typedef struct s_philo
{
	struct timeval	last_eaten;
	int				is_done;
	int				is_eating;
	int				is_sleeping;
	int				is_thinking;
	int				position;
	int				nb_times_eaten;
	t_info			*info;
	pthread_t		thread;
	pthread_mutex_t	mutex;
}	t_philo;

//----- Functions ------------------------------------------------------------//

//----------------------------------------------------------------------------//
//----- check_death.c --------------------------------------------------------//
int				check_death(t_philo philo, t_info *info);
//----- get_time_diff.c ------------------------------------------------------//
struct timeval	get_time_diff(struct timeval time, struct timeval time_to_sub);
long int		get_time_diff_milli(struct timeval time,
					struct timeval time_to_sub);
//----- lock_forks.c ---------------------------------------------------------//
int				unlock_forks(t_philo *philo);
int				lock_forks(t_philo *philo);
//----- parser.c -------------------------------------------------------------//
t_param			parse_params(int argc, char **argv);
//----- philos.c -------------------------------------------------------------//
int				start_philos(t_philo **philos);
t_philo			*create_philos(t_info *info);
int				join_philos(t_philo **philos);
void			destroy_philos(t_philo **philos);
int				check_philos(t_philo **philos);
//----- routine.c ------------------------------------------------------------//
int				routine(t_philo *philo);
//----- run.c ----------------------------------------------------------------//
void			*run(void *info);
//----- status.c -------------------------------------------------------------//
void			print_fork_taken(t_philo *philo);
void			print_eating(t_philo *philo);
void			print_sleeping(t_philo *philo);
void			print_thinking(t_philo *philo);
void			print_died(t_philo *philo);
//----- status_2.c -----------------------------------------------------------//
void			print_all_eaten(t_philo *philo);
//----- t_fork.c -------------------------------------------------------------//
t_fork			init_fork(void);
void			destroy_fork(t_fork *fork);
//----- t_info.c -------------------------------------------------------------//
t_info			init_info(t_param param, struct timeval start);
void			destroy_info(t_info *info);
//----- t_param.c ------------------------------------------------------------//
t_param			init_param(void);
int				check_invalid_params(t_param param);
void			destroy_param(t_param *param);
//----- t_philo.c ------------------------------------------------------------//
t_philo			init_philo(void);
t_philo			create_philo(int pos, t_info *info);
void			destroy_philo(t_philo *philo);
//----- utils.c --------------------------------------------------------------//
int				ft_strlen(char *str);
int				ft_isdigit(char chr);
int				is_number(char *number);
int				is_valid_integer(char *number);
int				ascii_to_integer(char *number);
//----------------------------------------------------------------------------//

#endif
