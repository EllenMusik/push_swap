/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 22:06:45 by esteiner          #+#    #+#             */
/*   Updated: 2026/03/08 16:19:05 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* swaps the first 2 nodes of stack_a */
void swap_a(t_swag **stack_a)
{
	swap_top(stack_a);
	write(1, "sa\n", 3);
}

/* swaps the first 2 nodes of stack_b */
void swap_b(t_swag **stack_b)
{
	swap_top(stack_b);
	write(1, "sb\n", 3);
}

/* swaps the first 2 nodes of stack_a and b */
void swap_both(t_swag **stack_a, t_swag **stack_b)
{
	swap_top(stack_b);
	swap_top(stack_a);
	write(1, "ss\n", 3);
}

/* swaps the first 2 nodes*/
int swap_top(t_swag **stack)
{
    t_swag *temp;
    
    if (!*stack || (*stack)->next == *stack || !(*stack)->previous)
        return (1);
    temp = (*stack)->next;
    swap_nodes(*stack, temp);
    *stack = temp;
    return (0);
}

/* swaps 2 given nodes */
void swap_nodes(t_swag *node1, t_swag *node2)
{
    t_swag *first_node;
    t_swag *second_node;
    t_swag *first_previous;
    t_swag *second_next;

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
