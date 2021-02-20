/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 09:54:28 by bdruez            #+#    #+#             */
/*   Updated: 2021/02/18 13:53:08 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <fcntl.h>
# include <stdio.h>
# include "libft.h"

/*
** ----- Enums -----------------------------------------------------------------
*/

/*
**	enum for the identifiers during parsing
*/
enum			e_id
{
	ID_ERR = -1,
	ID_R,
	ID_NO,
	ID_SO,
	ID_WE,
	ID_EA,
	ID_S,
	ID_F,
	ID_C
};

/*
**	enum for error identification and management 
*/
enum			e_err
{
	SUCCESS = 0,
	ERR_PARSING_ERROR = 10,
	ERR_READ_ERROR,
	ERR_WRONG_RESOLUTION,
	ERR_OUT_OF_BOUND_RGB,
	ERR_OUT_OF_BOUND_RESOLUTION,
	ERR_ID_ERROR = 20,
	ERR_WRONG_ID,
	ERR_WRONG_VALUES,
	ERR_MALLOC_ERROR = 30,
	ERR_MALLOC_FAILURE,
	ERR_NULL_POINTER_FREE_ATTEMPT,
	ERR_PARAM_ERROR = 40
};

/*
** ----- Structures ------------------------------------------------------------
*/

/*
**	structure for storing a path and it's id
*/
typedef struct	s_data
{
	int		width;
	int		height;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	char	*s_path;
	int		*f_rgb;
	int		*c_rgb;
}				t_data;

/*
** ----- Functions Declarations ------------------------------------------------
*/

/*
**	input.c
*/
int				open_map(char *path);
void			add_char(char **cur, char *to_add);
char			*get_line(int fd);

/*
**	parser.c
*/
int				check_id(char *line);
int				get_parser(char *line, t_data *data, int id);
int				parse_line(char *line, t_data *data);

/*
**	parser_utils.c
*/
unsigned int	get_id_length(int id);
int				remove_id(char **line, int id);
int				parse_path(t_data *data, char **line, int id);
int				parse_resolution(t_data *data, char **line, int id);
int				parse_rgb(t_data *data, char **line, int id);

/*
**	t_data.c
*/
int				*init_rgb(void);
void			add_rgb(t_data *data, int *rgb, int id);
t_data			new_data(void);
void			free_data(t_data *data);
void			add_path(t_data *data, char *line, int id);

/*
**	t_data_utils.c
*/
int				add_resolution(t_data *data, char **line);
int				get_resolution_number(char *line, char **num, int *start);

#endif
