/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 22:06:45 by esteiner          #+#    #+#             */
/*   Updated: 2026/03/09 20:26:16 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

/* swaps the first 2 nodes of stack_a */
void	swap_a(t_swag **stack_a)
{
	swap_top(stack_a);
}

/* swaps the first 2 nodes of stack_b */
void	swap_b(t_swag **stack_b)
{
	swap_top(stack_b);
}

/* swaps the first 2 nodes of stack_a and b */
void	swap_both(t_swag **stack_a, t_swag **stack_b)
{
	swap_top(stack_b);
	swap_top(stack_a);
}

/* swaps the first 2 nodes*/
int	swap_top(t_swag **stack)
{
	t_swag	*a;
	t_swag	*b;
	int		tmp;

	if (!stack || !*stack || (*stack)->next == *stack)
		return (1);
	a = *stack;
	b = a->next;
	tmp = a->number;
	a->number = b->number;
	b->number = tmp;
	return (0);
}

/* swaps 2 given nodes */
void	swap_nodes(t_swag *node1, t_swag *node2)
{
	t_swag	*first_node;
	t_swag	*second_node;
	t_swag	*first_previous;
	t_swag	*second_next;

	first_node = node1;
	second_node = node2;
	if (!first_node || !second_node || first_node == second_node
		|| !first_node->previous || !second_node->next)
		return ;
	first_previous = first_node->previous;
	second_next = second_node->next;
	first_previous->next = second_node;
	second_node->next = first_node;
	first_node->previous = second_node;
	second_node->previous = first_previous;
	first_node->next = second_next;
	second_next->previous = first_node;
}
