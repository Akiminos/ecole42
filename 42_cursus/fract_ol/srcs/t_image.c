/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_image.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 10:16:37 by bdruez            #+#    #+#             */
/*   Updated: 2021/09/16 17:17:55 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_image	*init_image(void)
{
	t_image *image;

	image = ft_calloc(sizeof(t_image), 1);
	if (image == NULL)
		return (NULL);
	image->p_img = NULL;
	image->buffer = NULL;
	image->bpp = 0;
	image->size_line = 0;
	image->endian = 0;
	return (image);
}

t_image *new_image(t_data *data)
{
	t_image *image;

	image = init_image();
	if (image == NULL)
		return (NULL);
	image->p_img = mlx_new_image(data->p_mlx, WIN_W, WIN_H);
	image->buffer = mlx_get_data_addr(image->p_img, &(image->bpp), 
						&(image->size_line), &(image->endian));
	return (image);
}

void	delete_image(t_data *data)
{
	if (data->image != NULL)
	{
		mlx_destroy_image(data->p_mlx, data->image->p_img);
		free(data->image);
	}
}
