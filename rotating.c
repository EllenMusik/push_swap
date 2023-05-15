/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 22:03:40 by esteiner          #+#    #+#             */
/*   Updated: 2023/05/15 22:05:20 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_swag **stack_a)
{
	t_swag	*temp_node;

	temp_node = *stack_a;
	*stack_a = temp_node->next;
	write(1, "ra\n", 3);
}

void	rotate_b(t_swag **stack_b)
{
	t_swag	*temp_node;

	temp_node = *stack_b;
	*stack_b = temp_node->next;
	write(1, "rb\n", 3);
}

void	rotate_both(t_swag **stack_a, t_swag **stack_b)
{
	t_swag	*temp_node;

	temp_node = *stack_a;
	*stack_a = temp_node->next;
	temp_node = *stack_b;
	*stack_b = temp_node->next;
	write(1, "rr\n", 3);
}
