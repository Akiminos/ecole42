/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 19:21:05 by bdruez            #+#    #+#             */
/*   Updated: 2019/11/13 19:21:06 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	clear_node(t_list *node, void (*del)(void *))
{
	if (node)
	{
		clear_node(node->next, (*del));
		(*del)(node->content);
		free(node);
	}
}

void		ft_lstclear(t_list **lst, void (*del)(void *))
{
	if ((*del))
	{
		clear_node(*lst, (*del));
		*lst = NULL;
	}
}
