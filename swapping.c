/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 22:06:45 by esteiner          #+#    #+#             */
/*   Updated: 2023/06/07 23:25:46 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_swag **stack_a)
{
	swap_top(stack_a);
	write(1, "sa\n", 3);
}

void	swap_b(t_swag **stack_b)
{
	swap_top(stack_b);
	write(1, "sb\n", 3);
}

void	swap_both(t_swag **stack_a, t_swag **stack_b)
{
	swap_top(stack_b);
	swap_top(stack_a);
	write(1, "ss\n", 3);
}

int	swap_top(t_swag **stack)
{
	int		first;
	int		second;
	t_swag	*temp_node_first;
	t_swag	*temp_node_second;

	temp_node_first = *stack;
	temp_node_second = temp_node_first->next;
	first = temp_node_first->number;
	second = temp_node_second->number;
	temp_node_first->number = second;
	temp_node_second->number = first;
	return (0);
}

void	swap_nodes(t_swag *node1, t_swag *node2)
{
	int	temp;

	temp = node1->number;
	node1->number = node2->number;
	node2->number = temp;
}
