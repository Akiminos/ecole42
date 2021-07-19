/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdruez <bdruez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 15:26:38 by bdruez            #+#    #+#             */
/*   Updated: 2021/07/16 15:26:40 by bdruez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	t_stack_ele *ele1 = new_stack_ele(42);
	printf("ele1 : value = %d, prev = %p, next = %p\n",
			ele1->value, ele1->prev, ele1->next);
	t_stack_ele *ele2 = new_stack_ele(50);
	printf("ele2 : value = %d, prev = %p, next = %p\n",
			ele2->value, ele2->prev, ele2->next);
	t_stack_ele *ele3 = new_stack_ele(13);
	printf("ele3 : value = %d, prev = %p, next = %p\n",
			ele3->value, ele3->prev, ele3->next);
	t_stack_ele *ele4 = new_stack_ele(42);
	printf("ele4 : value = %d, prev = %p, next = %p\n",
			ele4->value, ele4->prev, ele4->next);
	t_stack_ele *ele5 = new_stack_ele(5);
	printf("ele5 : value = %d, prev = %p, next = %p\n",
			ele5->value, ele5->prev, ele5->next);
	t_stack_ele *ele6 = new_stack_ele(0);
	printf("ele6 : value = %d, prev = %p, next = %p\n",
			ele6->value, ele6->prev, ele6->next);
	printf("---\n");
	t_stack	*stack_a = init_stack();
	add_ele_head(stack_a, ele1);
	add_ele_tail(stack_a, ele2);
	add_ele_tail(stack_a, ele3);
	add_ele_head(stack_a, ele4);
	add_ele_head(stack_a, ele5);
	add_ele_tail(stack_a, ele6);
	print_stack(stack_a);
	printf("---\n");
	printf("Swap\n");
	swap(stack_a);
	print_stack(stack_a);
	printf("---\n");
	printf("Swap\n");
	swap(stack_a);
	print_stack(stack_a);
	printf("---\n");
	printf("Rotate\n");
	rotate(stack_a);
	print_stack(stack_a);
	printf("---\n");
	printf("Rotate\n");
	rotate(stack_a);
	print_stack(stack_a);
	printf("---\n");
	printf("Swap\n");
	swap(stack_a);
	print_stack(stack_a);
	printf("---\n");
	printf("Rotate\n");
	rotate(stack_a);
	print_stack(stack_a);
	printf("---\n");
	printf("RevRotate\n");
	reverse_rotate(stack_a);
	print_stack(stack_a);
	printf("---\n");
	printf("RevRotate\n");
	reverse_rotate(stack_a);
	print_stack(stack_a);
	printf("---\n");
	printf("RevRotate\n");
	reverse_rotate(stack_a);
	print_stack(stack_a);
	printf("---\n");
	printf("RevRotate\n");
	reverse_rotate(stack_a);
	print_stack(stack_a);
	printf("---\n");
	printf("---\n");
	printf("---\n");
	
	t_stack *stack_b = init_stack();
	
	printf("---\n");
	printf("Push B\n");
	push(stack_a, stack_b);
	printf("A---\n");
	print_stack(stack_a);
	printf("B---\n");
	print_stack(stack_b);
	printf("---\n");
	printf("Push B\n");
	push(stack_a, stack_b);
	printf("A---\n");
	print_stack(stack_a);
	printf("B---\n");
	print_stack(stack_b);
	printf("---\n");
	printf("Push B\n");
	push(stack_a, stack_b);
	printf("A---\n");
	print_stack(stack_a);
	printf("B---\n");
	print_stack(stack_b);
	printf("---\n");
	printf("Push B\n");
	push(stack_a, stack_b);
	printf("A---\n");
	print_stack(stack_a);
	printf("B---\n");
	print_stack(stack_b);
	printf("---\n");
	printf("Push B\n");
	push(stack_a, stack_b);
	printf("A---\n");
	print_stack(stack_a);
	printf("B---\n");
	print_stack(stack_b);
	printf("---\n");
	printf("Push B\n");
	push(stack_a, stack_b);
	printf("A---\n");
	print_stack(stack_a);
	printf("B---\n");
	print_stack(stack_b);
	printf("---\n");
	printf("Push B\n");
	push(stack_a, stack_b);
	printf("A---\n");
	print_stack(stack_a);
	printf("B---\n");
	print_stack(stack_b);
	printf("---\n");
	printf("Push A\n");
	push(stack_b, stack_a);
	printf("A---\n");
	print_stack(stack_a);
	printf("B---\n");
	print_stack(stack_b);
	printf("---\n");
	printf("Push A\n");
	push(stack_b, stack_a);
	printf("A---\n");
	print_stack(stack_a);
	printf("B---\n");
	print_stack(stack_b);
	printf("---\n");
	printf("Push A\n");
	push(stack_b, stack_a);
	printf("A---\n");
	print_stack(stack_a);
	printf("B---\n");
	print_stack(stack_b);
	printf("---\n");
	printf("Push A\n");
	push(stack_b, stack_a);
	printf("A---\n");
	print_stack(stack_a);
	printf("B---\n");
	print_stack(stack_b);
	printf("---\n");
	printf("Push A\n");
	push(stack_b, stack_a);
	printf("A---\n");
	print_stack(stack_a);
	printf("B---\n");
	print_stack(stack_b);
	printf("---\n");
	printf("Push A\n");
	push(stack_b, stack_a);
	printf("A---\n");
	print_stack(stack_a);
	printf("B---\n");
	print_stack(stack_b);
	printf("---\n");
	printf("Push A\n");
	push(stack_b, stack_a);
	printf("A---\n");
	print_stack(stack_a);
	printf("B---\n");
	print_stack(stack_b);

	free_stack(stack_a);
	free_stack(stack_b);
	printf("------------------------\n");
	printf("TRUE = %d, FALSE = %d\n", TRUE, FALSE);
	printf("num : '%s', is_number : %d\n", "123123", is_number("123123"));
	printf("num : '%s', is_number : %d\n", "-123123", is_number("-123123"));
	printf("num : '%s', is_number : %d\n", "", is_number(""));
	printf("num : '%s', is_number : %d\n", "1", is_number("1"));
	printf("num : '%s', is_number : %d\n", "-", is_number("-"));
	printf("num : '%s', is_number : %d\n", "Q", is_number("Q"));
	printf("num : '%s', is_number : %d\n", "123R23", is_number("123R23"));
	printf("num : '%s', is_number : %d\n", "-0", is_number("-0"));

	printf("------------------------\n");
	printf("TRUE = %d, FALSE = %d\n", TRUE, FALSE);
	int	res_1 = 0, state_1 = TRUE;
	char *num_1 = "-123456";
	res_1 = convert_number(num_1, &state_1);
	printf("s_num = '%s', num = %d, state = '%s'\n", num_1, res_1,
			(state_1 == TRUE ? "TRUE" : "FALSE"));
	res_1 = 0;
	state_1 = TRUE;
	num_1 = "123456";
	res_1 = convert_number(num_1, &state_1);
	printf("s_num = '%s', num = %d, state = '%s'\n", num_1, res_1,
			(state_1 == TRUE ? "TRUE" : "FALSE"));
	res_1 = 0;
	state_1 = TRUE;
	num_1 = "12345678910111213";
	res_1 = convert_number(num_1, &state_1);
	printf("s_num = '%s', num = %d, state = '%s'\n", num_1, res_1,
			(state_1 == TRUE ? "TRUE" : "FALSE"));
	res_1 = 0;
	state_1 = TRUE;
	num_1 = "";
	res_1 = convert_number(num_1, &state_1);
	printf("s_num = '%s', num = %d, state = '%s'\n", num_1, res_1,
			(state_1 == TRUE ? "TRUE" : "FALSE"));
	res_1 = 0;
	state_1 = TRUE;
	num_1 = "0";
	res_1 = convert_number(num_1, &state_1);
	printf("s_num = '%s', num = %d, state = '%s'\n", num_1, res_1,
			(state_1 == TRUE ? "TRUE" : "FALSE"));
	res_1 = 0;
	state_1 = TRUE;
	num_1 = "-";
	res_1 = convert_number(num_1, &state_1);
	printf("s_num = '%s', num = %d, state = '%s'\n", num_1, res_1,
			(state_1 == TRUE ? "TRUE" : "FALSE"));
	res_1 = 0;
	state_1 = TRUE;
	num_1 = "P";
	res_1 = convert_number(num_1, &state_1);
	printf("s_num = '%s', num = %d, state = '%s'\n", num_1, res_1,
			(state_1 == TRUE ? "TRUE" : "FALSE"));
	res_1 = 0;
	state_1 = TRUE;
	num_1 = "2147483647";
	res_1 = convert_number(num_1, &state_1);
	printf("s_num = '%s', num = %d, state = '%s'\n", num_1, res_1,
			(state_1 == TRUE ? "TRUE" : "FALSE"));
	res_1 = 0;
	state_1 = TRUE;
	num_1 = "2147483648";
	res_1 = convert_number(num_1, &state_1);
	printf("s_num = '%s', num = %d, state = '%s'\n", num_1, res_1,
			(state_1 == TRUE ? "TRUE" : "FALSE"));
	res_1 = 0;
	state_1 = TRUE;
	num_1 = "-2147483648";
	res_1 = convert_number(num_1, &state_1);
	printf("s_num = '%s', num = %d, state = '%s'\n", num_1, res_1,
			(state_1 == TRUE ? "TRUE" : "FALSE"));
	res_1 = 0;
	state_1 = TRUE;
	num_1 = "-2147483649";
	res_1 = convert_number(num_1, &state_1);
	printf("s_num = '%s', num = %d, state = '%s'\n", num_1, res_1,
			(state_1 == TRUE ? "TRUE" : "FALSE"));
	res_1 = 0;
	state_1 = TRUE;
	num_1 = "-21474836490";
	res_1 = convert_number(num_1, &state_1);
	printf("s_num = '%s', num = %d, state = '%s'\n", num_1, res_1,
			(state_1 == TRUE ? "TRUE" : "FALSE"));
	res_1 = 0;
	state_1 = TRUE;
	num_1 = " -2147483648";
	res_1 = convert_number(num_1, &state_1);
	printf("s_num = '%s', num = %d, state = '%s'\n", num_1, res_1,
			(state_1 == TRUE ? "TRUE" : "FALSE"));
	res_1 = 0;
	state_1 = TRUE;
	num_1 = "--2147483648";
	res_1 = convert_number(num_1, &state_1);
	printf("s_num = '%s', num = %d, state = '%s'\n", num_1, res_1,
			(state_1 == TRUE ? "TRUE" : "FALSE"));
	printf("------------------------\n");
	t_stack *stack_6 = NULL;
	char	**argv_1 = NULL;
	argv_1 = ft_calloc(sizeof(*argv_1), 6);
	argv_1[0] = ft_strdup("./push_swap");
	argv_1[1] = ft_strdup("20");
	argv_1[2] = ft_strdup("-22230");
	argv_1[3] = ft_strdup("4000000");
	argv_1[4] = ft_strdup("-50");
	argv_1[5] = ft_strdup("0");
	int		argc_1 = 6;
	int		state_2 = TRUE;
	stack_6 = create_stack_from_input(argc_1, argv_1, &state_2);
	if (state_2 == TRUE)
	{
		print_stack(stack_6);
		//free_and_exit_message(stack_6, NULL, "Wrong Input");
		free_stack(stack_6);
	}

	while(1){}

	return (0);
}
