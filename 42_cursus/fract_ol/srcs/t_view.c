/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_view.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:34:34 by bdruez            #+#    #+#             */
/*   Updated: 2021/09/17 12:20:31 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_view	*init_view(void)
{
	t_view	*view;

	view = ft_calloc(sizeof(t_view), 1);
	if (view == NULL)
		return (NULL);
	view->x_min = 0.0f;
	view->x_max = 0.0f;
	view->x_off = 0.0f;
	view->y_min = 0.0f;
	view->y_max = 0.0f;
	view->y_off = 0.0f;
	view->zoom = 1.0f;
	return (view);
}

t_view	*new_view(t_data *data)
{
	t_view	*view;

	view = init_view();
	if (view == NULL)
		return (NULL);
	if (data->fractal_type == MANDELBROT)
		get_mandelbrot_view(view);
	else if (data->fractal_type == JULIA)
		return (view);
	return (view);
}

void	delete_view(t_data *data)
{
	if (data->view != NULL)
		free(data->view);
}

void	reset_view(t_view *view)
{
	view->x_min = 0.0f;
	view->x_max = 0.0f;
	view->x_off = 0.0f;
	view->y_min = 0.0f;
	view->y_max = 0.0f;
	view->y_off = 0.0f;
	view->zoom = 1.0f;
}
