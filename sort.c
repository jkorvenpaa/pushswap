/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorvenp <jkorvenp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:58:10 by jkorvenp          #+#    #+#             */
/*   Updated: 2025/07/07 15:13:04 by jkorvenp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

#include <stdio.h>

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

void	move_to_push(stack **a, stack **b, stack *current_push, stack *target)
{
	while(*a != current_push)
	{
		if (past_middle_node(*a, current_push))
		{
			if(*b != target)
				rrr(a, b);
			else
				rra(a);
		}
		else
		{
			if(*b != target)
				rr(a, b);
			else
				ra(a);
		}
	}
	while (*b != target)
	{
		if (past_middle_node(*b, target))
			rrb(b);
		else
			rb(b);
	}
}

void	turk(stack **a, stack **b)
{
	//printf("WE ARE IN TURK\n");
	stack	*target;
	stack	*current_push;

	target = NULL;
	current_push = NULL;
	while (stack_len(*a) > 3)
	{
		current_push = cheapest_to_pb(*a, *b);
		target = find_target_pb(current_push, *b);
	//	printf("target= %ld  current_push= %ld\n", target->data, current_push->data);
		//print_A(*a);
		//print_B(*b);
		//printf("a = %ld b = %ld\n", (*a)->data, (*b)->data);
		move_to_push(a, b, current_push, target);
	//	print_A(*a);
	//	print_B(*b);
		//printf("a = %ld b = %ld\n\n", (*a)->data, (*b)->data);
		pb(a, b);
	}
	sort_triple(a);
	while (*b)
	{
		current_push = cheapest_to_pa(*b, *a);
		target = find_target_pa(current_push, *a);
		move_to_push(b, a, current_push, target);
		pa(a, b);
	}
	//print_A(*a);
	//print_B(*b);
	while(*a != min_node(*a))
	{
		if(past_middle_node(*a, min_node(*a)))
			rra(a);
		else
			ra(a);
	}
	//print_A(*a);
	//print_B(*b);
	//if (is_sorted(a))
	//	write(1,"Asorted\n",8);
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
	else if (stack_len(*a) > 3)
	{
		if(is_sorted(a) == 1)
			return;
		else
		{
			pb(a, b);
			if	(stack_len(*a) > 3)
				pb(a, b);
			turk(a, b);
		}
	}
}
