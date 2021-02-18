/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 10:29:55 by bdruez            #+#    #+#             */
/*   Updated: 2019/11/07 10:57:13 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char *tmp_s1;
	const char *tmp_s2;

	tmp_s1 = (const char *)s1;
	tmp_s2 = (const char *)s2;
	if (n == 0)
		return (0);
	while (n--)
	{
		if (*tmp_s1 != *tmp_s2)
			return ((unsigned char)*tmp_s1 - (unsigned char)*tmp_s2);
		tmp_s1++;
		tmp_s2++;
	}
	return (0);
}
