/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:23:27 by bdruez            #+#    #+#             */
/*   Updated: 2021/09/17 00:24:57 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	init(t_data *data)
{
	data->p_mlx = mlx_init();
	if (data->p_mlx == NULL)
		return (-1);
	data->p_win = init_window(data);
	if (data->p_win == NULL)
		return (-1);
	data->image = new_image(data);
	if (data->image == NULL)
		return (-1);
	data->view = new_view(data);
	if (data->view == NULL)
		return (-1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data *data;

	data = init_data();
	parse_args(argc, argv, data);
	if (init(data) != 0)
		free_and_exit(&data, "Could not initialize mlx properly", -1);
	draw_image(data);
	mlx_key_hook(data->p_win, hook_key_pressed, data);
	mlx_mouse_hook(data->p_win, hook_mouse, data);
	mlx_loop(data->p_mlx);
	free_data(&data);
	return (0);
}
