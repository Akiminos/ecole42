/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_color.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 14:50:53 by bdruez            #+#    #+#             */
/*   Updated: 2021/02/16 18:22:40 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_cube3d.h"

void	c_red(void)
{
	printf("\x1b[31m");
}

void	c_green(void)
{
	printf("\x1b[32m");
}

void	c_yellow(void)
{
	printf("\x1b[33m");
}

void	c_blue(void)
{
	printf("\x1b[34m");
}

void	c_magenta(void)
{
	printf("\x1b[35m");
}

void	c_cyan(void)
{
	printf("\x1b[36m");
}

void	c_reset(void)
{
	printf("\x1b[0m");
}

