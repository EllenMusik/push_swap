/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target_position.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 17:41:35 by esteiner          #+#    #+#             */
/*   Updated: 2026/03/09 17:44:38 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_target_positions(t_swag **stack_a, t_swag **stack_b)
{
	t_swag	*current_b;
	int		max_index_in_a;
	int		smallest_pos_in_a;

	max_index_in_a = get_max_index(stack_a);
	smallest_pos_in_a = get_position_of_lowest(stack_a);
	current_b = *stack_b;
	while (current_b)
	{
		if (current_b->index > max_index_in_a)
			current_b->target_pos = smallest_pos_in_a;
		else
			current_b->target_pos = find_target_for_value(stack_a,
					current_b->index);
		if (current_b == list_find_last(stack_b))
			break ;
		current_b = current_b->next;
	}
}

int	find_target_for_value(t_swag **stack_a, long index_b)
{
	t_swag	*current_a;

	if (!*stack_a)
		return (0);
	current_a = *stack_a;
	while (current_a)
	{
		if (current_a->index < index_b && current_a->next->index > index_b)
			return (current_a->next->position);
		if (current_a->index > current_a->next->index)
		{
			if (index_b > current_a->index || index_b < current_a->next->index)
				return (current_a->next->position);
		}
		if (current_a == list_find_last(stack_a))
			break ;
		current_a = current_a->next;
	}
	return (0);
}

void	update_positions(t_swag **stack_a, t_swag **stack_b)
{
	int		position;
	t_swag	*current;

	position = 0;
	current = *stack_a;
	while (current)
	{
		current->position = position;
		position++;
		if (current == list_find_last(stack_a))
			break ;
		current = current->next;
	}
	current = *stack_b;
	position = 0;
	while (current)
	{
		current->position = position;
		position++;
		if (current == list_find_last(stack_b))
			break ;
		current = current->next;
	}
}

int	get_max_index(t_swag **stack_a)
{
	t_swag	*current;
	int		max_index;

	current = *stack_a;
	max_index = current->index;
	while (current)
	{
		if (current->index > max_index)
			max_index = current->index;
		if (current == list_find_last(stack_a))
			break ;
		current = current->next;
	}
	return (max_index);
}

int	get_position_of_lowest(t_swag **stack_a)
{
	t_swag	*current;
	t_swag	*lowest_position;

	current = *stack_a;
	lowest_position = current;
	while (current)
	{
		if (current->index < lowest_position->index)
			lowest_position = current;
		if (current == list_find_last(stack_a))
			break ;
		current = current->next;
	}
	return (lowest_position->position);
}
