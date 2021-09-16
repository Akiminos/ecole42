/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 18:11:54 by bdruez            #+#    #+#             */
/*   Updated: 2021/09/16 18:39:29 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	k_left(t_data *data)
{
	data->view->x_off -= 0.2f * data->view->zoom;
	return (0);
}

int	k_right(t_data *data)
{
	data->view->x_off += 0.2f * data->view->zoom;
	return (0);
}

int	k_up(t_data *data)
{
	data->view->y_off -= 0.2f * data->view->zoom;
	return (0);
}

int	k_down(t_data *data)
{
	data->view->y_off += 0.2f * data->view->zoom;
	return (0);
}
