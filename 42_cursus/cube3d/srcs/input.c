/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 20:32:28 by bdruez            #+#    #+#             */
/*   Updated: 2021/01/25 23:56:56 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		open_map(char* path)
{
	int fd;
	fd = open(path);


	return (fd);
}

void	add_char(char** cur, char* to_add)
{
	size_t
}

char*	get_line(int fd)
{
	char	*line;
	char	*chr;
	int		nb_read;

	line = ft_strdup("");
	chr = ft_strdup("");
	nb_read = 1;
	while(nb_read == 1 && chr != '\n')
	{
		nb_read = read(fd, chr, 1);
	}
	return (line);
}
