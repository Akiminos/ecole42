/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 20:18:55 by bdruez            #+#    #+#             */
/*   Updated: 2021/10/20 08:51:06 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	trim_path(char **path)
{
	char	*tmp;
	int		iter;
	int		iter_2;

	tmp = ft_strdup(*path);
	free(*path);
	*path = NULL;
	*path = ft_calloc(sizeof(**path), ft_strlen(tmp) - 4);
	iter = 5;
	iter_2 = 0;
	while (tmp[iter] != 0)
	{
		path[0][iter_2] = tmp[iter];
		iter++;
		iter_2++;
	}
	free(tmp);
}

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

void	add_backslash(char ***paths)
{
	char	*tmp;
	int		iter;

	iter = 0;
	while (paths[0][iter] != 0)
	{
		tmp = ft_strndup(paths[0][iter], ft_strlen(paths[0][iter]) + 1);
		free(paths[0][iter]);
		tmp[ft_strlen(tmp)] = '/';
		paths[0][iter] = ft_strdup(tmp);
		free(tmp);
		iter++;
	}
}

char	**get_paths(char *cmd, char **envp)
{
	char	*path;
	char	**res;

	(void)cmd;
	path = get_path_var(envp);
	trim_path(&path);
	res = ft_split(path, ':');
	free(path);
	add_backslash(&res);
	return (res);
}
