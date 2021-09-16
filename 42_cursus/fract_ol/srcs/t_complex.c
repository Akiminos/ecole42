/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_complex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:22:19 by bdruez            #+#    #+#             */
/*   Updated: 2021/09/16 20:36:38 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	get_complex_value(int x, int y, t_view *view)
{
	t_complex	c;

	c.rl = (((double)x / WIN_W) * (view->x_max - view->x_min)) * view->zoom
				+ view->x_min + view->x_off;
	c.im = (((double)y / WIN_H) * (view->y_max - view->y_min)) * view->zoom
				+ view->y_min + view->y_off;
	return (c);
}

t_complex	get_complex_from_angle(double angle)
{
	t_complex	c;

	c.rl = cos(angle);
	c.im = sin(angle);
	return (c);
}
