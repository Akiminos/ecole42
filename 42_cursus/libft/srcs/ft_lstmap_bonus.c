/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 19:21:55 by bdruez            #+#    #+#             */
/*   Updated: 2019/11/13 19:21:56 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *alst;
	t_list *tmp;

	alst = NULL;
	tmp = NULL;
	while (lst)
	{
		if (!(tmp = malloc(sizeof(*tmp))))
		{
			ft_lstclear(&alst, (*del));
			return (0);
		}
		tmp->content = (*f)(lst->content);
		tmp->next = NULL;
		ft_lstadd_back(&alst, tmp);
		lst = lst->next;
	}
	return (alst);
}
