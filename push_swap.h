/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 13:02:50 by esteiner          #+#    #+#             */
/*   Updated: 2023/06/07 23:36:27 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct s_swag
{
	int				number;
	long			index;
	struct s_swag	*next;
	struct s_swag	*previous;
}	t_swag;

int		make_the_list(char **argv, t_swag **stack_a, int i);
t_swag	*list_new_node(int content);
t_swag	*list_find_last(t_swag *lst);
void	list_add_back(t_swag **lst, t_swag *new_last);
void	free_list(t_swag **lst);
int		sorting_commands(t_swag **stack_a, t_swag **stack_b);
void	list_add_front(t_swag **lst, t_swag *new_first);
void	push_b_to_a(t_swag **stack_a, t_swag **stack_b);
void	push_a_to_b(t_swag **stack_a, t_swag **stack_b);
int		push_stack_1_to_2(t_swag **stack_1, t_swag **stack_2);
void	swap_b(t_swag **stack_b);
void	swap_a(t_swag **stack_a);
void	swap_both(t_swag **stack_a, t_swag **stack_b);
int		swap_top(t_swag **stack);
void	rotate_a(t_swag **stack_a);
void	rotate_b(t_swag **stack_b);
void	rotate_both(t_swag **stack_a, t_swag **stack_b);
void	reverse_rotate_a(t_swag **stack_a);
void	reverse_rotate_b(t_swag **stack_b);
void	reverse_rotate_both(t_swag **stack_a, t_swag **stack_b);
void	print_stack_a_and_b(t_swag **stack_a, t_swag **stack_b);
int		is_it_already_sorted(t_swag **stack_a);
int		sorting_when_3_numbers(t_swag **stack_a);
int		list_node_count(t_swag *stack);
int		sorting_3_2(t_swag *tmp1, t_swag *tmp2, t_swag *tmp3, t_swag **stack_a);
int		get_index(t_swag **stack_a);
void	sort_copy(t_swag **stack_copy);
void	swap_nodes(t_swag *node1, t_swag *node2);
int		copy_list(t_swag **stack_a, t_swag **stack_copy);
void	assign_index(t_swag **stack_a, t_swag **stack_copy);
int		sort_5(t_swag **stack_a, t_swag **stack_b);
int		radix_sort(t_swag **stack_a, t_swag **stack_b);
void	replace_with_index(t_swag **stack_a, t_swag **stack_copy);

#endif