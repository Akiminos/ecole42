/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 17:35:18 by bdruez            #+#    #+#             */
/*   Updated: 2021/07/01 18:36:02 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
**	double linked-list structure for stack management
*/
typedef struct	s_stack
{
	int				value;
	struct s_stack	*prev;
	struct s_stack	*next;
}				t_stack;

/*
** ----- Function prototypes ---------------------------------------------------
*/

/*
**	parser.c
*/

/*
**	t_stack.c
*/
t_stack 	*new_stack(int value);
int			stack_size(t_stack *head);
void		rotate(t_stack *head);
void		r_rotate(t_stack *tail);

#endif
