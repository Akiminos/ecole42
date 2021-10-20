/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_subprocess_input.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 16:38:37 by bdruez            #+#    #+#             */
/*   Updated: 2021/10/20 06:39:50 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_subprocess_input(int fd_in, char *cmd, int pipe_array[2],
			char **envp)
{
	int	status;

	status = EXIT_FAILURE;
	if (fd_in != -1)
	{
		dup2(fd_in, STDIN_FILENO);
		dup2(pipe_array[1], STDOUT_FILENO);
		close(pipe_array[0]);
		close(fd_in);
		status = execute_command(cmd, envp);
	}
	exit(status);
}
