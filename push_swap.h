/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 13:02:50 by esteiner          #+#    #+#             */
/*   Updated: 2023/05/09 20:12:30 by esteiner         ###   ########.fr       */
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

#endif