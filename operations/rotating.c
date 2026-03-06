/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 22:03:40 by esteiner          #+#    #+#             */
/*   Updated: 2026/03/05 17:26:53 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* rotates stack a so that the first node is now the last one */
void	rotate_a(t_swag **stack_a)
{
	t_swag	*temp_node;

	temp_node = *stack_a;
	*stack_a = temp_node->next;
	write(1, "ra\n", 3);
}

/* rotates stack b so that the first node is now the last one */
void	rotate_b(t_swag **stack_b)
{
	t_swag	*temp_node;

	temp_node = *stack_b;
	*stack_b = temp_node->next;
	write(1, "rb\n", 3);
}

/// @brief rotates both stacks so that the first node is now the last one 
/// @param stack_a pointer to the first node of stack a
/// @param stack_b pointer to the first node of stack b
/// @return nothing, but writes "rr\n" to the standard output
void	rotate_both(t_swag **stack_a, t_swag **stack_b)
{
	t_swag	*temp_node;

	temp_node = *stack_a;
	*stack_a = temp_node->next;
	temp_node = *stack_b;
	*stack_b = temp_node->next;
	write(1, "rr\n", 3);
}
