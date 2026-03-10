/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 22:03:40 by esteiner          #+#    #+#             */
/*   Updated: 2026/03/09 20:26:23 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

/* rotates stack a so that the first node is now the last one */
void	rotate_a(t_swag **stack_a)
{
	t_swag	*temp_node;

	temp_node = *stack_a;
	*stack_a = temp_node->next;
}

/* rotates stack b so that the first node is now the last one */
void	rotate_b(t_swag **stack_b)
{
	t_swag	*temp_node;

	temp_node = *stack_b;
	*stack_b = temp_node->next;
}

/// @brief rotates both stacks so that the first node is now the last one
/// @param stack_a pointer to the first node of stack a
/// @param stack_b pointer to the first node of stack b
/// @return nothing, but writes "rr\n" to the standard output
void	rotate_both(t_swag **stack_a, t_swag **stack_b)
{
	if (stack_a && *stack_a && (*stack_a)->next != *stack_a)
		*stack_a = (*stack_a)->next;
	if (stack_b && *stack_b && (*stack_b)->next != *stack_b)
		*stack_b = (*stack_b)->next;
}
