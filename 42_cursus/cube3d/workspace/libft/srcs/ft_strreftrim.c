/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreftrim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 12:16:44 by bdruez            #+#    #+#             */
/*   Updated: 2021/02/17 12:29:09 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	is_in_set(char c, char const *set)
{
	size_t iter;

	iter = 0;
	while (iter < ft_strlen(set))
	{
		if (set[iter] == c)
			return (1);
		iter++;
	}
	return (0);
}

static size_t	get_trimmed_len(char const *s1, char const *set)
{
	size_t res;
	size_t iter;

	res = ft_strlen(s1);
	iter = 0;
	while (is_in_set(s1[iter], set) && res != 0)
	{
		iter++;
		res--;
	}
	iter = ft_strlen(s1) - 1;
	while (is_in_set(s1[iter], set) && res != 0)
	{
		iter--;
		res--;
	}
	return (res);
}

void			ft_strreftrim(char **s1, char const *set)
{
	char	*res;
	size_t	iter;
	size_t	iter_res;
	size_t	trimmed_len;

	if (s1 == NULL || *s1 == 0 || set == 0)
		return ;
	trimmed_len = get_trimmed_len(*s1, set);
	if (!(res = malloc(sizeof(*res) * (trimmed_len + 1))))
		return ;
	iter = 0;
	iter_res = 0;
	while (is_in_set(s1[0][iter], set) && iter < ft_strlen(*s1))
		iter++;
	while (iter_res < trimmed_len)
	{
		res[iter_res] = s1[0][iter];
		iter++;
		iter_res++;
	}
	res[iter_res] = 0;
	free(*s1);
	*s1 = ft_strdup(res);
	free(res);
}
