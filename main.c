/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorvenp <jkorvenp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 12:01:55 by jkorvenp          #+#    #+#             */
/*   Updated: 2025/07/10 17:42:52 by jkorvenp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include<stdio.h>

static bool	input_is_digit(char **argv, int argc)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < argc)
	{
		if ((argv[i][j+1]) && (argv[i][j] == '-' || argv[i][j] == '+'))
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

static bool	is_valid_int(stack *a, stack *node)
{
	if (node->data > INT_MAX || node->data < INT_MIN)
	{
		write (1, "Error\n", 6);
		return (false);
	} 

	while (a)
	{
		if (node->data == a->data)
			{
			write (1, "Error\n", 6);
			return (false);
			}
		a = a->next;
		}
		return (true);
}
static void	free_nodes(stack *a)
{
	stack	*node;

	while (a)
	{
		node = a;
		a = a->next;
		free(node);
	}

}
static stack	*fill_stack_a(char **argv, stack  *a, size_t size)
{
	stack	*node;

	while (size > 0)
	{
		node = malloc(sizeof(stack));
		if (!node)
			return (NULL);
		node->data = ft_atol(argv[size - 1]);
		if (is_valid_int(a, node)==false)
		{
			free(node);
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
/*
void print_A(stack *head)
{
    stack *current = head;
    printf("StackA: ");
    while (current)
    {
        printf("%ld ", current->data);
        current = current->next;
    }
    printf("\n");
}
void print_B(stack *head)
{
    stack *current = head;
    printf("StackB: ");
    while (current)
    {
        printf("%ld ", current->data);
        current = current->next;
    }
    printf("\n");
}*/
int	main(int argc, char **argv)
{
	stack	*a;
	stack	*b;

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
	if (!a)
		return (0);
	sort(&a, &b);
	//print_A(a);
	//print_B(b);
	free_nodes (a);
	return (0);
}

	
