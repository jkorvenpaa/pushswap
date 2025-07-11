/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorvenp <jkorvenp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 12:01:55 by jkorvenp          #+#    #+#             */
/*   Updated: 2025/07/11 16:08:47 by jkorvenp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	input_is_digit(char **argv, int argc)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < argc)
	{
		if ((argv[i][j + 1]) && (argv[i][j] == '-' || argv[i][j] == '+'))
			j++;
		while (argv[i][j])
		{
			if (argv[i][j] < 48 || argv[i][j] > 57)
				return (false);
			j++;
		}
		i++;
		j = 0;
	}
	return (true);
}

static bool	is_valid_int(t_stack *a, t_stack *node)
{
	if (node->data > INT_MAX || node->data < INT_MIN)
	{
		write (1, "Error\n", 6);
		free(node);
		return (false);
	}
	while (a)
	{
		if (node->data == a->data)
		{
			write (1, "Error\n", 6);
			free(node);
			return (false);
		}
		a = a->next;
	}
	return (true);
}

static void	free_nodes(t_stack *a)
{
	t_stack	*node;

	while (a)
	{
		node = a;
		a = a->next;
		free(node);
	}
}

static t_stack	*fill_stack_a(char **argv, t_stack *a, size_t size)
{
	t_stack	*node;

	while (size > 0)
	{
		node = malloc(sizeof(t_stack));
		if (!node)
			return (NULL);
		node->data = ft_atol(argv[size - 1]);
		if (is_valid_int(a, node) == false)
		{
			free_nodes(a);
			return (NULL);
		}
		node->prev = NULL;
		if (a)
		{
			node->next = a;
			a->prev = node;
		}
		else
			node->next = NULL;
		a = node;
		size--;
	}
	return (a);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2 || (argc == 2 && argv[1] == NULL))
		return (0);
	if (input_is_digit(&argv[1], argc - 1) == false)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	a = fill_stack_a(&argv[1], a, argc - 1);
	if (!a || is_sorted(&a))
		return (0);
	sort(&a, &b);
	free_nodes (a);
	return (0);
}
