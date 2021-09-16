/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 09:52:45 by bdruez            #+#    #+#             */
/*   Updated: 2021/09/13 20:55:31 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*tmp_s;

	tmp_s = (char *)s;
	while (n--)
	{
		if (*tmp_s == (char)c)
			return (tmp_s);
		else
			tmp_s++;
	}
	return (NULL);
}
