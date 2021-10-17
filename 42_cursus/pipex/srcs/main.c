/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 11:52:24 by bdruez            #+#    #+#             */
/*   Updated: 2021/10/17 20:18:27 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	fd1;
	int	fd2;
	int	iter;

	iter = 0;
	if (argc == 5)
	{
		fd1 = open_file_in(argv[1]);
		fd2 = open_file_out(argv[4]);
		pipex(fd1, fd2, argv, envp);
	}
	else
	{
		while (envp[iter] != 0)
		{
			fprintf(stderr, "%s\n", envp[iter]);
			iter++;
		}
	}
	fprintf(stderr, "END\n");
	return (0);
}
