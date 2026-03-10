/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 18:31:34 by esteiner          #+#    #+#             */
/*   Updated: 2026/03/09 20:30:50 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../get_next_line/get_next_line.h"
# include "../push_swap.h"

int		execute_instructions(t_swag **stack_a, t_swag **stack_b);
int		check_instruction(char *line, t_swag **stack_a, t_swag **stack_b);
void	swap_a(t_swag **stack_a);
void	swap_b(t_swag **stack_b);
void	swap_both(t_swag **stack_a, t_swag **stack_b);
void	rotate_a(t_swag **stack_a);
void	rotate_b(t_swag **stack_b);
void	rotate_both(t_swag **stack_a, t_swag **stack_b);
void	reverse_rotate_a(t_swag **stack_a);
void	reverse_rotate_b(t_swag **stack_b);
void	reverse_rotate_both(t_swag **stack_a, t_swag **stack_b);
void	push_a_to_b(t_swag **stack_a, t_swag **stack_b);
void	push_b_to_a(t_swag **stack_a, t_swag **stack_b);
int		push_stack_1_to_2(t_swag **stack_1, t_swag **stack_2);

#endif