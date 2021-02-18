/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cube3d.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 15:02:19 by bdruez            #+#    #+#             */
/*   Updated: 2021/02/17 17:53:04 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_CUBE3D_H
# define TEST_CUBE3D_H

# include <stdio.h>
# include <assert.h>

/*
**	Function declaration ---------------------------------------------------  **
*/

/*
**	t_color.c
*/
void	c_red(void);
void	c_green(void);
void	c_yellow(void);
void	c_blue(void);
void	c_magenta(void);
void	c_cyan(void);
void	c_reset(void);

/*
**	test_input.c
*/
void	test_add_char_01(void);
void	test_add_char_02(void);
void	test_add_char_03(void);
void	test_add_char_04(void);
void	test_add_char_05(void);
void	test_add_char_06(void);

void	test_get_line_01(void);
void	test_get_line_02(void);
void	test_get_line_03(void);

/*
**	test_parser_utils.c
*/
void	test_remove_id_01(void);

void	test_get_id_length_01(void);
void	test_get_id_length_02(void);
void	test_get_id_length_03(void);
void	test_get_id_length_04(void);
void	test_get_id_length_05(void);
void	test_get_id_length_06(void);
void	test_get_id_length_07(void);
void	test_get_id_length_08(void);
void	test_get_id_length_09(void);

void	test_parse_path_01(void);
void	test_parse_path_02(void);
void	test_parse_path_03(void);
void	test_parse_path_04(void);
void	test_parse_path_05(void);
void	test_parse_path_06(void);

/*
**	test_t_data.c
*/
void	test_init_rgb_01(void);

void	test_new_data_01(void);

/*
**	test_t_data_utils.c
*/
void	test_get_resolution_number_01(void);

#endif
