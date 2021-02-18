/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:26:35 by bdruez            #+#    #+#             */
/*   Updated: 2019/11/07 11:02:15 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*tmp_dst;
	const char	*tmp_src;
	char		*last_src;
	char		*last_dst;

	tmp_dst = dst;
	tmp_src = src;
	if (dst == 0 && src == 0)
		return (0);
	if (tmp_dst < tmp_src)
	{
		while (len--)
			*tmp_dst++ = *tmp_src++;
	}
	else
	{
		last_src = (char *)(tmp_src + (len - 1));
		last_dst = tmp_dst + (len - 1);
		while (len--)
			*last_dst-- = *last_src--;
	}
	return (dst);
}
