/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_data.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 18:47:35 by bdruez            #+#    #+#             */
/*   Updated: 2021/02/17 14:15:05 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		*init_rgb(void)
{
	int	*rgb;

	rgb = malloc(sizeof(*rgb) * 3);
	if (rgb == NULL)
		return (NULL);
	rgb[0] = -1;
	rgb[1] = -1;
	rgb[2] = -1;
	return (rgb);
}

void	add_rgb(t_data *data, int *rgb, int id)
{
	if (id == ID_F)
	{
		data->f_rgb[0] = rgb[0];
		data->f_rgb[1] = rgb[1];
		data->f_rgb[2] = rgb[2];
	}
	else if (id == ID_C)
	{
		data->c_rgb[0] = rgb[0];
		data->c_rgb[1] = rgb[1];
		data->c_rgb[2] = rgb[2];
	}
}

t_data	new_data(void)
{
	t_data	data;

	data.width = -1;
	data.height = -1;
	data.no_path = NULL;
	data.so_path = NULL;
	data.we_path = NULL;
	data.ea_path = NULL;
	data.s_path = NULL;
	data.f_rgb = init_rgb();
	data.c_rgb = init_rgb();
	return (data);
}

void	free_data(t_data *data)
{
	if (data == NULL)
		return ;
	if (data->no_path != NULL)
		free(data->no_path);
	if (data->so_path != NULL)
		free(data->so_path);
	if (data->we_path != NULL)
		free(data->we_path);
	if (data->ea_path != NULL)
		free(data->ea_path);
	if (data->s_path != NULL)
		free(data->s_path);
	if (data->f_rgb != NULL)
		free(data->f_rgb);
	if (data->c_rgb != NULL)
		free(data->c_rgb);
}

void	add_path(t_data *data, char *path, int id)
{
	if (id == ID_NO)
		data->no_path = ft_strdup(path);
	else if (id == ID_SO)
		data->so_path = ft_strdup(path);
	else if (id == ID_WE)
		data->we_path = ft_strdup(path);
	else if (id == ID_EA)
		data->ea_path = ft_strdup(path);
	else if (id == ID_S)
		data->s_path = ft_strdup(path);
	else
		return ;
}
