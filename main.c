/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorvenp <jkorvenp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 12:01:55 by jkorvenp          #+#    #+#             */
/*   Updated: 2025/07/06 16:28:17 by jkorvenp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include<stdio.h>

// DUP still needs to be handled
// error checks and parsing
// int min and max
// memcheck!!!

stack	*fill_stack_a(char **argv, stack  *a, size_t size)
{
	stack	*node;

	while(size > 0)
	{
		node = malloc(sizeof(stack));
		if(!node)
			return(NULL);
		node->data = ft_atoi(argv[size - 1]);
		node->prev = NULL;
		node->next = a;
		if (a)
			a->prev = NULL;
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
	int	i;
	char	**array = &argv[1];
	i = 0;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		if (argv[1] == NULL)
			return(0);
		array = ft_split (argv[1], ' ');
		while (array[i])
		{
        	printf("array[%d] = \"%s\"\n", i, array[i]);
        	i++;
    	}
		printf("%d\n", i);
		a = fill_stack_a(&array[0], a, i);
	}
	else
		a = fill_stack_a(&argv[1], a, argc - 1);
	print_A(a);
	print_B(b);
	//last_node(a);
	//max_node(a);
	//min_node(a);
	sort(&a, &b);
	print_A(a);
	print_B(b);
	free (a);
	free (b);
	return (0);
	
}

	
