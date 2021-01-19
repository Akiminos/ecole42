/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 10:23:19 by bdruez            #+#    #+#             */
/*   Updated: 2019/11/08 15:31:24 by bdruez           ###   ########.fr       */
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

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	iter;
	size_t	iter_res;
	size_t	trimmed_len;

	if (s1 == 0 || set == 0)
		return (0);
	trimmed_len = get_trimmed_len(s1, set);
	if (!(res = malloc(sizeof(*res) * (trimmed_len + 1))))
		return (0);
	iter = 0;
	iter_res = 0;
	while (is_in_set(s1[iter], set) && iter < ft_strlen(s1))
	{
		iter++;
	}
	while (iter_res < trimmed_len)
	{
		res[iter_res] = s1[iter];
		iter++;
		iter_res++;
	}
	res[iter_res] = 0;
	return (res);
}
