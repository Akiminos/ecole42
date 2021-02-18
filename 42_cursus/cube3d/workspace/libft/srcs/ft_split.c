/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 18:09:35 by bdruez            #+#    #+#             */
/*   Updated: 2019/11/09 19:44:17 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_nb_word(char const *s, char c)
{
	short	is_word;
	size_t	nb_word;
	size_t	iter;

	is_word = 0;
	iter = 0;
	nb_word = 0;
	while (iter < ft_strlen(s))
	{
		if (s[iter] != c)
		{
			if (!is_word)
				nb_word++;
			is_word = 1;
		}
		else
			is_word = 0;
		iter++;
	}
	return (nb_word);
}

static char		*get_next_word(char **ptr, char c)
{
	char	*start;
	char	*res;

	while (**ptr && **ptr == c)
		*ptr = *ptr + 1;
	start = *ptr;
	while (**ptr && **ptr != c)
		*ptr = *ptr + 1;
	if (!(res = ft_strndup(start, (size_t)(*ptr - start))))
		return (0);
	return (res);
}

static void		free_tab(char **tab)
{
	size_t iter;

	iter = 0;
	while (tab[iter])
	{
		free(tab[iter]);
		iter++;
	}
	free(tab);
}

char			**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	nb_word;
	size_t	curr_word;
	char	*ptr;

	if (s == 0)
		return (0);
	nb_word = get_nb_word(s, c);
	curr_word = 0;
	if (!(tab = malloc(sizeof(*tab) * (nb_word + 1))))
		return (0);
	tab[nb_word] = 0;
	ptr = (char *)s;
	while (curr_word < nb_word)
	{
		if (!(tab[curr_word] = get_next_word(&ptr, c)))
		{
			free_tab(tab);
			return (0);
		}
		curr_word++;
	}
	return (tab);
}
