/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorvenp <jkorvenp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:52:49 by jkorvenp          #+#    #+#             */
/*   Updated: 2025/07/10 17:58:10 by jkorvenp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stack	*find_target_pb(stack *a, stack *b)
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
	}
	if (!target)
		target = max_node(b_head);
	return (target);
}

stack	*find_target_pa(stack *b, stack *a)
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
	}
	if (!target)
		target = min_node(a_head);
	return (target);
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
	if (a != current)
	{
		if (past_middle_node(a, current))
			cost = cost + (stack_len(current));
		else
			cost = cost + (stack_len(a) - stack_len(current));
	}
	return (cost);
} 

stack	*cheapest_to_pb(stack *a, stack *b)
{
	stack	*current;
	stack	*target;
	stack	*cheap;
	size_t	min;
	size_t	cost;

	current = a;
	target = NULL;
	cheap = NULL;
	min = 0;	
	cost = 0;
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
	return (cheap);
}
stack	*cheapest_to_pa(stack *b, stack *a)
{
	stack	*current;
	stack	*target;
	stack	*cheap;
	size_t	min;
	size_t	cost;

	current = b;
	target = NULL;
	cheap = NULL;
	min = 0;	
	cost = 0;
	while (current)
	{
		target = find_target_pa(current, a);
		cost = push_cost(a, target, b, current);
		if (!cheap || cost < min)
		{
			cheap = current;
			min = cost;
		}
		current = current->next;
	}
	return (cheap);
}

