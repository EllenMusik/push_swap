/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_help.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 13:08:36 by esteiner          #+#    #+#             */
/*   Updated: 2023/05/09 20:14:44 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_swag	*list_new_node(int content)
{
	t_swag	*node;

	node = malloc(sizeof(t_swag));
	if (!node)
		return (0);
	node->number = content;
	node->next = NULL;
	node->previous = NULL;
	node->index = 0;
	return (node);
}

void	list_add_back(t_swag **lst, t_swag *new_last)
{
	t_swag	*old_last;
	t_swag	*first_node;

	old_last = list_find_last(*lst);
	first_node = *lst;
	if (*lst)
	{
		old_last->next = new_last;
		first_node->previous = new_last;
		new_last->next = *lst;
		new_last->previous = old_last;
	}
	if (!*lst)
		*lst = new_last;
}

t_swag	*list_find_last(t_swag *lst)
{
	t_swag	*adresse;

	if (lst == NULL)
		return (NULL);
	if (lst->previous != NULL)
		adresse = lst->previous;
	else
		adresse = lst;
	return (adresse);
}

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

void	free_list(t_swag **lst)
{
	t_swag	*start;
	t_swag	*adresse;
	t_swag	*temporary;

	if (lst && *lst != NULL)
	{
		start = *lst;
		adresse = start->next;
		while (adresse && adresse != start)
		{
			temporary = adresse->next;
			free(adresse);
			adresse = temporary;
		}
		free(start);
		*lst = NULL;
	}
}

// void	free_list(int i, t_swag **lst)
// {
// 	t_swag	*adresse;
// 	t_swag	*temporary;

// 	adresse = *lst;
// 	if (*lst != NULL)
// 	{
// 		while (i > 1)
// 		{
// 			temporary = adresse->next;
// 			free(adresse);
// 			adresse = temporary;
// 			i--;
// 		}
// 		//free(adresse);
// 		*lst = NULL;
// 	}
// }
