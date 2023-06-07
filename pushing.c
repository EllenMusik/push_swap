/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:54:59 by esteiner          #+#    #+#             */
/*   Updated: 2023/06/08 00:04:25 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* pushes the first element from stack a to be the first elemnt from stack b */
void	push_a_to_b(t_swag **stack_a, t_swag **stack_b)
{
	push_stack_1_to_2(stack_a, stack_b);
	write(1, "pb\n", 3);
}

/* pushes the first element from stack b to be the first elemnt from stack a */
void	push_b_to_a(t_swag **stack_a, t_swag **stack_b)
{
	push_stack_1_to_2(stack_b, stack_a);
	write(1, "pa\n", 3);
}

/* pushes the first element from stack 1 to be the first elemnt from stack 2 */
int	push_stack_1_to_2(t_swag **stack_1, t_swag **stack_2)
{
	t_swag	*temp_node;
	t_swag	*temp_new_first;
	t_swag	*temp_last;

	if (!*stack_1)
		return (0);
	temp_node = *stack_1;
	if (temp_node == temp_node->next)
	{
		temp_new_first = NULL;
		temp_last = NULL;
	}
	else
	{
		temp_new_first = temp_node->next;
		temp_last = temp_node->previous;
	}
	list_add_front(stack_2, temp_node);
	*stack_1 = temp_new_first;
	if (temp_new_first)
	{
		temp_last->next = temp_new_first;
		temp_new_first->previous = temp_last;
	}
	return (0);
}

/* adds the Element to the front of the list,
making it the new first item in the list */
void	list_add_front(t_swag **lst, t_swag *new_first)
{
	t_swag	*old_first;
	t_swag	*last_node;

	old_first = *lst;
	last_node = list_find_last(*lst);
	if (*lst)
	{
		old_first->previous = new_first;
		last_node->next = new_first;
		new_first->next = old_first;
		new_first->previous = last_node;
	}
	else
	{
		new_first->next = new_first;
		new_first->previous = new_first;
	}
	*lst = new_first;
}
