/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_data_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:21:50 by bdruez            #+#    #+#             */
/*   Updated: 2021/02/17 18:02:06 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		get_resolution_number(char *line, char **res, int start)
{
	int	iter;
	int size;

	iter = start;
	size = 0;
	while (line[iter] != 0 && line[iter] != ' ' && size <= 4)
	{
		if (!ft_isdigit(line[iter]))
			return (ERR_WRONG_RESOLUTION);
		add_char(res, &line[iter]);
		iter++;
		size++;
	}
	if (size >= 5)
		return (ERR_OUT_OF_BOUND_RESOLUTION);
	return (SUCCESS);
}

int		add_resolution(t_data *data, char **line)
{
	int		iter;
	int		size;
	char	*tmp;

	iter = 0;
	size = 0;
	(void)data;
	tmp = ft_strdup("");
	get_resolution_number(*line, &tmp, iter);
	return (SUCCESS);
}
