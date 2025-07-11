/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorvenp <jkorvenp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:31:07 by jkorvenp          #+#    #+#             */
/*   Updated: 2025/07/11 15:30:47 by jkorvenp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.
rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.
rr : ra and rb at the same time.
*/

#include "push_swap.h"

void	rotate(t_stack **a)
{
	t_stack	*rot;
	t_stack	*tmp;

	if (!*a || !(*a)->next)
		return ;
	rot = *a;
	*a = (*a)->next;
	(*a)->prev = NULL;
	tmp = *a;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = rot;
	rot->prev = tmp;
	rot->next = NULL;
}

void	ra(t_stack **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
