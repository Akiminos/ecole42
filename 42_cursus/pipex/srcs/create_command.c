/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 12:50:41 by bdruez            #+#    #+#             */
/*   Updated: 2021/09/20 13:00:40 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*create_command(const char *cmd)
{
	char	*res;
	int		size;

	size = ft_strlen(cmd) + 6;
	res = ft_calloc(sizeof(*res), size);
	if (res == NULL)
		return (NULL);
	res[0] = '/';
	res[1] = 'b';
	res[2] = 'i';
	res[3] = 'n';
	res[4] = '/';
	res[5] = '\0';
	ft_strlcat(res, cmd, size);
	return (res);
}
