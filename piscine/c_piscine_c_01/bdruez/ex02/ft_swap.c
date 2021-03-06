/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 19:04:07 by bdruez            #+#    #+#             */
/*   Updated: 2019/08/29 19:13:20 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int *c;
	*c = *a;
	*a = *b;
	*b = *c;
}

int main() {
	int *a;
	int *b;

	*a = 42;
	*b = 21;

	printf("A : %d\n", *a);
	printf("B : %d\n", *b);

	ft_swap(a, b);

	printf("A : %d\n", *a);
	printf("B : %d\n", *b);
}
