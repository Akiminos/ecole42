/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:32:59 by bdruez            #+#    #+#             */
/*   Updated: 2021/09/19 23:52:52 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <math.h>
# include "mlx.h"
# include "mlx_int.h"
# include "libft.h"

/*
** ----- Defines ---------------------------------------------------------------
*/
# define WIN_W 1280
# define WIN_H 720

# define DIV_VAL 32
# define MAX_ITER 80

/*
** ----- Enums -----------------------------------------------------------------
*/

/*
**	Keys' code numbers for hooks
*/
enum e_key_values
{
	K_ESC			=	65307,
	K_ENTER			=	65293,
	K_LEFT			=	65361,
	K_RIGHT			=	65363,
	K_UP			=	65362,
	K_DOWN			=	65364,
	K_SPACE			=	32,
	K_O				=	111,
	K_L				=	108,
	K_I				=	105,
	K_K				=	107,
	M_WHEEL_UP		=	4,
	M_WHEEL_DOWN	=	5
};

/*
**	Fractal types
*/
enum e_fractal
{
	MANDELBROT = 0,
	JULIA = 1
};

/*
** ----- Structures ------------------------------------------------------------
*/

/*
**	Complex number structure
*/
typedef struct s_complex
{
	double	rl;
	double	im;
}	t_complex;

/*
**	Color management structure
*/
typedef struct s_color
{
	int		t;
	int		r;
	double	r_prime;
	int		g;
	double	g_prime;
	int		b;
	double	b_prime;
	double	c;
	double	x;
	double	m;
	double	h;
	double	s;
	double	v;
	int		color;
}	t_color;

/*
**	Parameters for the current "view state" of the fractal
*/
typedef struct s_view
{
	double	x_min;
	double	x_max;
	double	x_off;
	double	y_min;
	double	y_max;
	double	y_off;
	double	zoom;
}	t_view;

/*
**	Image info storage structure
*/
typedef struct s_image
{
	void	*p_img;
	char	*buffer;
	int		bpp;
	int		size_line;
	int		endian;
}	t_image;

/*
**	Main data storage structure
*/
typedef struct s_data
{
	int			fractal_type;
	double		range;
	void		*p_mlx;
	void		*p_win;
	char		*win_name;
	t_image		*image;
	t_view		*view;
}	t_data;

/*
** ----- Function prototypes ---------------------------------------------------
*/

/*
**	color_convert.c
*/
int			create_trgb(int t, int r, int g, int b);
int			get_t(int trgb);
int			get_r(int trgb);
int			get_g(int trgb);
int			get_b(int trgb);

/*
**	draw.c
*/
int			draw_image(t_data *data);

/*
**	exit_management.c
*/
void		free_and_exit(t_data **data, char *error_msg, int error_code);
void		free_and_exit_instruction(t_data **data);

/*
**	hook.c
*/
int			hook_key_pressed(int key, t_data *data);
int			hook_mouse(int mouse_input, int x, int y, t_data *data);

/*
**	hsv_to_trgb.c
*/
void		hsv_to_trgb(t_color *color);

/*
**	image.c
*/
int			create_image(t_data *data);

/*
**	julia.c
*/
int			julia_pixel(int x, int y, t_data *data);
void		get_julia_view(t_view *view);
t_color		julia_color(int iter);

/*
**	key_zoom.c
*/
int			k_o(t_data *data);
int			k_l(t_data *data);
int			k_enter(t_data *data);

/*
**	key_move.c
*/
int			k_left(t_data *data);
int			k_right(t_data *data);
int			k_up(t_data *data);
int			k_down(t_data *data);

/*
**	mandelbrot.c
*/
int			mandelbrot_pixel(int x, int y, t_view *view);
void		get_mandelbrot_view(t_view *view);
t_color		mandelbrot_color(int iter);

/*
**	mouse_zoom.c
*/
int			m_wheel_up(t_data *data);
int			m_wheel_down(t_data *data);

/*
**	parse.c
*/
int			parse_args(int argc, char **argv, t_data *data);
int			set_fractal_name(char **argv, t_data *data);

/*
**	pixel.c
*/

/*
**	t_color.c
*/
t_color		init_color(void);

/*
**	t_data.c
*/
t_data		*init_data(void);
void		free_data(t_data **data);

/*
**	t_image.c
*/
t_image		*init_image(void);
t_image		*new_image(t_data *data);
void		delete_image(t_data *data);

/*
**	t_view.c
*/
t_view		*init_view(void);
t_view		*new_view(t_data *data);
void		delete_view(t_data *data);
void		reset_view(t_view *view);

/*
**	t_complex.c
*/
t_complex	get_complex_value(int x, int y, t_view *view);
t_complex	get_complex_from_angle(double angle);

/*
**	window.c
*/
void		*init_window(t_data *data);

#endif
