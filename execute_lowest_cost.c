/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_lowest_cost.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 17:40:00 by esteiner          #+#    #+#             */
/*   Updated: 2026/03/09 17:46:29 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_lowest_cost_move(t_swag **stack_a, t_swag **stack_b)
{
	t_swag	*lowest_cost_node;

	lowest_cost_node = find_lowest_cost_node(stack_b);
	do_combined_rotations(stack_a, stack_b, lowest_cost_node);
	while ((*stack_a)->position != lowest_cost_node->target_pos)
	{
		if (use_reverse_rotate(stack_a, lowest_cost_node->target_pos))
			reverse_rotate_a(stack_a);
		else
			rotate_a(stack_a);
	}
	while ((*stack_b)->position != lowest_cost_node->position)
	{
		if (use_reverse_rotate(stack_b, lowest_cost_node->position))
			reverse_rotate_b(stack_b);
		else
			rotate_b(stack_b);
	}
}

void	do_combined_rotations(t_swag **stack_a, t_swag **stack_b,
		t_swag *lowest_cost_node)
{
	if (!use_reverse_rotate(stack_b, lowest_cost_node->position)
		&& !use_reverse_rotate(stack_a, lowest_cost_node->target_pos))
	{
		while ((*stack_a)->position != lowest_cost_node->target_pos
			&& (*stack_b)->position != lowest_cost_node->position)
			rotate_both(stack_a, stack_b);
	}
	if (use_reverse_rotate(stack_b, lowest_cost_node->position)
		&& use_reverse_rotate(stack_a, lowest_cost_node->target_pos))
	{
		while ((*stack_a)->position != lowest_cost_node->target_pos
			&& (*stack_b)->position != lowest_cost_node->position)
			reverse_rotate_both(stack_a, stack_b);
	}
}

t_swag	*find_lowest_cost_node(t_swag **stack_b)
{
	t_swag	*current_b;
	t_swag	*lowest_cost_node;

	current_b = *stack_b;
	lowest_cost_node = current_b;
	while (current_b)
	{
		if (current_b->total_cost < lowest_cost_node->total_cost)
			lowest_cost_node = current_b;
		if (current_b == list_find_last(stack_b))
			break ;
		current_b = current_b->next;
	}
	return (lowest_cost_node);
}
