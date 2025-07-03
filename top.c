/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorvenp <jkorvenp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:52:49 by jkorvenp          #+#    #+#             */
/*   Updated: 2025/07/03 20:57:44 by jkorvenp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stack    find_target(stack *a, stack *b)
{
	stack	*target;

	while (b->next && a->data > b->data)
	{
		target = b;
		b = b->next;
		if (!b)
			target = max_node(b);
	}
	return(*target);
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

stack	cheapest_to_push(stack *a, stack *b,)
{
	stack	*target;

	*target = find_target(a, b);
	while (push_cost(a, target) > push_cost(a->next, target))
		a = (a)->next;
	return(*a);
}
void	move_to_top(stack **a, stack **b, stack *current_push, stack *target)
{
	if((*a)->prev == NULL && past_middle_node(b, target) == 1)
	{
		while (current_push->prev && a_to_top > i && smallest_cost > i)
			rrr(a, b);
		while (current_push->prev)
			rra(a);
	}
	else if ((*a)->prev == NULL && past_middle_node(b, target) == 0)
	{
		while (current_push->prev && a_to_top > i && smallest_cost > i)
			rr(a, b);
		while (current_push->prev)
			ra(a);
	}
	// check all these and add ss conditions;
	target_to_top(b, target);
}

void	target_to_top(stack	**b, stack *target)
{
	while (b != target)
	{
		if (past_middle_node(b, target) == 0)
			rb(b);
		else
			rrb(b);
	}
}
