/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:28:15 by bdruez            #+#    #+#             */
/*   Updated: 2019/11/09 17:47:25 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	iter;
	size_t	len;

	iter = 0;
	if (src == 0)
		return (0);
	len = ft_strlen(src);
	if (dstsize == 0)
		return (len);
	while (src[iter] && iter < dstsize - 1)
	{
		dst[iter] = src[iter];
		iter++;
	}
	dst[iter] = 0;
	return (len);
}
