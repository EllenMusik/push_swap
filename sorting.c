/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:21:23 by esteiner          #+#    #+#             */
/*   Updated: 2023/05/19 20:38:58 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorting_commands(t_swag **stack_a, t_swag **stack_b)
{
	get_index(stack_a);
	if (3 == list_node_count(*stack_a))
	{
		sorting_when_3_numbers(stack_a);
		print_stack_a_and_b(stack_a, stack_b);
		return (0);
	}
	if (2 == list_node_count(*stack_a))
	{
		swap_a(stack_a);
		print_stack_a_and_b(stack_a, stack_b);
		return (0);
	}
	if (5 >= list_node_count(*stack_a))
	{
		sort_5(stack_a, stack_b);
		//print_stack_a_and_b(stack_a, stack_b);
		return (0);
	}
	//print_stack_a_and_b(stack_a, stack_b);
	return (0);
}

int	sort_5(t_swag **stack_a, t_swag **stack_b)
{
	push_a_to_b(stack_a, stack_b);
	if (3 == list_node_count(*stack_a))
		sorting_when_3_numbers(stack_a);
	else
	{
		sort_5(stack_a, stack_b);
		return (0);
	}
	sort_5_2(stack_a, stack_b);
	return (0);
}

int	sort_5_2(t_swag **stack_a, t_swag **stack_b)
{
	t_swag	*temp_node1;
	t_swag	*new_node;
	t_swag	*last_node;

	temp_node1 = *stack_a;
	new_node = *stack_b;
	last_node = temp_node1->previous;
	while (new_node)
	{
		while (temp_node1 != last_node)
		{
			if (new_node->number < temp_node1->number)
				push_b_to_a(stack_a, stack_b);
			else
				rotate_a(stack_a);
			print_stack_a_and_b(stack_a, stack_b);
			temp_node1 = *stack_a;
		}
		if (new_node->number > temp_node1->number)
		{
			rotate_a(stack_a);
			push_b_to_a(stack_a, stack_b);
			last_node = new_node;
		}
		while (*stack_a != last_node->next)
			reverse_rotate_a(stack_a);
		new_node = *stack_b;
	}
	print_stack_a_and_b(stack_a, stack_b);
	return (0);
}

int	is_it_already_sorted(t_swag **stack_a)
{
	t_swag	*temp_node;
	t_swag	*last_node;
	int		previous_number;

	temp_node = *stack_a;
	last_node = list_find_last(*stack_a);
	while (temp_node && temp_node != last_node)
	{
		if (previous_number && temp_node->number < previous_number)
			return (1);
		previous_number = temp_node->number;
		temp_node = temp_node->next;
	}
	if (temp_node && previous_number && temp_node->number < previous_number)
		return (1);
	printf("already sorted!\n");
	return (0);
}

int	sorting_when_3_numbers(t_swag **stack_a)
{
	t_swag	*tmp1;
	t_swag	*tmp2;
	t_swag	*tmp3;

	tmp1 = *stack_a;
	tmp2 = tmp1->next;
	tmp3 = tmp2->next;
	if (tmp1->number < tmp2->number && tmp1->number < tmp3->number)
	{
		reverse_rotate_a(stack_a);
		swap_a(stack_a);
	}
	else if (tmp1->number > tmp2->number && tmp2->number > tmp3->number)
	{
		rotate_a(stack_a);
		swap_a(stack_a);
	}
	else
		sorting_3_2(tmp1, tmp2, tmp3, stack_a);
	return (0);
}

int	sorting_3_2(t_swag *tmp1, t_swag *tmp2, t_swag *tmp3, t_swag **stack_a)
{
	if (tmp1->number > tmp2->number && tmp2->number < tmp3->number
		&& tmp1->number > tmp3->number)
		rotate_a(stack_a);
	else if (tmp1->number < tmp2->number && tmp2->number > tmp3->number
		&& tmp1->number > tmp3->number)
		reverse_rotate_a(stack_a);
	else if (tmp1->number > tmp2->number && tmp2->number < tmp3->number
		&& tmp1->number < tmp3->number)
		swap_a(stack_a);
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
	if (test_node)
		printf("a: %i\n\n", test_node->number);
	last_node = list_find_last(*stack_b);
	test_node = *stack_b;
	while (test_node && test_node != last_node)
	{
		printf("b: %i\n", test_node->number);
		test_node = test_node->next;
	}
	if (test_node)
		printf("b: %i\n\n", test_node->number);
}

int list_node_count(t_swag *stack)
{
	t_swag	*temp_node;
	t_swag	*last_node;
	int		counter;

	temp_node = stack;
	last_node = stack->previous;
	counter = 0;
	while (temp_node && temp_node != last_node)
	{
		temp_node = temp_node->next;
		counter++;
	}
	if (temp_node)
		counter++;
	return (counter);
}
