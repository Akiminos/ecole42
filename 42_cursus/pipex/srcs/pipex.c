/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 16:15:13 by bdruez            #+#    #+#             */
/*   Updated: 2021/10/20 06:40:42 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipex(int fd1, int fd2, char **argv, char **envp)
{
	int		pipe_array[2];
	int		status;
	pid_t	child_1;
	pid_t	child_2;

	pipe(pipe_array);
	child_1 = fork();
	if (child_1 < 0)
		return (1);
	if (child_1 == 0)
		child_subprocess_input(fd1, argv[2], pipe_array, envp);
	child_2 = fork();
	if (child_2 < 0)
		return (1);
	if (child_2 == 0)
		child_subprocess_output(fd2, argv[3], pipe_array, envp);
	close(pipe_array[0]);
	close(pipe_array[1]);
	waitpid(child_1, &status, 0);
	waitpid(child_2, &status, 0);
	if (WIFEXITED(status))
		status = WEXITSTATUS(status);
	return (status);
}
