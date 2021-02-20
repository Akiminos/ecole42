/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:34:48 by bdruez            #+#    #+#             */
/*   Updated: 2021/02/18 13:37:16 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_cube3d.h"
#include "cube3d.h"

void	test_input(void)
{
	c_yellow();
	printf("START : input.c : add_char()\n");
	c_reset();
	test_add_char_01();
	test_add_char_02();
	test_add_char_03();
	test_add_char_04();
	test_add_char_05();
	test_add_char_06();
	c_yellow();
	printf("END : input.c : add_char()\n");
	c_reset();

	c_cyan();
	printf("-------------------------------------\n");
	c_reset();

	c_yellow();
	printf("START : input.c : get_line()\n");
	c_reset();
	test_get_line_01();
	test_get_line_02();
	test_get_line_03();
	c_yellow();
	printf("END : input.c : get_line()\n");
	c_reset();
}

void	test_t_data(void)
{
	c_yellow();
	printf("START : t_data.c : init_rgb()\n");
	c_reset();
	test_init_rgb_01();
	c_yellow();
	printf("END : t_data.c : init_rgb()\n");
	c_reset();

	c_cyan();
	printf("-------------------------------------\n");
	c_reset();

	c_yellow();
	printf("START : t_data.c : new_data()\n");
	c_reset();
	test_new_data_01();
	c_yellow();
	printf("END : t_data.c : new_data()\n");
	c_reset();
}

void	test_parser_utils(void)
{
	c_yellow();
	printf("START : parser_utils.c : remove_id()\n");
	c_reset();
	test_remove_id_01();
	c_yellow();
	printf("END : parser_utils.c : remove_id()\n");
	c_reset();

	c_cyan();
	printf("-------------------------------------\n");
	c_reset();

	c_yellow();
	printf("START : parser_utils.c : get_id_length()\n");
	c_reset();
	test_get_id_length_01();
	test_get_id_length_02();
	test_get_id_length_03();
	test_get_id_length_04();
	test_get_id_length_05();
	test_get_id_length_06();
	test_get_id_length_07();
	test_get_id_length_08();
	test_get_id_length_09();
	c_yellow();
	printf("END : parser_utils.c : get_id_length()\n");
	c_reset();

	c_cyan();
	printf("-------------------------------------\n");
	c_reset();

	c_yellow();
	printf("START : parser_utils.c : parse_path()\n");
	c_reset();
	test_parse_path_01();
	test_parse_path_02();
	test_parse_path_03();
	test_parse_path_04();
	test_parse_path_05();
	test_parse_path_06();
	c_yellow();
	printf("END : parser_utils.c : parse_path()\n");
	c_reset();
}

void	test_t_data_utils(void)
{
	c_yellow();
	printf("START : t_data_utils.c : get_resolution_number()\n");
	c_reset();
	test_get_resolution_number_01();
	test_get_resolution_number_02();
	c_yellow();
	printf("END : t_data_utils.c : get_resolution_number()\n");
	c_reset();
}

int		main(void)
{
	c_cyan();
	printf("START : input.c\n");
	c_reset();

	test_input();

	c_cyan();
	printf("END : input.c\n");
	c_reset();

	c_cyan();
	printf("-------------------------------------\n");
	c_reset();

	c_cyan();
	printf("START : t_data.c\n");
	c_reset();

	test_t_data();

	c_cyan();
	printf("END : t_data.c\n");
	c_reset();

	c_cyan();
	printf("-------------------------------------\n");
	c_reset();

	c_cyan();
	printf("START : parser_utils.c\n");
	c_reset();

	test_parser_utils();

	c_cyan();
	printf("END : parser_utils.c\n");
	c_reset();

	c_cyan();
	printf("-------------------------------------\n");
	c_reset();

	c_cyan();
	printf("START : t_data_utils.c\n");
	c_reset();

	test_t_data_utils();

	c_cyan();
	printf("END : t_data_utils.c\n");
	c_reset();

	return (0);
}
