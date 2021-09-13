/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:34:53 by bdruez            #+#    #+#             */
/*   Updated: 2021/09/13 21:29:13 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(char *number)
{
	int	is_digit;
	int	iter;
	int	size;

	is_digit = 1;
	iter = 0;
	size = ft_strlen(number);
	if (size < 1 || size > 14)
		return (FALSE);
	else if (size == 1 && !ft_isdigit(number[0]))
		return (FALSE);
	else
	{
		if (number[0] == '-')
			iter++;
		while (iter < size)
		{
			is_digit = ft_isdigit(number[iter]);
			if (!is_digit)
				return (FALSE);
			iter++;
		}
	}
	return (TRUE);
}

int	ascii_to_int(const char *number, int *status)
{
	size_t		iter;
	long long	res;
	size_t		sign;

	iter = 0;
	res = 0;
	sign = 1;
	*status = TRUE;
	if (number[iter] == '-')
	{
		sign = -1;
		iter++;
	}
	while (iter < ft_strlen(number))
	{
		res *= 10;
		res += (number[iter] - 48);
		iter++;
	}
	res *= sign;
	if (res < -2147483648 || res > 2147483647)
		*status = FALSE;
	return ((int)res);
}

int	convert_number(char *number, int *status)
{
	int	res;

	res = 0;
	*status = is_number(number);
	if (*status == FALSE)
		return (-1);
	res = ascii_to_int(number, status);
	if (*status == FALSE)
		return (-1);
	return (res);
}

t_stack	*create_stack_from_input(int argc, char **argv, int *status)
{
	t_stack	*stack;
	int		iter;
	int		number;

	stack = init_stack();
	iter = 1;
	number = 0;
	*status = TRUE;
	while (iter < argc)
	{
		number = convert_number(argv[iter], status);
		if (*status == FALSE)
		{
			free_stack(stack);
			return (NULL);
		}
		add_ele_tail(stack, new_stack_ele(number));
		iter++;
	}
	return (stack);
}
