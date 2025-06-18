/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorvenp <jkorvenp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 12:01:55 by jkorvenp          #+#    #+#             */
/*   Updated: 2025/06/18 12:00:00 by jkorvenp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

#include<stdio.h>

stack	*fill_stack_a(char **argv, stack  *a, size_t size)
{	
	size_t	i;
	stack	*node;
	i = 0;
	while(size > 0)
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
/*
void print_stack(stack *head)
{
    stack *current = head;
    printf("Stack: ");
    while (current)
    {
        printf("%ld ", current->data);
        current = current->next;
    }
    printf("\n");
}
*/
int	main(int argc, char **argv)
{
	stack	*a;
	stack	*b;
	
	if (argc < 2)
		return (0);
	a = malloc(sizeof(stack));
	b = malloc (sizeof(stack));
	if (!a || !b)
		return (0);
	a = fill_stack_a(&argv[1], a, argc - 1);
	sort(*a, *b);
	free (a);
	free (b);
	return (0);
}