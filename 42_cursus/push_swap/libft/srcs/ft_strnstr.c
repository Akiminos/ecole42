/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:52:53 by bdruez            #+#    #+#             */
/*   Updated: 2021/09/13 21:12:00 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_substr(const char *str, const char *sub_str, size_t pos)
{
	size_t	iter_str;
	size_t	iter_sub;

	iter_str = pos;
	iter_sub = 0;
	while (str[iter_str] && sub_str[iter_sub])
	{
		if (str[iter_str] - sub_str[iter_sub] != 0)
			return (-1);
		iter_str++;
		iter_sub++;
	}
	if (str[iter_str] - sub_str[iter_sub] >= 0)
		return (0);
	else
		return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	iter;
	size_t	needle_len;

	iter = 0;
	needle_len = ft_strlen(needle);
	if (ft_strlen(haystack) == 0 && ft_strlen(needle) == 0)
		return ("\0");
	else if (ft_strlen(haystack) > 0 && ft_strlen(needle) == 0)
		return ((char *)haystack);
	if (len == 0)
		return (0);
	while (haystack[iter] && iter < (len - needle_len + 1))
	{
		if (haystack[iter] == needle[0])
		{
			if (ft_check_substr(haystack, needle, iter) == 0)
				return ((char *)&haystack[iter]);
		}
		iter++;
	}
	return (0);
}
