/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 11:52:24 by bdruez            #+#    #+#             */
/*   Updated: 2021/10/20 06:41:12 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	fd1;
	int	fd2;
	int	iter;
	int	status;

	iter = 0;
	status = 1;
	if (argc == 5)
	{
		fd1 = open_file_in(argv[1]);
		fd2 = open_file_out(argv[4]);
		status = pipex(fd1, fd2, argv, envp);
	}
	return (status);
}
