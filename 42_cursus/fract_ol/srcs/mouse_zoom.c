/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_zoom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 22:43:59 by bdruez            #+#    #+#             */
/*   Updated: 2021/09/16 22:46:09 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	m_wheel_up(t_data *data)
{
	data->view->zoom *= 0.8f;                                                   
	data->view->x_off += (data->view->x_max - data->view->x_min) / 8            
		* data->view->zoom;                                 
	data->view->y_off += (data->view->y_max - data->view->y_min) / 8            
		* data->view->zoom;                                 
	return (0);
}

int	m_wheel_down(t_data *data)
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
