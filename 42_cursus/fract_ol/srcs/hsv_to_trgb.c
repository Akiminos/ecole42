/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hsv_to_trgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 11:18:41 by bdruez            #+#    #+#             */
/*   Updated: 2021/09/16 13:07:42 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_conversion_variables(t_color *color)
{
	color->c = color->v * color->s;
	color->x = color->c * (1.0f - fabs(fmod((color->h / 60.0f), 2.0f) - 1.0f));
	color->m = color->v - color->c;
}

void	set_prime_variables_bis(t_color *color)
{
	if (color->h >= 240 && color->h < 300)
	{
		color->b_prime = color->c;
		color->r_prime = color->x;
	}
	else if (color->h >= 300 && color->h < 360)
	{
		color->r_prime = color->c;
		color->b_prime = color->x;
	}
}

void	set_prime_variables(t_color *color)
{
	if (color->h >= 0 && color->h < 60)
	{
		color->r_prime = color->c;
		color->g_prime = color->x;
	}
	else if (color->h >= 60 && color->h < 120)
	{
		color->g_prime = color->c;
		color->r_prime = color->x;
	}
	else if (color->h >= 120 && color->h < 180)
	{
		color->g_prime = color->c;
		color->b_prime = color->x;
	}
	else if (color->h >= 180 && color->h < 240)
	{
		color->b_prime = color->c;
		color->g_prime = color->x;
	}
	else
		set_prime_variables_bis(color);
}

void	set_rgb_variables(t_color *color)
{
	color->r = (int)((color->r_prime + color->m) * 255.0f);
	color->g = (int)((color->g_prime + color->m) * 255.0f);
	color->b = (int)((color->b_prime + color->m) * 255.0f);
}

void	hsv_to_trgb(t_color *color)
{
	set_conversion_variables(color);
	set_prime_variables(color);
	set_rgb_variables(color);
}
