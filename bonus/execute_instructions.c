/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 18:47:58 by esteiner          #+#    #+#             */
/*   Updated: 2026/03/10 16:27:53 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	check_instruction(char *line, t_swag **stack_a, t_swag **stack_b)
{
	if (0 == ft_strncmp(line, "sa\n", 3))
		swap_a(stack_a);
	else if (0 == ft_strncmp(line, "sb\n", 3))
		swap_b(stack_b);
	else if (0 == ft_strncmp(line, "ss\n", 3))
		swap_both(stack_a, stack_b);
	else if (0 == ft_strncmp(line, "pa\n", 3))
		push_b_to_a(stack_a, stack_b);
	else if (0 == ft_strncmp(line, "pb\n", 3))
		push_a_to_b(stack_a, stack_b);
	else if (0 == ft_strncmp(line, "ra\n", 3))
		rotate_a(stack_a);
	else if (0 == ft_strncmp(line, "rb\n", 3))
		rotate_b(stack_b);
	else if (0 == ft_strncmp(line, "rr\n", 3))
		rotate_both(stack_a, stack_b);
	else if (0 == ft_strncmp(line, "rra\n", 4))
		reverse_rotate_a(stack_a);
	else if (0 == ft_strncmp(line, "rrb\n", 4))
		reverse_rotate_b(stack_b);
	else if (0 == ft_strncmp(line, "rrr\n", 4))
		reverse_rotate_both(stack_a, stack_b);
	else
		return (1);
	return (0);
}

int	execute_instructions(t_swag **stack_a, t_swag **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (1 == check_instruction(line, stack_a, stack_b))
		{
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line(0);
	}
	return (0);
}
