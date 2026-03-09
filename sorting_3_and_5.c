/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_3_and_5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 23:16:09 by esteiner          #+#    #+#             */
/*   Updated: 2026/03/08 16:11:24 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* sorts it if there are 5 numbers with the help of "sort_3" */
int	sort_5(t_swag **stack_a, t_swag **stack_b)
{
	while (list_node_count(stack_a) > 3)
	{
		if ((*stack_a)->index == 1 || (*stack_a)->index == 2)
			push_a_to_b(stack_a, stack_b);
		else
			rotate_a(stack_a);
	}
	if (is_it_already_sorted(stack_a) != 0)
		sorting_when_3_numbers(stack_a);
	if ((*stack_b)->index < (*stack_b)->next->index)
		swap_b(stack_b);
	push_b_to_a(stack_a, stack_b);
	push_b_to_a(stack_a, stack_b);
	return (0);
}

/* a hard coded algorithm to sort 3 numbers. */
int	sorting_when_3_numbers(t_swag **stack_a)
{
	t_swag	*tmp1;
	t_swag	*tmp2;
	t_swag	*tmp3;

	tmp1 = *stack_a;
	tmp2 = tmp1->next;
	tmp3 = tmp2->next;
	if (tmp1->index < tmp2->index && tmp1->index < tmp3->index)
	{
		reverse_rotate_a(stack_a);
		swap_a(stack_a);
	}
	else if (tmp1->index > tmp2->index && tmp2->index > tmp3->index)
	{
		rotate_a(stack_a);
		swap_a(stack_a);
	}
	else
		sorting_3_2(tmp1, tmp2, tmp3, stack_a);
	return (0);
}

int	sorting_3_2(t_swag *tmp1, t_swag *tmp2, t_swag *tmp3, t_swag **stack_a)
{
	if (tmp1->index > tmp2->index && tmp2->index < tmp3->index
		&& tmp1->index > tmp3->index)
		rotate_a(stack_a);
	else if (tmp1->index < tmp2->index && tmp2->index > tmp3->index
		&& tmp1->index > tmp3->index)
		reverse_rotate_a(stack_a);
	else if (tmp1->index > tmp2->index && tmp2->index < tmp3->index
		&& tmp1->index < tmp3->index)
		swap_a(stack_a);
	return (0);
}
