/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 16:27:01 by bdruez            #+#    #+#             */
/*   Updated: 2021/02/17 17:55:05 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		check_id(char *line)
{
	if (ft_strncmp(line, "R ", 2) == 0)
		return (ID_R);
	else if (ft_strncmp(line, "NO ", 3) == 0)
		return (ID_NO);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		return (ID_SO);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		return (ID_WE);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		return (ID_EA);
	else if (ft_strncmp(line, "S ", 2) == 0)
		return (ID_S);
	else if (ft_strncmp(line, "F ", 2) == 0)
		return (ID_F);
	else if (ft_strncmp(line, "C ", 2) == 0)
		return (ID_C);
	else
		return (ID_ERR);
}

int		get_parser(char *line, t_data *data, int id)
{
	int		state;

	state = SUCCESS;
	if (id == ID_R)
		state = parse_resolution(data, &line, id);
	else if (id == ID_F || id == ID_C)
		state = parse_rgb(data, &line, id);
	else
		state = parse_path(data, &line, id);
	return (state);
}

int		parse_line(char *line, t_data *data)
{
	int		id;
	int		state;

	state = SUCCESS;
	id = check_id(line);
	if (id == ID_ERR)
		return (ERR_ID_ERROR);
	else
		state = get_parser(line, data, id);
	return (state);
}
