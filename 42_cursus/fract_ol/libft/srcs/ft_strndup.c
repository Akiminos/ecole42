/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 19:44:30 by bdruez            #+#    #+#             */
/*   Updated: 2021/09/13 21:10:08 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t len)
{
	char	*dup;
	char	*tmp_s;
	size_t	len_alloc;
	size_t	iter;

	tmp_s = (char *)s;
	if (len < ft_strlen(s))
		len_alloc = len;
	else
		len_alloc = ft_strlen(s);
	iter = 0;
	dup = ft_calloc((len_alloc + 1), sizeof(*dup));
	if (!dup)
		return (0);
	while (iter < len_alloc)
	{
		dup[iter] = tmp_s[iter];
		iter++;
	}
	return (dup);
}
