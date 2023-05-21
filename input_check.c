/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:42:57 by esteiner          #+#    #+#             */
/*   Updated: 2023/05/19 19:56:42 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(t_swag **stack_a)
{
	t_swag	**stack_copy;

	stack_copy = malloc(sizeof(t_swag *));
	*stack_copy = NULL;
	if (1 == copy_list(stack_a, stack_copy))
	{
		/* error handling and freeing shit */
	}
	sort_copy(stack_copy);
	assign_index(stack_a, stack_copy);
	// print_stack_a_and_b(stack_a, stack_copy);
	/* free copy stack */
	return (0);
}

void	assign_index(t_swag **stack_a, t_swag **stack_copy)
{
	t_swag	*copy_node;
	t_swag	*temp_node;
	t_swag	*last_node;
	int		index;

	index = 1;
	temp_node = *stack_copy;
	last_node = temp_node->previous;
	while (temp_node && temp_node != last_node)
	{
		temp_node->index = index;
		temp_node = temp_node->next;
		index++;
	}
	if (temp_node)
		temp_node->index = index;
	copy_node = *stack_copy;
	temp_node = *stack_a;
	last_node = temp_node->previous;
	while (temp_node && temp_node != last_node)
	{
		while (temp_node->number != copy_node->number)
			copy_node = copy_node->next;
		temp_node->number = copy_node->index;
		temp_node = temp_node->next;
		copy_node = *stack_copy;
	}
	while (temp_node->number != copy_node->number)
		copy_node = copy_node->next;
	temp_node->number = copy_node->index;
}

void	sort_copy(t_swag **stack_copy)
{
	t_swag	*node1;
	t_swag	*last;
	int		swap;

	swap = 0;
	node1 = *stack_copy;
	last = node1->previous;
	while (swap == 0)
	{
		swap = 1;
		while (node1 && node1->next && node1 != last)
		{
			if (node1->number > node1->next->number)
			{
				swap_nodes(node1, node1->next);
				swap = 0;
			}
			node1 = node1->next;
		}
		node1 = *stack_copy;
	}
}

void	swap_nodes(t_swag *node1, t_swag *node2)
{
	int	temp;

	temp = node1->number;
	node1->number = node2->number;
	node2->number = temp;
}

int	copy_list(t_swag **stack_a, t_swag **stack_copy)
{
	t_swag	*last_node;
	t_swag	*temp_node;
	t_swag	*copy_node;

	temp_node = *stack_a;
	last_node = temp_node->previous;
	while (temp_node && temp_node != last_node)
	{
		copy_node = list_new_node(temp_node->number);
		if (!copy_node)
			return (1);
		list_add_back(stack_copy, copy_node);
		temp_node = temp_node->next;
	}
	if (temp_node)
	{
		copy_node = list_new_node(temp_node->number);
		if (!copy_node)
			return (1);
		list_add_back(stack_copy, copy_node);
	}
	return (0);
}
