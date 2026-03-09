/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 17:28:29 by esteiner          #+#    #+#             */
/*   Updated: 2026/03/09 15:23:34 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int total = 0;
int amount = 0;


int cost_calculate_sort(t_swag **stack_a, t_swag **stack_b)
{
    push_all_but_3_b(stack_a, stack_b);
    if (is_it_already_sorted(stack_a) != 0)
        sorting_when_3_numbers(stack_a);
    while (*stack_b)
    {
        update_positions(stack_a, stack_b);
        find_target_positions(stack_a, stack_b);
        calculate_each_node_cost(stack_a, stack_b);
        execute_lowest_cost_move(stack_a, stack_b);
        push_b_to_a(stack_a, stack_b);
    }
    if (use_reverse_rotate(stack_a, get_position_of_lowest(stack_a)))
    {
        while ((*stack_a)->index != 1)
            reverse_rotate_a(stack_a);
    }
    else
    {
        while ((*stack_a)->index != 1)
            rotate_a(stack_a);
    }
    print_stack_a_and_b(stack_a, stack_b);
    printf("done\n");
    printf("total moves: %i\n ", total);
    printf("amount of moves: %i\n ", amount);
    return 0;
}

void push_all_but_3_b(t_swag **stack_a, t_swag **stack_b)
{
    int total_nodes = list_node_count(stack_a);
    int pushed_count = 0;

    while (total_nodes - pushed_count > 3)
    {
        push_a_to_b(stack_a, stack_b);
        pushed_count++;
    }
}

void calculate_each_node_cost(t_swag **stack_a, t_swag **stack_b)
{
    t_swag *current_b;
    int cost_a;
    int cost_b;

    current_b = *stack_b;
    cost_a = current_b->target_pos;
    cost_b = current_b->position;
    while (current_b)
    {
        cost_a = current_b->target_pos;
        cost_b = current_b->position;
        if (use_reverse_rotate(stack_a, current_b->target_pos))
            cost_a = list_node_count(stack_a) - cost_a;
        if (use_reverse_rotate(stack_b, current_b->position))
            cost_b = list_node_count(stack_b) - cost_b;
        if (use_reverse_rotate(stack_b, current_b->position) == use_reverse_rotate(stack_a, current_b->target_pos))
        {
            if (cost_a > cost_b)
                current_b->total_cost = cost_a;
            else
                current_b->total_cost = cost_b;
        }
        else
            current_b->total_cost = cost_a + cost_b;
        if (current_b == list_find_last(stack_b))
            break ;
        current_b = current_b->next;
    }

}

void execute_lowest_cost_move(t_swag **stack_a, t_swag **stack_b)
{
    t_swag *current_b;
    t_swag *lowest_cost_node;
    bool same_direction_rotate;
    bool same_direction_reverse;
    int i;

    current_b = *stack_b;
    lowest_cost_node = current_b;
    same_direction_reverse = false;
    same_direction_rotate = false;
    i = 0;

    while (current_b) //finding lowest cost node
    {
        if (current_b->total_cost < lowest_cost_node->total_cost)
            lowest_cost_node = current_b;
        if (current_b == list_find_last(stack_b))
            break ;
        current_b = current_b->next;
    }
    // print_stack_a_and_b(stack_a, stack_b);
    // printf("---------------------------------lowest cost: %i, node: %li\n", lowest_cost_node->total_cost, lowest_cost_node->index);

    //checking if we can do some combined rotations
    if (use_reverse_rotate(stack_b, lowest_cost_node->position) && use_reverse_rotate(stack_a, lowest_cost_node->target_pos))
        same_direction_reverse = true;
    
    if (!use_reverse_rotate(stack_b, lowest_cost_node->position) && !use_reverse_rotate(stack_a, lowest_cost_node->target_pos))
        same_direction_rotate = true;

    // performing the combined rotations
    if (same_direction_rotate)
    {
        while ((*stack_a)->position != lowest_cost_node->target_pos && (*stack_b)->position != lowest_cost_node->position)
        {
            rotate_both(stack_a, stack_b);
            i++;
        }
    }
    if (same_direction_reverse)
    {
        while ((*stack_a)->position != lowest_cost_node->target_pos && (*stack_b)->position != lowest_cost_node->position)
        {
            reverse_rotate_both(stack_a, stack_b);
            i++;
        }
    }

    // performing the remaining individual rotations
    while ((*stack_a)->position != lowest_cost_node->target_pos)
    {
        if (use_reverse_rotate(stack_a, lowest_cost_node->target_pos))
            reverse_rotate_a(stack_a);
        else
            rotate_a(stack_a);
        i++;
    }
    while ((*stack_b)->position != lowest_cost_node->position)  
    {
        if (use_reverse_rotate(stack_b, lowest_cost_node->position))
            reverse_rotate_b(stack_b);
        else
            rotate_b(stack_b);
        i++;
    }

    total += i;
    amount++;
}

void update_positions(t_swag **stack_a, t_swag **stack_b)
{
    int position;

    position = 0;
    t_swag *current = *stack_a;
    while (current)
    {
        current->position = position;
        position++;
        if (current == list_find_last(stack_a))
            break ;
        current = current->next;
    }
    current = *stack_b;
    position = 0;
    while (current)
    {
        current->position = position;
        position++;
        if (current == list_find_last(stack_b))
            break ;
        current = current->next;
    }
}

int find_target_for_value(t_swag **stack_a, long index_b)
{
    t_swag *current_a;

    if (!*stack_a)
        return 0;
    current_a = *stack_a;
    while (current_a)
    {
        if (current_a->index < index_b && current_a->next->index > index_b)
            return current_a->next->position;
        if (current_a->index > current_a->next->index)
        {
            if (index_b > current_a->index || index_b < current_a->next->index)
                return current_a->next->position;
        }
        if (current_a == list_find_last(stack_a))
            break ;
        current_a = current_a->next;
    }
    return 0;
}

/// @brief For each node in stack_b, find the position in stack_a where it should be inserted to maintain sorted order.
void find_target_positions(t_swag **stack_a, t_swag **stack_b)
{
	t_swag *current_b;
	int max_index_in_a;
	int smallest_pos_in_a;

	max_index_in_a = get_max_index(stack_a);
	smallest_pos_in_a = get_position_of_lowest(stack_a);
	current_b = *stack_b;
	while (current_b)
	{
		if (current_b->index > max_index_in_a)
			current_b->target_pos = smallest_pos_in_a;
		else
            current_b->target_pos = find_target_for_value(stack_a, current_b->index);
		if (current_b == list_find_last(stack_b))
            break ;
        current_b = current_b->next;
	}
}

int get_max_index(t_swag **stack_a)
{
    t_swag *current;
    int max_index;

    current = *stack_a;
    max_index = current->index;
    while (current)
    {
        if (current->index > max_index)
            max_index = current->index;
        if (current == list_find_last(stack_a))
            break ;
        current = current->next;
    }
    return max_index;
}

int get_position_of_lowest(t_swag **stack_a)
{
    t_swag *current;
    t_swag *lowest_position;

    current = *stack_a;
    lowest_position = current;
    while (current)
    {
        if (current->index < lowest_position->index)
            lowest_position = current;
        if (current == list_find_last(stack_a))
            break ;
        current = current->next;
    }
    return lowest_position->position;
}

int use_reverse_rotate(t_swag **stack, int position)
{
	if (position > list_node_count(stack) / 2)
		return 1;
	return 0;
}