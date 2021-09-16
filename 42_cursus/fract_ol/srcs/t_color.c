/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_color.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 11:20:44 by bdruez            #+#    #+#             */
/*   Updated: 2021/09/16 12:24:29 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color	init_color(void)
{
	t_color	color;
	color.t = 0;
	color.r = 0;
	color.r_prime = 0.0f;
	color.g = 0;
	color.g_prime = 0.0f;
	color.b = 0;
	color.b_prime = 0.0f;
	color.c = 0.0f;
	color.x = 0.0f;
	color.m = 0.0f;
	color.h = 0;
	color.s = 0;
	color.v = 0;
	color.color = 0;
	return (color);
}
