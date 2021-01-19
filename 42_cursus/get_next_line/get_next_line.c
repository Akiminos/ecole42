/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 18:03:58 by bdruez            #+#    #+#             */
/*   Updated: 2019/12/03 20:21:38 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char *str, size_t start, size_t len)
{
	char	*res;
	size_t	iter;

	iter = 0;
	if (!str || !(res = ft_calloc(sizeof(*res), (len + 1))))
		return (0);
	if (ft_strlen(str) < start)
		return (ft_strdup(""));
	while (str[iter] && iter < len)
	{
		res[iter] = str[iter + start];
		iter++;
	}
	res[iter] = 0;
	return (res);
}

char	*flush_rest(char *rest, int pos)
{
	char	*tmp;

	if (rest[pos])
	{
		tmp = ft_strdup(rest + pos + 1);
		free(rest);
		rest = tmp;
	}
	else
	{
		free(rest);
		rest = NULL;
	}
	return (rest);
}

int		ft_exit(int code, char **buffer, char **rest)
{
	if (code >= 0)
	{
		if (*buffer)
			free(*buffer);
		if (code == 0 && *rest)
			free(*rest);
	}
	if (code == -1)
		if (!*buffer)
			free(*buffer);
	return (code);
}

int		ft_return(int code, char *buffer, char *rest)
{
	if (code || rest)
		return (ft_exit(1, &buffer, &rest));
	return (ft_exit(0, &buffer, &rest));
}

int		get_next_line(int fd, char **line)
{
	static char	*rest;
	char		*buffer;
	int			nb_bytes;
	size_t		iter;

	iter = 0;
	buffer = NULL;
	if (fd < 0 || !line || BUFFER_SIZE <= 0 ||
			(!(buffer = ft_calloc(sizeof(*buffer), (BUFFER_SIZE + 1)))))
		return (ft_exit(-1, &buffer, &rest));
	if (!rest)
		rest = ft_calloc(sizeof(*rest), 1);
	while (!is_in(buffer, '\n') && (nb_bytes = read(fd, buffer, BUFFER_SIZE)))
	{
		if (nb_bytes < 0)
			return (ft_exit(-1, &buffer, &rest));
		buffer[nb_bytes] = 0;
		rest = ft_strjoin(rest, buffer);
	}
	while (rest[iter] != '\0' && rest[iter] != '\n')
		iter++;
	*line = ft_substr(rest, 0, iter);
	rest = flush_rest(rest, iter);
	return (ft_return(nb_bytes, buffer, rest));
}
