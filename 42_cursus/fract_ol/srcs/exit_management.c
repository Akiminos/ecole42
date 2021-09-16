/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 21:21:45 by bdruez            #+#    #+#             */
/*   Updated: 2021/09/16 21:50:42 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	free_and_exit(t_data **data, char *error_msg, int error_code)
{
	free_data(data);
	ft_putstr_fd("Error : ", 2);
	ft_putstr_fd(error_msg, 2);
	ft_putstr_fd("\n", 2);
	exit(error_code);
}

void	free_and_exit_instruction(t_data **data)
{
	free_data(data);
	ft_putstr_fd("Usage : ./fractol mandelbrot\n", 1);
	ft_putstr_fd("     OR ./fractol julia [NBR] (NBR from 0 to 99)\n", 1);
	exit(EXIT_SUCCESS);
}
