/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 21:12:36 by bdruez            #+#    #+#             */
/*   Updated: 2021/01/26 16:49:54 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "cube3d.h"

void test_ft_strlen()
{
	const char *str = "Hello World !\n";
	printf("ft_strlen : %lu, strlen : %lu\n", ft_strlen(str), strlen(str));
}

int	main(void)
{
	int fd = open("./test.txt", O_RDONLY);
	char *ptr = strdup("");
	int nb_read = 0;
	printf("Hello World\n");
	printf("File descriptor : %d\n", fd);
	nb_read = read(fd, ptr, 10);
	printf("The result is : \"%s\"\n", ptr);
	free(ptr);
	close(fd);

	test_ft_strlen();
}
