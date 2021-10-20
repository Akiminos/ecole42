/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 14:07:28 by bdruez            #+#    #+#             */
/*   Updated: 2021/09/25 15:15:30 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_diff(const char s1, const char *s2, size_t len1, size_t len2)
{

}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	iter;
	int		res;		

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len1 != len2)
		return (get_diff(s1, s2, len1, len2));
	iter = 0;
	while (iter < len1)
	{
		res = (int)s1[iter] - (int)s2[iter];
		if (res != 0)
			return (res);
		iter++;
	}
	return (0);
}
