/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_data_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:21:50 by bdruez            #+#    #+#             */
/*   Updated: 2021/02/18 15:18:10 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		get_resolution_number(char *line, char **num, int *start)
{
	int size;

	size = 0;
	while (line[start[0]] != 0 && line[start[0]] != ' ' && size <= 4)
	{
		if (!ft_isdigit(line[start[0]]))
		{
			free(*num);
			return (ERR_WRONG_RESOLUTION);
		}
		add_char(num, &line[start[0]]);
		start[0]++;
		size++;
	}
	if (size == 0 || size >= 10)
	{
		free(*num);
		return (ERR_OUT_OF_BOUND_RESOLUTION);
	}
	return (SUCCESS);
}

int		add_resolution(t_data *data, char **line)
{
	int		start;
	int		state;
	char	*num;

	start = 0;
	state = SUCCESS;
	(void)data;
	num = ft_strdup("");
	state = get_resolution_number(*line, &num, &start);
	if (state != SUCCESS)
		return (state);
	data->width = ft_atoi(num);
	return (SUCCESS);
}
