/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 16:15:13 by bdruez            #+#    #+#             */
/*   Updated: 2021/10/17 20:29:09 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(int fd1, int fd2, char **argv, char **envp)
{
	int		pipe_array[2];
	int		status;
	pid_t	child_1;
	pid_t	child_2;
	char	**paths;

	paths = get_paths(envp);
	pipe(pipe_array);
	child_1 = fork();
	if (child_1 < 0)
		return (perror("Fork"));
	if (child_1 == 0)
		child_subprocess_input(fd1, argv[2], pipe_array);
	child_2 = fork();
	if (child_2 < 0)
		return (perror("Fork"));
	if (child_2 == 0)
		child_subprocess_output(fd2, argv[3], pipe_array);
	close(pipe_array[0]);
	close(pipe_array[1]);
	waitpid(child_1, &status, 0);
	waitpid(child_2, &status, 0);
}
