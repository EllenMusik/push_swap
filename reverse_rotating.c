/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotating.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 22:05:04 by esteiner          #+#    #+#             */
/*   Updated: 2023/06/05 20:01:15 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* reverse rotates stack a so that the last node is now the first one */
void	reverse_rotate_a(t_swag **stack_a)
{
	t_swag	*temp_node;

	temp_node = *stack_a;
	*stack_a = temp_node->previous;
	write(1, "rra\n", 4);
}

/* reverse rotates stack b so that the last node is now the first one */
void	reverse_rotate_b(t_swag **stack_b)
{
	t_swag	*temp_node;

	temp_node = *stack_b;
	*stack_b = temp_node->previous;
	write(1, "rrb\n", 4);
}

/* reverse rotates both stacks so that the last node is now the first one */
void	reverse_rotate_both(t_swag **stack_a, t_swag **stack_b)
{
	t_swag	*temp_node;

	temp_node = *stack_a;
	*stack_a = temp_node->previous;
	temp_node = *stack_b;
	*stack_b = temp_node->previous;
	write(1, "rrr\n", 4);
}
