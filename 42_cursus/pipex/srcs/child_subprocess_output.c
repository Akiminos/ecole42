/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_subprocess_output.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 16:41:12 by bdruez            #+#    #+#             */
/*   Updated: 2021/10/20 06:38:41 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_subprocess_output(int fd_out, char *cmd, int pipe_array[2],
			char **envp)
{
	int	status;

	status = EXIT_FAILURE;
	if (fd_out != -1)
	{
		dup2(fd_out, STDOUT_FILENO);
		dup2(pipe_array[0], STDIN_FILENO);
		close(pipe_array[1]);
		close(fd_out);
		status = execute_command(cmd, envp);
	}
	exit(status);
}
