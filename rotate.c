/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorvenp <jkorvenp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:31:07 by jkorvenp          #+#    #+#             */
/*   Updated: 2025/06/18 11:55:13 by jkorvenp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.
rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.
rr : ra and rb at the same time.
*/
# include"push_swap.h"

void	rotate(stack **a)
{
	stack	*first;
	stack	*tmp;

	if (!*a || !(*a)->next)
		return;
	first = *a;
	*a = first->next;
	first->next = NULL;
	tmp = *a;
	while(tmp->next)
		tmp =  tmp->next;
	tmp->next = first;
}

void    ra(stack **a)
{
    rotate(*a);
    write(1, "ra\n", 3);
}
void    rb(stack **b)
{
    rotate(*b);
    write(1, "rb\n", 3);
}
void    rr(stack **a, stack **b)
{
    rotate(*a);
    rotate(*b);
    write(1, "rr\n", 3);
}

