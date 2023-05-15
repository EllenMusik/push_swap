/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:54:59 by esteiner          #+#    #+#             */
/*   Updated: 2023/05/15 22:20:24 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorting_commands(t_swag **stack_a)
{
	t_swag	**stack_b;

	stack_b = malloc(sizeof(t_swag *));
	*stack_b = NULL;
	print_stack_a_and_b(stack_a, stack_b);
	push_a_to_b(stack_a, stack_b);
	push_a_to_b(stack_a, stack_b);
	print_stack_a_and_b(stack_a, stack_b);
	rotate_both(stack_a, stack_b);
	print_stack_a_and_b(stack_a, stack_b);
	rotate_a(stack_a);
	rotate_b(stack_b);
	print_stack_a_and_b(stack_a, stack_b);
	return (0);
}

void	print_stack_a_and_b(t_swag **stack_a, t_swag **stack_b)
{
	t_swag	*test_node;
	t_swag	*last_node;

	last_node = list_find_last(*stack_a);
	test_node = *stack_a;
	while (test_node && test_node != last_node)
	{
		printf("a: %i\n", test_node->number);
		test_node = test_node->next;
	}
	printf("%i\n\n", test_node->number);
	last_node = list_find_last(*stack_b);
	test_node = *stack_b;
	while (test_node && test_node != last_node)
	{
		printf("b: %i\n", test_node->number);
		test_node = test_node->next;
	}
	printf("%i\n\n", test_node->number);
}

void	push_a_to_b(t_swag **stack_a, t_swag **stack_b)
{
	push_stack_1_to_2(stack_a, stack_b);
	write(1, "pb\n", 3);
}

void	push_b_to_a(t_swag **stack_a, t_swag **stack_b)
{
	push_stack_1_to_2(stack_b, stack_a);
	write(1, "pa\n", 3);
}

int	push_stack_1_to_2(t_swag **stack_1, t_swag **stack_2)
{
	t_swag	*temp_node;
	t_swag	*temp_new_first;
	t_swag	*temp_last;

	if (!*stack_1)
		return (0);
	temp_node = *stack_1;
	temp_new_first = temp_node->next;
	temp_last = temp_node->previous;
	list_add_front(stack_2, temp_node);
	*stack_1 = temp_new_first;
	temp_last->next = temp_new_first;
	temp_new_first->previous = temp_last;
	return (0);
}

void	list_add_front(t_swag **lst, t_swag *new_first)
{
	t_swag	*old_first;
	t_swag	*last_node;

	old_first = *lst;
	last_node = list_find_last(*lst);
	if (*lst)
	{
		old_first->previous = new_first;
		last_node->next = new_first;
		new_first->next = old_first;
		new_first->previous = last_node;
	}
	else
	{
		new_first->next = new_first;
		new_first->previous = new_first;
	}
	*lst = new_first;
}
