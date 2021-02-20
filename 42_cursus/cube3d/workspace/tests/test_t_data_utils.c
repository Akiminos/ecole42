/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_t_data_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 17:38:15 by bdruez            #+#    #+#             */
/*   Updated: 2021/02/18 14:01:02 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_cube3d.h"
#include "cube3d.h"

/*
**	get_resolution_number
*/
void	test_get_resolution_number_01(void)
{
	int		start;
	char	*line;
	char	*num;
	int		status;

	start = 0;
	line = ft_strdup("1920 1080");
	num = ft_strdup("");
	status = get_resolution_number(line, &num, &start);
	assert(status == SUCCESS);
	assert(strcmp(num, "1920") == 0);
	c_green();
	printf("test_get_resolution_number_01 : OK\n");
	c_reset();
	free(line);
	free(num);
}

void	test_get_resolution_number_02(void)
{
	int		start;
	char	*line;
	char	*num;
	int		status;

	start = 5;
	line = ft_strdup("1920 1080");
	num = ft_strdup("");
	status = get_resolution_number(line, &num, &start);
	assert(status == SUCCESS);
	assert(strcmp(num, "1080") == 0);
	c_green();
	printf("test_get_resolution_number_02 : OK\n");
	c_reset();
	free(line);
	free(num);
}

/*
void	test_get_resolution_number_01(void)
{
	int		start;
	char	*line;
	char	*num;
	int		status;

	start = 0;
	line = ft_strdup("1920 1080");
	num = ft_strdup("");
	status = get_resolution_number(line, &num, start);
	assert(status == SUCCESS);
	assert(strcmp(num, "1920") == 0);
	c_green();
	printf("test_get_resolution_number_01 : OK\n");
	c_reset();
	free(line);
	free(num);
}

void	test_get_resolution_number_01(void)
{
	int		start;
	char	*line;
	char	*num;
	int		status;

	start = 0;
	line = ft_strdup("1920 1080");
	num = ft_strdup("");
	status = get_resolution_number(line, &num, start);
	assert(status == SUCCESS);
	assert(strcmp(num, "1920") == 0);
	c_green();
	printf("test_get_resolution_number_01 : OK\n");
	c_reset();
	free(line);
	free(num);
}
*/
