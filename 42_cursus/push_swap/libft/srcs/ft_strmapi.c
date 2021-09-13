/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 17:05:33 by bdruez            #+#    #+#             */
/*   Updated: 2021/09/13 21:06:55 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	size_t	iter;

	iter = 0;
	if (s == 0 || (*f) == 0)
		return (0);
	res = ft_calloc(ft_strlen(s) + 1, sizeof(*res));
	if (!res)
		return (0);
	while (iter < ft_strlen(s))
	{
		res[iter] = (*f)(iter, s[iter]);
		iter++;
	}
	return (res);
}
