/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:50:00 by bdruez            #+#    #+#             */
/*   Updated: 2021/01/28 21:49:56 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	iter_dst;
	size_t	iter_src;
	size_t	dst_len;

	dst_len = ft_strlen(dst);
	if (dstsize == 0)
		return (ft_strlen(src));
	if (dstsize < dst_len)
		return (ft_strlen(src) + dstsize);
	iter_dst = dst_len;
	iter_src = 0;
	while (src[iter_src] && iter_dst < dstsize - 1)
	{
		dst[iter_dst] = src[iter_src];
		iter_dst++;
		iter_src++;
	}
	dst[iter_dst] = 0;
	return (ft_strlen(src) + dst_len);
}
