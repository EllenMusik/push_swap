/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:21:23 by esteiner          #+#    #+#             */
/*   Updated: 2023/06/14 15:30:20 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* checks based on the number of numbers what sortig method should be used */
int	sorting_commands(t_swag **stack_a, t_swag **stack_b)
{
	get_index(stack_a);
	if (2 == list_node_count(*stack_a))
		swap_a(stack_a);
	else if (3 == list_node_count(*stack_a))
		sorting_when_3_numbers(stack_a);
	else if (5 >= list_node_count(*stack_a))
		sort_5(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
	return (0);
}

/* checks if the array is sorted. if it is sorted, it returns 0,
if it is not sorted it returns 1 */
int	is_it_already_sorted(t_swag **stack_a)
{
	t_swag	*temp_node;
	t_swag	*last_node;
	t_swag	*previous_node;

	previous_node = NULL;
	temp_node = *stack_a;
	last_node = list_find_last(*stack_a);
	while (temp_node && temp_node != last_node)
	{
		if (previous_node && temp_node->number < previous_node->number)
			return (1);
		previous_node = temp_node;
		temp_node = temp_node->next;
	}
	if (temp_node && previous_node && temp_node->number < previous_node->number)
		return (1);
	return (0);
}

/* counts the amount of nodes in a list */
int	list_node_count(t_swag *stack)
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

/* uses bits to sort big amounts of numbers.
It starts from the last bit of each number and checks if it is 1 or 0.
if it is 0, it gets pushed to b,
if it is 1, we rotate a and lookat the same bit of the next number.
After the bit is checked for every number,
everything in b gets pushed to a again and the next bit from the back is checked
until the stack_a is completely sorted.
this works, because 1 is bigger than 0,
and so the gigger number stays in a (= gets further down)
and the smaller numbers are put at the front. */
int	radix_sort(t_swag **stack_a, t_swag **stack_b)
{
	int	max_number;
	int	number;
	int	bit_number;
	int	counter;

	max_number = list_node_count(*stack_a);
	bit_number = 0;
	counter = 0;
	while (is_it_already_sorted(stack_a) != 0)
	{
		while (counter < max_number)
		{
			number = (*stack_a)->number;
			if (((number >> bit_number) & 1) == 1)
				rotate_a(stack_a);
			else
				push_a_to_b(stack_a, stack_b);
			counter++;
		}
		while (*stack_b)
			push_b_to_a(stack_a, stack_b);
		bit_number++;
		counter = 0;
	}
	return (0);
}

// void	print_stack_a_and_b(t_swag **stack_a, t_swag **stack_b)
// {
// 	t_swag	*test_node;
// 	t_swag	*last_node;

// 	last_node = list_find_last(*stack_a);
// 	test_node = *stack_a;
// 	while (test_node && test_node != last_node)
// 	{
// 		printf("a: %i\n", test_node->number);
// 		test_node = test_node->next;
// 	}
// 	if (test_node)
// 		printf("a: %i\n\n", test_node->number);
// 	last_node = list_find_last(*stack_b);
// 	test_node = *stack_b;
// 	while (test_node && test_node != last_node)
// 	{
// 		printf("b: %i\n", test_node->number);
// 		test_node = test_node->next;
// 	}
// 	if (test_node)
// 		printf("b: %i\n\n", test_node->number);
// }
