/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 20:18:55 by bdruez            #+#    #+#             */
/*   Updated: 2021/10/17 20:30:01 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path_var(char **envp)
{
	char	*path;
	int		iter;

	iter = 0;
	path = NULL;
	while (envp[iter] != NULL)
	{
		if (ft_strncmp(envp[iter], "PATH=", 5) == 0)
		{
			path = ft_strdup(envp[iter]);
			break ;
		}
		iter++;
	}
	return (path);
}

char	**get_paths(char **envp)
{
	char	*path;

	path = get_path_var(envp);
	fprintf(stderr, "Path Var : '%s'\n", path);
	free(path);
	return (NULL);
}
