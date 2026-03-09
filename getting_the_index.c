/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getting_the_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:42:57 by esteiner          #+#    #+#             */
/*   Updated: 2026/03/09 15:36:16 by esteiner         ###   ########.fr       */
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
		return (1);
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
	set_index(stack_a, stack_copy);
}

/* replaces the numbers in "stack_a" with it's index */
void	set_index(t_swag **stack_a, t_swag **stack_copy)
{
	t_swag	*copy_node;
	t_swag	*temp_node;
	t_swag	*last_node;

	copy_node = *stack_copy;
	temp_node = *stack_a;
	last_node = temp_node->previous;
	while (temp_node)
	{
		while (temp_node->number != copy_node->number)
			copy_node = copy_node->next;
		temp_node->index = copy_node->index;
		if (temp_node == last_node)
			break ;
		temp_node = temp_node->next;
		copy_node = *stack_copy;
	}
}

/* uses a simple bubble sort algorithm to sort the numbers in "stack-copy" */
void	sort_copy(t_swag **stack_copy)
{
	t_swag	*node1;
	int		swap;
	int		len;

	len = list_node_count(stack_copy);
	swap = 0;
	node1 = *stack_copy;
	while (swap == 0)
	{
		swap = 1;
		node1 = *stack_copy;
		int i = 0;
		while (i < len - 1)
		{
			if (node1->number > node1->next->number)
			{
				if (node1 == *stack_copy)
					*stack_copy = node1->next;
				swap_nodes(node1, node1->next);
				swap = 0;
			}
			else
				node1 = node1->next;
			i++;
		}
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

