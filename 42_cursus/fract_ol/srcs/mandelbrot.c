/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:52:35 by bdruez            #+#    #+#             */
/*   Updated: 2021/09/24 15:07:03 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot_pixel(int x, int y, t_view *view)
{
	t_complex	z;
	t_complex	c;
	t_complex	tmp;
	int			iter;

	iter = 0;
	z = get_complex_value(x, y, view);
	c = get_complex_value(x, y, view);
	while (z.rl * z.rl + z.im * z.im < DIV_VAL & iter < MAX_ITER)
	{
		tmp.rl = z.rl * z.rl - z.im * z.im + c.rl;
		tmp.im = 2 * z.rl * z.im + c.im;
		if (z.rl == tmp.rl && z.im == tmp.im)
		{
			iter = MAX_ITER;
			break ;
		}
		z.rl = tmp.rl;
		z.im = tmp.im;
		iter++;
	}
	return (iter);
}

void	get_mandelbrot_view(t_view *view)
{
	view->x_min = -2.0f;
	view->x_max = 1.0f;
	view->y_min = -1.0f;
	view->y_max = 1.0f;
	view->x_off = -0.5f;
}

t_color	mandelbrot_color(int iter)
{
	t_color	color;

	color = init_color();
	color.s = 1.0f;
	color.v = 1.0f;
	if (iter == MAX_ITER)
		return (color);
	if (iter < 1)
		return (color);
	color.h = fmod(((double)iter * COLOR_SCALING), 360.0f);
	hsv_to_trgb(&color);
	return (color);
}
