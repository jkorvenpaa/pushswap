/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorvenp <jkorvenp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:58:10 by jkorvenp          #+#    #+#             */
/*   Updated: 2025/07/10 18:16:12 by jkorvenp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int	is_sorted(stack **a)
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

void	move_to_pb(stack **a, stack **b, stack *current_push, stack *target)
{
	while (*a != current_push)
	{
		if (past_middle_node(*a, current_push))
		{
			if (*b != target)
				rrr(a, b);
			else
				rra(a);
		}
		else
		{
			if (*b != target)
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
void	move_to_pa(stack **a, stack **b, stack *current_push, stack *target)
{
	while (*b != current_push)
	{
		if (past_middle_node(*b, current_push))
		{
			if (*a != target)
				rrr(a, b);
			else
				rrb(b);
		}
		else
		{
			if (*a != target)
				rr(a, b);
			else
				rb(b);
		}
	}
	while (*a != target)
	{
		if (past_middle_node(*a, target))
			rra(a);
		else
			ra(a);
	}
}

void	turk(stack **a, stack **b, stack *target, stack *current_push)
{
	while (stack_len(*a) > 3)
	{
		current_push = cheapest_to_pb(*a, *b);
		target = find_target_pb(current_push, *b);
		move_to_pb(a, b, current_push, target);
		pb(a, b);
	}
	sort_triple(a);
	while (*b)
	{
		current_push = cheapest_to_pa(*b, *a);
		target = find_target_pa(current_push, *a);
		move_to_pa(a, b, current_push, target);
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
void	mini_turk(stack **a, stack **b)
{
	stack	*target;
	stack	*current_push;

	target = NULL;
	current_push = NULL;
	pb(a, b);
	if (stack_len(*a) > 3)
		pb(a, b);
	turk(a, b, target, current_push);
}

void	sort(stack **a, stack **b)
{
	if (stack_len(*a) < 2)
		return;
	else if (stack_len(*a)== 2)
	{
		if ((*a)->data > (*a)->next->data)
			sa(*a);
		return;
	}
	else if (stack_len(*a) == 3)
	{
		sort_triple(a);
		return;
	}
	else if (stack_len(*a) > 3)
	{
		if (is_sorted(a) == 1)
			return;
		else
			mini_turk(a, b);
	}
}
