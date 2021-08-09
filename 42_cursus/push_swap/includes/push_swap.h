/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 11:22:36 by bdruez            #+#    #+#             */
/*   Updated: 2021/08/06 19:33:09 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 17:35:18 by bdruez            #+#    #+#             */
/*   Updated: 2021/07/16 16:03:54 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define TRUE 0
# define FALSE 1

# include <stdio.h>
# include "libft.h"

/*
** ----- Enums -----------------------------------------------------------------
*/

/*
**	instructions enumeration
*/
enum			e_instruction
{
	INIT = 0,
	SA = 10,
	SB,
	SS,
	PA = 20,
	PB,
	RA = 30,
	RB,
	RR,
	RRA = 40,
	RRB,
	RRR
};

/*
** ----- Structures ------------------------------------------------------------
*/

/*
**	double linked-list structure element for stack management
*/
typedef struct	s_stack_ele
{
	int					value;
	struct s_stack_ele	*prev;
	struct s_stack_ele	*next;
}				t_stack_ele;

/*
**	double linked-list structure element for stack management
*/
typedef	struct	s_stack
{
	int					size;
	struct s_stack_ele	*head;
	struct s_stack_ele	*tail;
}				t_stack;

/*
** ----- Function prototypes ---------------------------------------------------
*/

/*
**	doublons.c
*/
void		check_doublons(t_stack *stack);
int			*create_int_array(t_stack *stack, int length);
int			has_doublons(int *array, int length);

/*
**	input.c
*/

/*
**	exit_management.c
*/
void		free_and_exit(t_stack *stack_a, t_stack *stack_b);
void		free_and_exit_message(t_stack *stack_a, t_stack *stack_b,
		const char *message);

/*
**	parser.c
*/
int			is_number(char *number);
int			ascii_to_int(const char *number, int *status);
int			convert_number(char *number, int *status);
t_stack		*create_stack_from_input(int argc, char **argv, int *status);

/*
**	t_stack.c
*/
t_stack		*init_stack(void);
void		add_ele_head(t_stack *stack, t_stack_ele *ele);
void		add_ele_tail(t_stack *stack, t_stack_ele *ele);
void		print_stack(t_stack *stack);
void		free_stack(t_stack *stack);

/*
**	t_stack_utils.c
*/
int			get_lowest_ele_pos(t_stack *stack);

/*
**	t_stack_action.c
*/
void		swap(t_stack *stack);
void		push(t_stack *stack_from, t_stack *stack_to);
void		rotate(t_stack *stack);
void		reverse_rotate(t_stack *stack);

/*
**	t_stack_ele.c
*/
t_stack_ele	*new_stack_ele(int value);
void		free_stack_ele(t_stack_ele *stack_ele);

#endif
