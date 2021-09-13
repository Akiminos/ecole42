/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 15:39:07 by bdruez            #+#    #+#             */
/*   Updated: 2021/09/13 21:05:28 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	iter;
	size_t	iter_res;

	if (s1 == 0 || s2 == 0)
		return (0);
	res = ft_calloc(sizeof(*res), ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (0);
	iter = 0;
	iter_res = 0;
	while (iter < ft_strlen(s1))
	{
		res[iter_res] = s1[iter];
		iter++;
		iter_res++;
	}
	iter = 0;
	while (iter < ft_strlen(s2))
	{
		res[iter_res] = s2[iter];
		iter++;
		iter_res++;
	}
	return (res);
}
