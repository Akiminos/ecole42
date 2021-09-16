/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 08:44:48 by bdruez            #+#    #+#             */
/*   Updated: 2021/09/16 23:19:57 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color	get_color_for_pos(int x, int y, t_data *data)
{
	int		iter;
	t_color	color;

	color = init_color();
	iter = 0;
	if (data->fractal_type == MANDELBROT)
	{
		iter = mandelbrot_pixel(x, y, data->view);
		color = mandelbrot_color(iter);
	}
	if (data->fractal_type == JULIA)
	{
		iter = julia_pixel(x, y, data);
		color = julia_color(iter);
	}
	color.color = create_trgb(color.t, color.r, color.g, color.b);
	return (color);
}

int	draw_image(t_data *data)
{
	int				x;
	int				y;
	int				pixel;
	t_color			color;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			color = get_color_for_pos(x, y, data);
			pixel = (y * data->image->size_line) + (x * 4);
			data->image->buffer[pixel + 0] = (color.color) & 0xFF;
			data->image->buffer[pixel + 1] = (color.color >> 8) & 0xFF;
			data->image->buffer[pixel + 2] = (color.color >> 16) & 0xFF;
			data->image->buffer[pixel + 3] = (color.color >> 24) & 0xFF;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->p_mlx, data->p_win, data->image->p_img, 0, 0);
	return (0);
}
