/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorvenp <jkorvenp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:58:10 by jkorvenp          #+#    #+#             */
/*   Updated: 2025/07/03 21:00:49 by jkorvenp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

#include <stdio.h>

void	turk(stack **a, stack **b)
{
	printf("WE ARE IN TURK\n");
	stack	*current_push;
	// add checks if len < 3 after push
	pb(a, b);
	pb(a, b);
	while (stack_len(*a) > 3)
	{
		current_push = cheapest_to_push(a, b);
		move_to_top(a, b, current_push);
		pb(a, b);
	}
	sort_triple(*a);
	while(b)
	{
		current_push = cheapest_to_push(b, a);
		move_to_top(a, b, current_push);
		pa(a, b);
	}
	while(a != min_node(*a))
		rra, ra;	
}

int is_sorted(stack **a)
{
	stack   *temp;

	temp = *a;
	while (temp->next)
	{
		if (temp->data > temp->next->data)
			return (0);
		else
		temp = temp->next;
	}
	return (1);
}

void    sort_triple(stack **a)
{
	if (((*a)->data > (*a)->next->data))
		sa(*a);
	if ((*a) ->next ->data > (*a)->next->next->data)
		rra(a);
	if (((*a)->data > (*a)->next->data))
		sa(*a);
}


void    sort(stack **a, stack **b)
{
	if (stack_len(*a) < 2)
		return;
	else if(stack_len(*a)== 2)
	{
		if ((*a)->data > (*a)->next->data)
			sa(*a);
		return;
	}
	else if(stack_len(*a) == 3)
	{
		sort_triple(a);
		return;
	}
	else
	{
		if(is_sorted(a) == 1)
			return;
		else
			turk(a, b);
	}

}
