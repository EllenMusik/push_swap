/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 17:28:29 by esteiner          #+#    #+#             */
/*   Updated: 2026/03/09 18:22:59 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	cost_calculate_sort(t_swag **stack_a, t_swag **stack_b)
{
	push_all_but_3_b(stack_a, stack_b);
	if (is_it_already_sorted(stack_a) != 0)
		sorting_when_3_numbers(stack_a);
	while (*stack_b)
	{
		update_positions(stack_a, stack_b);
		find_target_positions(stack_a, stack_b);
		calculate_each_node_cost(stack_a, stack_b);
		execute_lowest_cost_move(stack_a, stack_b);
		push_b_to_a(stack_a, stack_b);
	}
	if (use_reverse_rotate(stack_a, get_position_of_lowest(stack_a)))
	{
		while ((*stack_a)->index != 1)
			reverse_rotate_a(stack_a);
	}
	else
	{
		while ((*stack_a)->index != 1)
			rotate_a(stack_a);
	}
	return (0);
}

void    push_all_but_3_b(t_swag **stack_a, t_swag **stack_b)
{
    int    total_nodes;
    int    pushed_count;
    int    median;

    total_nodes = list_node_count(stack_a);
    pushed_count = 0;
    median = total_nodes / 2;
    while (total_nodes - pushed_count > 3)
    {
        if ((*stack_a)->index < median)
        {
            push_a_to_b(stack_a, stack_b);
            rotate_b(stack_b);
        }
        else
            push_a_to_b(stack_a, stack_b);
        pushed_count++;
    }
}

void	check_for_rr_and_rrr(t_swag **stack_a, t_swag **stack_b,
		t_swag *current_b)
{
	if (use_reverse_rotate(stack_a, current_b->target_pos))
		current_b->cost_a = list_node_count(stack_a) - current_b->cost_a;
	if (use_reverse_rotate(stack_b, current_b->position))
		current_b->cost_b = list_node_count(stack_b) - current_b->cost_b;
}

void	calculate_each_node_cost(t_swag **stack_a, t_swag **stack_b)
{
	t_swag	*current_b;

	current_b = *stack_b;
	while (current_b)
	{
		current_b->cost_a = current_b->target_pos;
		current_b->cost_b = current_b->position;
		check_for_rr_and_rrr(stack_a, stack_b, current_b);
		if (use_reverse_rotate(stack_b,
				current_b->position) == use_reverse_rotate(stack_a,
				current_b->target_pos))
		{
			if (current_b->cost_a > current_b->cost_b)
				current_b->total_cost = current_b->cost_a;
			else
				current_b->total_cost = current_b->cost_b;
		}
		else
			current_b->total_cost = current_b->cost_a + current_b->cost_b;
		if (current_b == list_find_last(stack_b))
			break ;
		current_b = current_b->next;
	}
}

int	use_reverse_rotate(t_swag **stack, int position)
{
	if (position > list_node_count(stack) / 2)
		return (1);
	return (0);
}
