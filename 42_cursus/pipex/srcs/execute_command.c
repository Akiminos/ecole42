/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:43:32 by bdruez            #+#    #+#             */
/*   Updated: 2021/10/20 08:56:01 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**generate_args(char *cmd, char **envp)
{
	char	**args;
	char	*tmp;
	int		iter;

	args = get_paths(cmd, envp);
	iter = 0;
	while (args[iter] != 0)
	{
		tmp = NULL;
		tmp = ft_strjoin(args[iter], cmd);
		free(args[iter]);
		args[iter] = tmp;
		iter++;
	}
	return (args);
}

char	***generate_args_array(char *cmd, char **envp)
{
	char	**args;
	char	***args_array;
	int		nb_paths;
	int		iter;

	args = generate_args(cmd, envp);
	nb_paths = 0;
	while (args[nb_paths] != 0)
		nb_paths ++;
	args_array = ft_calloc(sizeof(*args_array), nb_paths + 1);
	iter = 0;
	while (iter < nb_paths)
	{
		args_array[iter] = ft_split(args[iter], ' ');
		free(args[iter]);
		iter++;
	}
	free(args);
	return (args_array);
}

int		check_command(char ***args_array)
{
	int		iter;
	int		status;

	status = -1;
	iter = 0;
	while (status == -1 && args_array[iter] != 0)
	{
		if (access(args_array[iter][0], F_OK) == 0)
		{
			if (access(args_array[iter][0], X_OK) == 0)
			{
				return (iter);
			}
			else
				return (-2);
		}
		iter++;
	}
	return (-1);
}

void	free_args_array(char ****args_array)
{
	int	iter;
	int	iter2;

	iter = 0;
	while (args_array[0][iter] != 0)
	{
		iter2 = 0;
		while (args_array[0][iter][iter2] != 0)
		{
			free(args_array[0][iter][iter2]);
			iter2++;
		}
		free(args_array[0][iter]);
		iter++;
	}
	free(args_array[0]);
}

int		execute_command(char *cmd, char **envp)
{
	char	***args_array;
	int		pos;

	check_default_cmd(cmd, envp);
	args_array = generate_args_array(cmd, envp);
	pos = check_command(args_array);
	if (pos == -1)
	{
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(" : command not found\n", 2);
		free_args_array(&args_array);
		return (127);
	}
	else if (pos == -2)
	{
		perror(cmd);
		free_args_array(&args_array);
		return (126);
	}
	else
		execve(args_array[pos][0], args_array[pos], envp);
	return (-1);
}
