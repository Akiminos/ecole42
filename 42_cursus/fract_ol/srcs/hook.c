/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 11:12:57 by bdruez            #+#    #+#             */
/*   Updated: 2021/09/16 23:20:50 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	hook_key_pressed(int key, t_data *data)
{
	if (key == K_ESC)
	{
		free_data(&data);
		exit(EXIT_SUCCESS);
	}
	else if (key == K_O)
		k_o(data);
	else if (key == K_L)
		k_l(data);
	else if (key == K_ENTER)
		k_enter(data);
	else if (key == K_LEFT)
		k_left(data);
	else if (key == K_RIGHT)
		k_right(data);
	else if (key == K_UP)
		k_up(data);
	else if (key == K_DOWN)
		k_down(data);
	draw_image(data);
	return (0);
}

int	hook_mouse(int mouse_input, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (mouse_input == M_WHEEL_UP)
		m_wheel_up(data);
	else if (mouse_input == M_WHEEL_DOWN)
		m_wheel_down(data);
	draw_image(data);
	return (0);
}
