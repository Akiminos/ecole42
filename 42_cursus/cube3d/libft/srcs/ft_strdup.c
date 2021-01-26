/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:41:05 by bdruez            #+#    #+#             */
/*   Updated: 2019/11/09 19:52:47 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	char	*tmp_s1;
	size_t	len;
	size_t	iter;

	tmp_s1 = (char *)s1;
	len = ft_strlen(s1);
	iter = 0;
	if ((dup = malloc(sizeof(*dup) * (len + 1))) == 0)
		return (0);
	while (iter < len)
	{
		dup[iter] = tmp_s1[iter];
		iter++;
	}
	dup[iter] = 0;
	return (dup);
}
