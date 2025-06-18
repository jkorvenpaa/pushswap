/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorvenp <jkorvenp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:44:05 by jkorvenp          #+#    #+#             */
/*   Updated: 2025/06/13 13:20:04 by jkorvenp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Sort 100 random numbers in fewer than 700 operations.
// Sort 500 random numbers in no more than 5500 operations.
//read, write, malloc, free, exit


# include "push_swap.h"

#include<stdio.h>
void	fill_stack_a(char **argv, long *stack, size_t size)
{
	printf("size=%zu\n", size);
	size_t	i;

	i = 0;
	while(i < size -1)
	{
		stack[i] = ft_atoi(argv[i]);
		printf("%ld\n", stack[i]);
		i++;
	}
  
	
}


int	main(int argc, char **argv)
{

	
	//array way:
		//send array of arguments to atoi = struct stack a filled;
		//create oprations
		//create stack b: calloc.
		//push_swap using algorithm + print used operations 
		//free stacks

	datastruct a;
	//long	*b_stack;

	if (argc < 2)
		return (0);
	a.stack = malloc(argc - 1* sizeof(long));
	if(!a.stack)
		return(0);
	a.size = argc;
	fill_stack_a(&argv[1], a.stack, a.size);
	//b_stack = calloc(argc *sizeof(long));
	//if (!b_stack)
	//	return(NULL);
	//push_swap(a.stack, b_stack);
	free (a.stack);
	//free (b_stack);
	return (0);
}