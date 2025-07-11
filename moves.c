/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorvenp <jkorvenp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:54:20 by jkorvenp          #+#    #+#             */
/*   Updated: 2025/07/11 15:58:42 by jkorvenp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_pb(t_stack **a, t_stack **b, t_stack *current, t_stack *target)
{
	while (*a != current)
	{
		if (past_middle_node(*a, current))
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

void	move_pa(t_stack **a, t_stack **b, t_stack *current, t_stack *target)
{
	while (*b != current)
	{
		if (past_middle_node(*b, current))
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
