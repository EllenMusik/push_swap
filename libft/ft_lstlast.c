/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:22:03 by esteiner          #+#    #+#             */
/*   Updated: 2023/05/04 16:56:53 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*adresse;

	printf(".\n");
	if (lst == NULL)
		return (NULL);
	adresse = lst;
	while (adresse->next != NULL)
	{
		printf("interate item: %i\n", *(int *)adresse->content);
		adresse = adresse->next;
	}
	printf("last Item: %i\n", (int)adresse->content);
	return (adresse);
}
