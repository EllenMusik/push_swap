/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_help.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 13:08:36 by esteiner          #+#    #+#             */
/*   Updated: 2026/03/10 02:52:58 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* creates a new node with the given integer as its content */
t_swag	*list_new_node(int content)
{
	t_swag	*node;

	node = malloc(sizeof(t_swag));
	if (!node)
		return (0);
	node->number = content;
	node->next = NULL;
	node->previous = NULL;
	node->position = 0;
	node->total_cost = 0;
	node->cost_a = 0;
	node->cost_b = 0;
	node->target_pos = 0;
	node->index = 0;
	return (node);
}

/* adds the given node to the back of the given list */
void	list_add_back(t_swag **lst, t_swag *new_last)
{
	t_swag	*old_last;
	t_swag	*first_node;

	old_last = list_find_last(lst);
	first_node = *lst;
	if (*lst)
	{
		old_last->next = new_last;
		first_node->previous = new_last;
		new_last->next = *lst;
		new_last->previous = old_last;
	}
	if (!*lst)
	{
		*lst = new_last;
		new_last->next = new_last;
		new_last->previous = new_last;
	}
}

/* finds the last node of the given circular list */
t_swag	*list_find_last(t_swag **lst)
{
	t_swag	*current;

	if (lst == NULL || *lst == NULL)
		return (NULL);
	current = *lst;
	while (current->next && current->next != *lst)
		current = current->next;
	return (current);
}

/* create the list "stack_a", made out of the given arguments/numbers */
int	make_the_list(char **argv, t_swag **stack_a, int i)
{
	int		temp;
	t_swag	*node;

	while (argv[i])
	{
		temp = ft_atoi(argv[i]);
		node = list_new_node(temp);
		if (node == 0)
		{
			free_list(stack_a);
			return (1);
		}
		list_add_back(stack_a, node);
		i++;
	}
	return (0);
}

/* frees a circular list and all its contents */
void	free_list(t_swag **lst)
{
	t_swag	*last;
	t_swag	*adresse;
	t_swag	*temporary;

	if (lst && *lst != NULL)
	{
		last = list_find_last(lst);
		adresse = *lst;
		while (adresse != last)
		{
			temporary = adresse->next;
			free(adresse);
			adresse = temporary;
		}
		free(last);
		*lst = NULL;
	}
}
