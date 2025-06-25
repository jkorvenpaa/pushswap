/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorvenp <jkorvenp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 12:01:55 by jkorvenp          #+#    #+#             */
/*   Updated: 2025/06/25 13:51:25 by jkorvenp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

#include<stdio.h>

stack	*fill_stack_a(char **argv, stack  *a, size_t size)
{	
	size_t	i;
	stack	*node;
	i = 0;
	while(size > 0 && argv[i] != NULL)
	{
		node = malloc(sizeof(stack));
		if(!node)
			return(NULL);
		node->data = ft_atoi(argv[i]);
		node->prev = NULL;
		node->next = a;
		if (a)
			a->prev = NULL;
		a = node;
		i++;
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
	stack_len(a);
	print_A(a);
	last_node(a);
	max_node(a);
	min_node(a);

/*
print_A(a);
	rra(&a);
	print_A(a);
	pb(&a, &b);
	pb(&a, &b);
	print_B(b);
	rrb(&b);
	print_B(b);
	rrr(&a, &b);
	print_A(a);
	print_B(b);

print_B(b);
	sa(a);
print_A(a);
print_B(b);
	pb(&a, &b);
	pb(&a, &b);
print_A(a);
print_B(b);
	sb(b);
print_A(a);
print_B(b);
	ss(a, b);
print_A(a);
print_B(b);
	pa(&a, &b);
print_A(a);
print_B(b);
*/
	free (a);
	free (b);
	return (0);
	
}
	
