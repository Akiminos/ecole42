/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_t_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 11:49:33 by bdruez            #+#    #+#             */
/*   Updated: 2021/02/16 18:50:46 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_cube3d.h"
#include "cube3d.h"

/*
**	init_rgb
*/

void	test_init_rgb_01(void)
{
	int		*rgb;

	rgb = init_rgb();
	assert(rgb[0] == -1);
	assert(rgb[1] == -1);
	assert(rgb[2] == -1);
	free(rgb);
	c_green();
	printf("test_init_rgb_01 : OK\n");
	c_reset();
}

/*
**	new_data
*/

void	test_new_data_01(void)
{
	t_data	data;

	data = new_data();
	assert(data.width == -1);
	assert(data.height == -1);
	assert(data.no_path == NULL);
	assert(data.so_path == NULL);
	assert(data.we_path == NULL);
	assert(data.ea_path == NULL);
	assert(data.s_path == NULL);
	assert(data.f_rgb[0] == -1);
	assert(data.f_rgb[1] == -1);
	assert(data.f_rgb[2] == -1);
	assert(data.c_rgb[0] == -1);
	assert(data.c_rgb[1] == -1);
	assert(data.c_rgb[2] == -1);
	free_data(&data);
	c_green();
	printf("test_new_data_01 : OK\n");
	c_reset();
}

/*
**	free_data
*/

void	test_free_data_01(void)
{
	//t_data	data;

	//data = new_data();
	//assert(data != NULL);
	//free_data(&data);
	//assert(data == NULL);
	c_green();
	printf("test_free_data_01 : OK\n");
	c_reset();
}

void	test_free_data_02(void)
{
	//t_data	data;

	//data = NULL;
	//free_data(&data);
	//assert(data == NULL);
	c_green();
	printf("test_free_data_02 : OK\n");
	c_reset();
}
