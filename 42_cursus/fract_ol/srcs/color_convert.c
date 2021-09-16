/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_convert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 09:36:30 by bdruez            #+#    #+#             */
/*   Updated: 2021/09/15 09:44:02 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int get_t(int trgb)
{
	return (trgb & (0xFF << 24));
}


int get_r(int trgb)
{
	return (trgb & (0xFF << 16));
}

int get_g(int trgb)
{
	return (trgb & (0xFF << 8));
}

int get_b(int trgb)
{
	return (trgb & 0xFF);
}
