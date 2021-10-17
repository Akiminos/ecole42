/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_subprocess_input.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 16:38:37 by bdruez            #+#    #+#             */
/*   Updated: 2021/10/17 20:38:43 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_subprocess_input(int fd_in, char *cmd, int pipe_array[2])
{
	dup2(fd_in, STDIN_FILENO);
	dup2(pipe_array[1], STDOUT_FILENO);
	close(pipe_array[0]);
	close(fd_in);
	fprintf(stdout, "IN IN : CMD : %s\n", cmd);
	exit(EXIT_SUCCESS);
}
