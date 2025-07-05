/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorvenp <jkorvenp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:52:49 by jkorvenp          #+#    #+#             */
/*   Updated: 2025/07/05 18:38:17 by jkorvenp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include<stdio.h>

stack    *find_target(stack *a, stack *b)
{
	stack	*target;

	target = NULL;
	while (b->next)
	{
		if ((a->data > b->data) && (!target || target->data < b->data))
			target = b;
		b = b->next;
		//printf("targetdata %ld\n", target->data);
	}
	if (!target)
		target = max_node(b);
	return(target);
}

size_t	push_cost(stack *b, stack *target, stack *a)
{
	size_t	cost;

	cost = 0;
	while (b && b->next)
	{
		if(b == target)
			return (cost);
		b = b->next;
		cost++;
	}
	while (a && a->prev)
	{
		a = a->prev;
		cost++;
	}
	return(cost);
} 

stack	*cheapest_to_push(stack *a, stack *b)
{
	stack	*target = find_target(a, b);
	stack	*next_target = find_target(a->next, b);

	while (push_cost(b, target, a->next) > push_cost(b, next_target, a->next))
	{
		a = a->next;
		target = find_target(a, b);
		next_target = find_target(a->next, b);
	}
	return(a);
}
void	move_to_push(stack **a, stack **b, stack *current_push, stack *target)
{
	if((*a)->prev == NULL && past_middle_node(*b, target) == 1)
	{
		while (current_push->prev && target->prev)
			rrr(a, b);
		while (current_push->prev)
			rra(a);
	}
	else if ((*a)->prev == NULL && past_middle_node(*b, target) == 0)
	{
		while (current_push->prev && target->prev)
			rr(a, b);
		while (current_push->prev)
			ra(a);
	}
	while (*b != target)
	{
		if (past_middle_node(*b, target) == 0)
			rb(b);
		else
			rrb(b);
	}
}
