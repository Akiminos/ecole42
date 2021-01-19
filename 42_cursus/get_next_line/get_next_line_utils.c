/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 16:45:41 by bdruez            #+#    #+#             */
/*   Updated: 2019/12/03 20:21:57 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		is_in(char *str, int chr)
{
	size_t iter;

	iter = 0;
	while (str[iter] && str[iter] != chr)
		iter++;
	if (str[iter] == chr)
		return (1);
	return (0);
}

size_t	ft_strlen(char *str)
{
	size_t len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_calloc(size_t count, size_t size)
{
	char	*res;
	size_t	iter;

	iter = 0;
	if (!count || !size)
		return (0);
	if ((res = malloc(count * size)) == 0)
		return (0);
	while (iter < count * size)
	{
		res[iter] = '\0';
		iter++;
	}
	return (res);
}

char	*ft_strdup(char *src)
{
	char	*res;
	size_t	iter;

	iter = 0;
	if (!(res = ft_calloc(sizeof(*res), (ft_strlen(src) + 1))))
		return (NULL);
	while (src[iter])
	{
		res[iter] = src[iter];
		iter++;
	}
	res[iter] = '\0';
	return (res);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	size_t	iter_res;
	size_t	iter_str;

	if (!s1 || !s2 || !(res = ft_calloc(sizeof(*res),
					(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	iter_res = 0;
	iter_str = 0;
	while (s1[iter_str])
		res[iter_res++] = s1[iter_str++];
	iter_str = 0;
	while (s2[iter_str])
		res[iter_res++] = s2[iter_str++];
	res[iter_res] = '\0';
	free(s1);
	return (res);
}
