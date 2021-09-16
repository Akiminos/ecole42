/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 21:02:10 by bdruez            #+#    #+#             */
/*   Updated: 2021/09/16 15:15:29 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void*	init_window(t_data *data)
{
	void	*ptr;

	ptr = mlx_new_window(data->p_mlx, WIN_W, WIN_H, data->win_name);
	return (ptr);
}
