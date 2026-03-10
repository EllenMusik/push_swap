/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotating.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 22:05:04 by esteiner          #+#    #+#             */
/*   Updated: 2026/03/10 16:34:56 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

/* reverse rotates stack a so that the last node is now the first one */
void	reverse_rotate_a(t_swag **stack_a)
{
	t_swag	*temp_node;

	temp_node = *stack_a;
	*stack_a = temp_node->previous;
}

/* reverse rotates stack b so that the last node is now the first one */
void	reverse_rotate_b(t_swag **stack_b)
{
	t_swag	*temp_node;

	temp_node = *stack_b;
	*stack_b = temp_node->previous;
}

/* reverse rotates both stacks so that the last node is now the first one */
void	reverse_rotate_both(t_swag **stack_a, t_swag **stack_b)
{
	if (stack_a && *stack_a && (*stack_a)->previous != *stack_a)
		*stack_a = (*stack_a)->previous;
	if (stack_b && *stack_b && (*stack_b)->previous != *stack_b)
		*stack_b = (*stack_b)->previous;
}
