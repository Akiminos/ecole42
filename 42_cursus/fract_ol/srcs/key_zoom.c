/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_zoom.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:58:46 by bdruez            #+#    #+#             */
/*   Updated: 2021/09/16 22:35:36 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	k_o(t_data *data)
{
	data->view->zoom *= 0.8f;
	data->view->x_off += (data->view->x_max - data->view->x_min) / 8
							* data->view->zoom;
	data->view->y_off += (data->view->y_max - data->view->y_min) / 8
							* data->view->zoom;
	return (0);
}

int	k_l(t_data *data)
{
	if (data->view->zoom < 2.0f)
	{
		data->view->x_off -= (data->view->x_max - data->view->x_min) / 8
								* data->view->zoom;
		data->view->y_off -= (data->view->y_max - data->view->y_min) / 8
								* data->view->zoom;
		data->view->zoom /= 0.8f;
	}
	return (0);
}

int	k_enter(t_data *data)
{
	reset_view(data->view);
	if (data->fractal_type == MANDELBROT)
		get_mandelbrot_view(data->view);
	if (data->fractal_type == JULIA)
		get_julia_view(data->view);
	return (0);
}
