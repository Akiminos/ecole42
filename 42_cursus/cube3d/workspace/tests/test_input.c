/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 14:17:19 by bdruez            #+#    #+#             */
/*   Updated: 2021/02/10 10:10:34 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_cube3d.h"
#include "cube3d.h"

/*
**	add_char()
*/
void	test_add_char_01(void)
{
	char	*str;

	str = ft_strdup("");
	add_char(&str, "");
	assert(strcmp(str, "") == 0);
	c_green();
	printf("test_add_char_01 : OK\n");
	c_reset();
	free(str);
}

void	test_add_char_02(void)
{
	char	*str;

	str = ft_strdup("");
	add_char(&str, "t");
	assert(strcmp(str, "t") == 0);
	c_green();
	printf("test_add_char_02 : OK\n");
	c_reset();
	free(str);
}

void	test_add_char_03(void)
{
	char	*str;

	str = ft_strdup("");
	add_char(&str, NULL);
	assert(strcmp(str, "") == 0);
	c_green();
	printf("test_add_char_03 : OK\n");
	c_reset();
	free(str);
}

void	test_add_char_04(void)
{
	char	*str;

	str = ft_strdup("tes");
	add_char(&str, "t");
	assert(strcmp(str, "test") == 0);
	c_green();
	printf("test_add_char_04 : OK\n");
	c_reset();
	free(str);
}

void	test_add_char_05(void)
{
	char	*str;

	str = ft_strdup("NULL");
	add_char(&str, NULL);
	assert(strcmp(str, "NULL") == 0);
	c_green();
	printf("test_add_char_05 : OK\n");
	c_reset();
	free(str);
}

void	test_add_char_06(void)
{
	char	*str;

	str = NULL;
	add_char(&str, "t");
	assert(str == NULL);
	c_green();
	printf("test_add_char_06 : OK\n");
	c_reset();
	free(str);
}

/*
**	get_line()
*/
void	test_get_line_01(void)
{
	int		fd;
	char	*line;

	fd = open("./tests/resources/test_input_01.txt", O_RDONLY);
	if (fd < 0)
	{
		c_red();
		printf("ERROR : invalid path or open() failure\n");
		return;
	}
	line = get_line(fd);
	assert(strcmp(line, "This is the first line") == 0);
	free(line);
	line = get_line(fd);
	assert(strcmp(line, "This is the second line") == 0);
	free(line);
	c_green();
	printf("test_get_line_01 : OK\n");
	c_reset();
}

void	test_get_line_02(void)
{
	int		fd;
	char	*line;

	fd = open("./tests/resources/test_input_02.txt", O_RDONLY);
	if (fd < 0)
	{
		c_red();
		printf("ERROR : invalid path or open() failure\n");
		return;
	}
	line = get_line(fd);
	assert(strcmp(line, "") == 0);
	free(line);
	c_green();
	printf("test_get_line_02 : OK\n");
	c_reset();
}

void	test_get_line_03(void)
{
	int		fd;
	char	*line;

	fd = open("./tests/resources/test_input_03.txt", O_RDONLY);
	if (fd < 0)
	{
		c_red();
		printf("ERROR : invalid path or open() failure\n");
		return;
	}
	line = get_line(fd);
	assert(strcmp(line, "There is a \\n in this line but it is fine") == 0);
	free(line);
	c_green();
	printf("test_get_line_03 : OK\n");
	c_reset();
}
