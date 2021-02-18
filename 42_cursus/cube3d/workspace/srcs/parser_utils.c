/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:10:37 by bdruez            #+#    #+#             */
/*   Updated: 2021/02/17 18:04:48 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

unsigned int	get_id_length(int id)
{
	if (id == ID_R)
		return (2);
	else if (id == ID_NO)
		return (3);
	else if (id == ID_SO)
		return (3);
	else if (id == ID_WE)
		return (3);
	else if (id == ID_EA)
		return (3);
	else if (id == ID_S)
		return (2);
	else if (id == ID_F)
		return (2);
	else if (id == ID_C)
		return (2);
	else
		return (0);
}

int				remove_id(char **line, int id)
{
	unsigned int	start;
	size_t			len;
	char			*tmp;

	tmp = NULL;
	start = get_id_length(id);
	len = ft_strlen(*line) - start;
	tmp = ft_substr(*line, start, len);
	if (*line != NULL)
		free(*line);
	*line = ft_strdup(tmp);
	if (tmp != NULL)
		free(tmp);
	return (SUCCESS);
}

int				parse_path(t_data *data, char **line, int id)
{
	if (data == NULL || line == NULL || *line == NULL)
		return (ERR_PARAM_ERROR);
	remove_id(line, id);
	ft_strreftrim(line, " ");
	add_path(data, *line, id);
	free(*line);
	return (SUCCESS);
}

int				parse_resolution(t_data *data, char **line, int id)
{
	if (data == NULL || line == NULL || *line == NULL)
		return (ERR_PARAM_ERROR);
	remove_id(line, id);
	ft_strreftrim(line, " ");
	add_resolution(data, line);
	free(*line);
	return (SUCCESS);
}

int				parse_rgb(t_data *data, char **line, int id)
{
	(void)line;
	(void)data;
	(void)id;
	return (SUCCESS);
}
