/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 20:32:28 by bdruez            #+#    #+#             */
/*   Updated: 2021/02/16 14:51:07 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int		open_map(char *path)
{
	int fd;

	fd = open(path, O_RDONLY);
	return (fd);
}

void	add_char(char **cur, char *to_add)
{
	size_t	dstsize;
	char	*tmp;

	if ((cur != NULL) && (*cur != NULL) && (to_add != NULL))
	{
		tmp = ft_strdup(*cur);
		free(*cur);
		dstsize = ft_strlen(tmp) + 2;
		*cur = ft_calloc(sizeof(*cur), dstsize);
		if (*cur != NULL)
		{
			ft_strlcat(*cur, tmp, dstsize);
			ft_strlcat(*cur, to_add, dstsize);
		}
		if (tmp != NULL)
			free(tmp);
	}
}

char	*get_line(int fd)
{
	char	*line;
	char	*chr;
	int		nb_read;

	line = ft_calloc(sizeof(*line), 3);
	chr = ft_calloc(sizeof(*chr), 2);
	nb_read = 1;
	while (nb_read == 1 && chr[0] != '\n')
	{
		nb_read = read(fd, chr, 1);
		if (nb_read == 1 && chr[0] != '\n')
			add_char(&line, chr);
	}
	if (chr != NULL)
		free(chr);
	return (line);
}
