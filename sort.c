/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorvenp <jkorvenp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:58:10 by jkorvenp          #+#    #+#             */
/*   Updated: 2025/07/11 16:04:15 by jkorvenp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_stack **a)
{
	t_stack	*temp;

	temp = *a;
	while (temp->next)
	{
		if (temp->data > temp->next->data)
			return (false);
		else
			temp = temp->next;
	}
	return (true);
}

void	sort_triple(t_stack **a)
{
	if (((*a)->data > (*a)->next->data))
		sa(*a);
	if ((*a)->next->data > (*a)->next->next->data)
		rra(a);
	if (((*a)->data > (*a)->next->data))
		sa(*a);
}

void	turk(t_stack **a, t_stack **b, t_stack *target, t_stack *current_push)
{
	while (stack_len(*a) > 3)
	{
		current_push = cheapest_to_pb(*a, *b);
		target = find_target_pb(current_push, *b);
		move_pb(a, b, current_push, target);
		pb(a, b);
	}
	sort_triple(a);
	while (*b)
	{
		current_push = cheapest_to_pa(*b, *a);
		target = find_target_pa(current_push, *a);
		move_pa(a, b, current_push, target);
		pa(a, b);
	}
	while (*a != min_node(*a))
	{
		if (past_middle_node(*a, min_node(*a)))
			rra(a);
		else
			ra(a);
	}
}

void	mini_turk(t_stack **a, t_stack **b)
{
	t_stack	*target;
	t_stack	*current_push;

	target = NULL;
	current_push = NULL;
	pb(a, b);
	if (stack_len(*a) > 3)
		pb(a, b);
	turk(a, b, target, current_push);
}

void	sort(t_stack **a, t_stack **b)
{
	if (stack_len(*a) < 2)
		return ;
	else if (stack_len(*a) == 2)
	{
		if ((*a)->data > (*a)->next->data)
			sa(*a);
		return ;
	}
	else if (stack_len(*a) == 3)
	{
		sort_triple(a);
		return ;
	}
	else if (stack_len(*a) > 3)
	{
		if (is_sorted(a))
			return ;
		else
			mini_turk(a, b);
	}
}
