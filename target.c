/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorvenp <jkorvenp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:52:49 by jkorvenp          #+#    #+#             */
/*   Updated: 2025/07/06 16:20:36 by jkorvenp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include<stdio.h>

stack    *find_target_pb(stack *a, stack *b)
{
	stack	*target;
	stack	*b_head;
	
	b_head = b;
	target = NULL;
	while (b)
	{
		if ((a->data > b->data) && (!target || target->data < b->data))
			target = b;
		b = b->next;
		//printf("targetdata %ld\n", target->data);
	}
	if (!target)
		target = max_node(b_head);
	return(target);
}

stack    *find_target_pa(stack *b, stack *a)
{
	stack	*target;
	stack	*a_head;
	
	a_head = a;
	target = NULL;
	while (a)
	{
		if ((b->data < a->data) && (!target || target->data > a->data))
			target = a;
		a = a->next;
//		printf("targetdata %ld\n", target->data);
	}
	if (!target)
		target = min_node(a_head);
	return(target);
}

size_t	push_cost(stack *b, stack *target, stack *a, stack *current)
{
	size_t	cost;

	cost = 0;
	if (b != target)
	{
		if (past_middle_node(b, target))
			cost = stack_len(target);
		else
			cost = stack_len(b) - stack_len(target);
	}
	//printf("push_cost = %zu\n", cost);
	if (a != current)
	{
		if (past_middle_node(a, current))
			cost = cost + (stack_len(current));
		else
			cost = cost + (stack_len(a) - stack_len(current));
	}

	//printf("push_cost = %zu\n\n", cost);
	return(cost);
} 

stack	*cheapest_to_pb(stack *a, stack *b)
{
	stack	*current = a;
	stack	*target = NULL;
	stack	*cheap = NULL;
	size_t	min = 0;
	size_t	cost = 0;

	while (current)
	{
		target = find_target_pb(current, b);
		cost = push_cost(b, target, a, current);
		if(!cheap || cost < min)
		{
			cheap = current;
			min = cost;
		}
		current = current->next;
	}
	return(cheap);
}
stack	*cheapest_to_pa(stack *b, stack *a)
{
	stack	*current = b;
	stack	*target = NULL;
	stack	*cheap = NULL;
	size_t	min = 0;
	size_t	cost = 0;

	while (current)
	{
		target = find_target_pa(current, a);
		cost = push_cost(a, target, b, current);
		if(!cheap || cost < min)
		{
			cheap = current;
			min = cost;
		}
		current = current->next;
	}
	return(cheap);
}

