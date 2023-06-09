/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getting_the_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:42:57 by esteiner          #+#    #+#             */
/*   Updated: 2023/06/09 15:52:28 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* creates a copy of "stack_a and delets it again
after using it for getting the index"*/
int	get_index(t_swag **stack_a)
{
	t_swag	**stack_copy;

	stack_copy = malloc(sizeof(t_swag *));
	*stack_copy = NULL;
	if (1 == copy_list(stack_a, stack_copy))
	{
		write(2, "Error\n", 6);
		free_list(stack_copy);
		free (stack_copy);
	}
	sort_copy(stack_copy);
	assign_index(stack_a, stack_copy);
	free_list(stack_copy);
	free (stack_copy);
	return (0);
}

/* assigns the index to the sorted copy of "stack_a" */
void	assign_index(t_swag **stack_a, t_swag **stack_copy)
{
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
	replace_with_index(stack_a, stack_copy);
}

/* replaces the numbers in "stack_a" with it's index */
void	replace_with_index(t_swag **stack_a, t_swag **stack_copy)
{
	t_swag	*copy_node;
	t_swag	*temp_node;
	t_swag	*last_node;

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

/* uses a simple bubble sort algorithm to sort the numbers in "stack-copy" */
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

/* copys every node from "stack_a" to "stack_copy" */
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
