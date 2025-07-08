/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorvenp <jkorvenp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 12:01:55 by jkorvenp          #+#    #+#             */
/*   Updated: 2025/07/08 18:31:08 by jkorvenp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include<stdio.h>


bool	is_valid(stack *a, stack *node)
{
	if (node->data > INT_MAX || node->data < INT_MIN)
	{
		write (1, "Error\n", 6);
		return (false);
	}
	
	//if no_int 

	while (a)
	{
		if (node->data == a->data)
			{
			write (1, "Error\n", 6);
			return (false);
			}
		a = a->next;
		}
		return(true);
}
static void	free_nodes(stack *a)
{
	stack	*node;
	
	while(a)
	{
		node = a;
		free(node);
		a = a->next;
	}

}
static stack	*fill_stack_a(char **argv, stack  *a, size_t size)
{
	stack	*node;

	while(size > 0)
	{
		node = malloc(sizeof(stack));
		if(!node)
			return(NULL);
		node->data = ft_atoi(argv[size - 1]);
		if (is_valid(a, node)==false)
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
}


int	main(int argc, char **argv)
{
	stack	*a;
	stack	*b;

	a = NULL;
	b = NULL;
	//int	i;
	//char	**array = &argv[1];
	//i = 0;
	if (argc < 2 || (argc == 2 && argv[1] == NULL))
		return (0);
	/*else if (argc == 2)
	{
		array = ft_split (argv[1], ' ');
		while (array[i])
        	i++;
		a = fill_stack_a(&array[0], a, i);
		free (array);
	}*/
	else
		a = fill_stack_a(&argv[1], a, argc - 1);
	if (!a)
		return(0);
	sort(&a, &b);
	free_nodes(a);
	return (0);
	
}

	
