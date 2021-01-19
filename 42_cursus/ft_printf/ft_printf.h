/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 14:13:23 by bdruez            #+#    #+#             */
/*   Updated: 2020/03/10 09:37:57 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

# define HEX_LOWER 0
# define HEX_UPPER 1

# define FALSE 0
# define TRUE 1

/*
**struct definitions
*/
typedef struct	s_data
{
	int		zeros;
	int		left_justify;
	int		min_width;
	int		has_dot;
	int		dot_value;
	char	conv;
}				t_data;

/*
**ft_printf.c
*/
int				call_display(va_list ap, t_data data);
int				check_char(const char **to_print, va_list ap);
int				ft_printf(const char *to_print, ...);

/*
**ft_printf_utils.c
*/
int				is_conv(int c);
int				is_flag(int c);

/*
**length_utils.c
*/
int				get_int_len(int nbr);
int				get_ulong_len(unsigned long nbr);
int				get_uint_len(unsigned int nbr);
int				get_hex_len(unsigned int nbr);
int				get_ptr_len(unsigned long nbr);

/*
**t_data.c
*/
t_data			ft_new_data(void);
int				ft_get_nbr(va_list ap, const char **str);
t_data			ft_get_flags(t_data data, const char **to_print);
t_data			ft_get_data_info(va_list ap, const char **to_print);
t_data			ft_check_and_set_min_width(t_data data, int min_width);

/*
**display_*_.c
*/
int				display_id_conv(va_list ap, t_data data);
int				get_abs_nbr_len(int nbr);
void			print_abs_nbr(int nbr);
int				display_c_conv(va_list ap, t_data data);
int				display_wrong_conv(va_list ap, t_data data);
int				display_s_conv(va_list ap, t_data data);
int				display_p_conv(va_list ap, t_data data);
int				display_u_conv(va_list ap, t_data data);
int				display_x_conv(va_list ap, int is_upper, t_data data);

/*
**display_id_printing.c
*/
int				get_total_len(t_data data, int nbr, int nbr_len);
int				print_id_left_no_prec(t_data data, int nbr, int nbr_len);
int				print_id_left_prec(t_data data, int nbr, int nbr_len);
int				print_id_right_no_prec(t_data data, int nbr, int nbr_len);
int				print_id_right_prec(t_data data, int nbr, int nbr_len);

/*
**display_u_printing.c
*/
int				print_u_left_no_prec(t_data data, unsigned int nbr);
int				print_u_left_prec(t_data data, unsigned int nbr);
int				print_u_right_no_prec(t_data data, unsigned int nbr);
int				print_u_right_prec(t_data data, unsigned int nbr);

/*
**display_x_printing.c
*/
int				print_x_left_no_prec(t_data data, unsigned int hex,
		int is_upper);
int				print_x_left_prec(t_data data, unsigned int hex, int is_upper);
int				print_x_right_no_prec(t_data data, unsigned int hex,
		int is_upper);
int				print_x_right_prec(t_data data, unsigned int hex, int is_upper);

#endif
