/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 21:18:51 by bdruez            #+#    #+#             */
/*   Updated: 2021/09/16 22:25:56 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_additional_args(int argc, char **argv, t_data *data)
{
	int	iter;
	int	res;

	if (argc < 3)
		free_and_exit_instruction(&data);
	if (ft_strlen(argv[2]) > 2)
		free_and_exit_instruction(&data);
	iter = 0;
	while (argv[2][iter])
	{
		if (!ft_isdigit(argv[2][iter]))
			free_and_exit_instruction(&data);
		iter++;
	}
	if (iter == 2)
		res = 10 * (argv[2][0] - 48) + (argv[2][1] - 48);
	else
		res = argv[2][0] - 48;
	return (res);
}

int	parse_args(int argc, char **argv, t_data *data)
{
	int res;

	res = 0;
	if (argc < 2)
		free_and_exit_instruction(&data);
	res = set_fractal_name(argv, data);
	if (res == -1)
		free_and_exit_instruction(&data);
	if (data->fractal_type == JULIA)
	{
		res = get_additional_args(argc, argv, data);
		data->range = (double)res;
	}
	return (0);
}

int	set_fractal_name(char **argv, t_data *data)
{
	if (ft_strncmp(argv[1], "mandelbrot", ft_strlen("mandelbrot")) == 0)
	{
		data->fractal_type = MANDELBROT;
		data->win_name = "Fractol : Mandelbrot";
	}
	else if (ft_strncmp(argv[1], "julia", ft_strlen("julia")) == 0)
	{
		data->fractal_type = JULIA;
		data->win_name = "Fractol : Julia";
	}
	else
		return (-1);
	return (0);
}
