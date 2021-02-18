/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 21:12:36 by bdruez            #+#    #+#             */
/*   Updated: 2021/02/16 18:17:45 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "cube3d.h"

int	main(void)
{
	/*
	int fd = open("./test.txt", O_RDONLY);
	char *ptr;

	printf("File descriptor : %d\n", fd);
	ptr = get_line(fd);
	printf("The result is : \"%s\"\n", ptr);
	free(ptr);
	close(fd);

	int		id = 0;
	char	*line = "G ple";
	id = check_id(line);
	printf("Str : %s, ID found : %d\n", line, id);
	*/

	t_data data = new_data();
	free_data(&data);
}
