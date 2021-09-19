/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_data.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 21:04:55 by bdruez            #+#    #+#             */
/*   Updated: 2021/09/19 23:40:19 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_data	*init_data(void)
{
	t_data	*data;
	
	data = ft_calloc(sizeof(t_data), 1);
	if (data == NULL)
		return (NULL);
	data->fractal_type = -1;
	data->range = 0.0f;
	data->p_mlx = NULL;
	data->p_win = NULL;
	data->win_name = "";
	data->image = NULL;
	data->view = NULL;
	return (data);
}

void	free_data(t_data **data)
{
	if (*data != NULL)
	{
		if ((*data)->image != NULL)
			delete_image(*data);
		if ((*data)->view != NULL)
			delete_view(*data);
		if ((*data)->p_win != NULL)
			mlx_destroy_window((*data)->p_mlx, (*data)->p_win);
		if ((*data)->p_mlx != NULL)
			mlx_destroy_display((*data)->p_mlx);
		free((*data)->p_mlx);
		free(*data);
	}
}
