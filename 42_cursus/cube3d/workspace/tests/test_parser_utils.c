/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parser_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 17:59:22 by bdruez            #+#    #+#             */
/*   Updated: 2021/02/17 14:55:31 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_cube3d.h"
#include "cube3d.h"

/*
**	get_id_length
*/
void	test_get_id_length_01(void)
{
	int		id;

	id = ID_R;
	assert(get_id_length(id) == 2);
	c_green();
	printf("test_get_id_length_01 : OK\n");
	c_reset();
}

void	test_get_id_length_02(void)
{
	int		id;

	id = ID_NO;
	assert(get_id_length(id) == 3);
	c_green();
	printf("test_get_id_length_02 : OK\n");
	c_reset();
}

void	test_get_id_length_03(void)
{
	int		id;

	id = ID_SO;
	assert(get_id_length(id) == 3);
	c_green();
	printf("test_get_id_length_03 : OK\n");
	c_reset();
}

void	test_get_id_length_04(void)
{
	int		id;

	id = ID_WE;
	assert(get_id_length(id) == 3);
	c_green();
	printf("test_get_id_length_04 : OK\n");
	c_reset();
}

void	test_get_id_length_05(void)
{
	int		id;

	id = ID_EA;
	assert(get_id_length(id) == 3);
	c_green();
	printf("test_get_id_length_05 : OK\n");
	c_reset();
}

void	test_get_id_length_06(void)
{
	int		id;

	id = ID_S;
	assert(get_id_length(id) == 2);
	c_green();
	printf("test_get_id_length_06 : OK\n");
	c_reset();
}

void	test_get_id_length_07(void)
{
	int		id;

	id = ID_F;
	assert(get_id_length(id) == 2);
	c_green();
	printf("test_get_id_length_07 : OK\n");
	c_reset();
}

void	test_get_id_length_08(void)
{
	int		id;

	id = ID_C;
	assert(get_id_length(id) == 2);
	c_green();
	printf("test_get_id_length_08 : OK\n");
	c_reset();
}

void	test_get_id_length_09(void)
{
	int		id;

	id = ID_ERR;
	assert(get_id_length(id) == 0);
	c_green();
	printf("test_get_id_length_09 : OK\n");
	c_reset();
}

/*
**	remove_id
*/
void	test_remove_id_01(void)
{
	char	*line;

	line = ft_strdup("R 1200 900");
	remove_id(&line, ID_R);
	assert(strcmp(line, "1200 900") == 0);
	c_green();
	printf("test_remove_id_01 : OK\n");
	c_reset();
	free(line);
}

/*
**	parse_path
*/
void	test_parse_path_01(void)
{
	t_data	data;
	char	*line;
	int		id;
	int		status;

	data = new_data();
	line = ft_strdup("NO ./resources/a_file   ");
	id = ID_NO;
	status = parse_path(&data, &line, id);
	assert(strcmp(data.no_path, "./resources/a_file") == 0);
	assert(status == SUCCESS);
	free_data(&data);
	c_green();
	printf("test_parse_path_01 : OK\n");
	c_reset();
}

void	test_parse_path_02(void)
{
	t_data	data;
	char	*line;
	int		id;
	int		status;

	data = new_data();
	line = ft_strdup("SO ./resources/a_file   ");
	id = ID_SO;
	status = parse_path(&data, &line, id);
	assert(strcmp(data.so_path, "./resources/a_file") == 0);
	assert(status == SUCCESS);
	free_data(&data);
	c_green();
	printf("test_parse_path_02 : OK\n");
	c_reset();
}

void	test_parse_path_03(void)
{
	t_data	data;
	char	*line;
	int		id;
	int		status;

	data = new_data();
	line = ft_strdup("WE ./resources/a_file   ");
	id = ID_WE;
	status = parse_path(&data, &line, id);
	assert(strcmp(data.we_path, "./resources/a_file") == 0);
	assert(status == SUCCESS);
	free_data(&data);
	c_green();
	printf("test_parse_path_03 : OK\n");
	c_reset();
}

void	test_parse_path_04(void)
{
	t_data	data;
	char	*line;
	int		id;
	int		status;

	data = new_data();
	line = ft_strdup("EA ./resources/a_file   ");
	id = ID_EA;
	status = parse_path(&data, &line, id);
	assert(strcmp(data.ea_path, "./resources/a_file") == 0);
	assert(status == SUCCESS);
	free_data(&data);
	c_green();
	printf("test_parse_path_04 : OK\n");
	c_reset();
}

void	test_parse_path_05(void)
{
	t_data	data;
	char	*line;
	int		id;
	int		status;

	data = new_data();
	line = ft_strdup("S ./resources/a_file   ");
	id = ID_S;
	status = parse_path(&data, &line, id);
	assert(strcmp(data.s_path, "./resources/a_file") == 0);
	assert(status == SUCCESS);
	free_data(&data);
	c_green();
	printf("test_parse_path_05 : OK\n");
	c_reset();
}

void	test_parse_path_06(void)
{
	char	*line;
	int		id;
	int		status;

	line = ft_strdup("NO ./resources/a_file   ");
	id = ID_NO;
	status = parse_path(NULL, &line, id);
	assert(status == ERR_PARAM_ERROR);
	free(line);
	c_green();
	printf("test_parse_path_06 : OK\n");
	c_reset();
}
