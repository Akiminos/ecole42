/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 11:52:24 by bdruez            #+#    #+#             */
/*   Updated: 2021/09/20 13:52:30 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	char *cmd;

	if (argc > 2)
	{
		cmd = create_command(argv[1]);
		ft_putstr_fd(cmd, 1);
		ft_putstr_fd("\n", 1);
		if (execve(cmd, argv, envp) == -1)
			perror("Could not execv");
		ft_putstr_fd("After...\n", 1);
	}
	return (1);
}
