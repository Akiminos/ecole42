/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:57:45 by bdruez            #+#    #+#             */
/*   Updated: 2019/11/07 15:37:38 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	iter;

	iter = 0;
	if (s == 0)
		return (0);
	if ((res = ft_calloc(sizeof(*res), len + 1)) == 0)
		return (0);
	if (start >= (unsigned int)ft_strlen(s))
		return (res);
	while (s[iter] && iter < len)
	{
		res[iter] = s[start];
		iter++;
		start++;
	}
	return (res);
}
