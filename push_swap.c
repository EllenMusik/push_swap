/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esteiner <esteiner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:12:51 by esteiner          #+#    #+#             */
/*   Updated: 2023/06/14 15:40:53 by esteiner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "push_swap.h"

/* checks if the number is in the integer (int) range
and if any number is duplicated */
static int	check_for_valid_nbr(char **stack, int i)
{
	long	temp_nbr;
	int		k;

	while (stack[i])
	{
		k = 0;
		while (stack[i][k])
			k++;
		if (k > 11)
			return (1);
		k = i + 1;
		temp_nbr = ft_atol(stack[i]);
		if (temp_nbr > 2147483647 || temp_nbr < -2147483648)
			return (1);
		while (stack[k])
		{
			if (0 == ft_strncmp(stack[i], stack[k], 10))
				return (1);
			k++;
		}
		i++;
	}
	return (0);
}

/* checks if the given argument only contains numbers (/negative numbers) */
static int	check_for_argv_error(char **argv, int startlist)
{
	int	k;
	int	i;

	i = startlist;
	k = 0;
	if (argv[i][0] == '\0')
		return (1);
	while (argv[i])
	{
		while (argv[i][k])
		{
			if ((argv[i][k] >= '0' && argv[i][k] <= '9')
			|| (argv[i][k] == '-' && argv[i][k + 1] != '-'))
				k++;
			else
				return (1);
		}
		i++;
		k = 0;
	}
	if (1 == check_for_valid_nbr(argv, startlist))
		return (1);
	return (0);
}

/* checks if the passed list in given as 1 argument and needs to be splitted */
static int	check_for_stoopid_list(char *arg, t_swag **stack_a)
{
	int		i;
	char	**splitted_list;

	i = 0;
	splitted_list = ft_split(arg, ' ');
	if (splitted_list == 0)
		return (1);
	if (1 == check_for_argv_error(splitted_list, 0))
		return (write(2, "Error\n", 6), 1);
	if (1 == make_the_list(splitted_list, stack_a, 0))
		return (free(stack_a), 1);
	while (splitted_list[i])
	{
		free(splitted_list[i]);
		i++;
	}
	return (free(splitted_list), 0);
}

/* handles the input checking functions and retruns an Error if nessesarry */
static int	input_handling(t_swag **stack_a, int argc, char **argv)
{	
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		if (1 == check_for_stoopid_list(argv[1], stack_a))
			return (1);
	}
	if (argc > 2)
	{
		if (1 == check_for_argv_error(argv, 1))
			return (write(2, "Error\n", 6), 1);
		if (1 == make_the_list(argv, stack_a, 1))
			return (free(stack_a), 1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_swag	**stack_a;
	t_swag	**stack_b;

	stack_a = malloc(sizeof(t_swag *));
	*stack_a = NULL;
	stack_b = malloc(sizeof(t_swag *));
	*stack_b = NULL;
	if (1 == input_handling(stack_a, argc, argv))
		return (1);
	if (is_it_already_sorted(stack_a) == 0)
		return (free_list(stack_a), free (stack_a), free (stack_b), 0);
	sorting_commands(stack_a, stack_b);
	free_list(stack_a);
	free_list(stack_b);
	return (free (stack_a), free (stack_b), 0);
}

// void	print_stack_a_and_b(t_swag **stack_a, t_swag **stack_b)
// {
// 	t_swag	*test_node;
// 	t_swag	*last_node;

// 	last_node = list_find_last(*stack_a);
// 	test_node = *stack_a;
// 	while (test_node && test_node != last_node)
// 	{
// 		printf("a: %i\n", test_node->number);
// 		test_node = test_node->next;
// 	}
// 	if (test_node)
// 		printf("a: %i\n\n", test_node->number);
// 	last_node = list_find_last(*stack_b);
// 	test_node = *stack_b;
// 	while (test_node && test_node != last_node)
// 	{
// 		printf("b: %i\n", test_node->number);
// 		test_node = test_node->next;
// 	}
// 	if (test_node)
// 		printf("b: %i\n\n", test_node->number);
// }
