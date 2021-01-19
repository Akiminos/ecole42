/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 16:38:24 by bdruez            #+#    #+#             */
/*   Updated: 2019/11/07 10:59:37 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	len;
	size_t	count;

	len = ft_strlen(s) + 1;
	count = 0;
	while (count < len)
	{
		if (s[count] == c)
			return ((char *)&s[count]);
		count++;
	}
	return (NULL);
}
