/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:08:35 by bdruez            #+#    #+#             */
/*   Updated: 2019/11/07 10:55:53 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char			*tmp_dst;
	const char		*tmp_src;
	unsigned char	tmp_c;

	tmp_dst = dst;
	tmp_src = src;
	tmp_c = (unsigned char)c;
	if (dst == 0 && src == 0)
		return (0);
	while (n--)
	{
		if ((unsigned char)*tmp_src == tmp_c)
		{
			*tmp_dst = *tmp_src;
			return (tmp_dst + 1);
		}
		*tmp_dst = *tmp_src;
		tmp_dst++;
		tmp_src++;
	}
	return (0);
}
