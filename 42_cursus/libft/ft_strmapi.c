/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 17:05:33 by bdruez            #+#    #+#             */
/*   Updated: 2019/11/10 17:26:20 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	size_t	iter;

	iter = 0;
	if (s == 0)
		return (0);
	if (!(res = ft_calloc(ft_strlen(s) + 1, sizeof(*res))))
		return (0);
	while (iter < ft_strlen(s))
	{
		res[iter] = (*f)(iter, s[iter]);
		iter++;
	}
	return (res);
}
