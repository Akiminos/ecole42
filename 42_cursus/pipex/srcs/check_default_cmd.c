/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_default_cmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 08:53:54 by bdruez            #+#    #+#             */
/*   Updated: 2021/10/20 09:26:02 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_cmd_array(char ***cmd_array)
{
	int	iter;

	iter = 0;
	while (cmd_array != 0 && cmd_array[0] != 0 && cmd_array[0][iter] != 0)
		free(cmd_array[0][iter++]);
	free(cmd_array[0]);
}

int	check_default_cmd(char *cmd, char **envp)
{
	char	**cmd_array;

	cmd_array = ft_split(cmd, ' ');
	if (cmd_array != 0 && access(cmd_array[0], X_OK) == 0)
		execve(cmd_array[0], cmd_array, envp);
	free_cmd_array(&cmd_array);
	return (-1);
}
