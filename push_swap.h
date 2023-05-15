/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 13:02:50 by esteiner          #+#    #+#             */
/*   Updated: 2023/05/15 22:21:20 by esteiner         ###   ########.fr       */
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
int		sorting_commands(t_swag **stack_a);
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

#endif