/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorvenp <jkorvenp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:40:30 by jkorvenp          #+#    #+#             */
/*   Updated: 2025/06/25 13:46:21 by jkorvenp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.
rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.
rrr : rra and rrb at the same time.
*/
# include"push_swap.h"

void	reverse_rotate(stack **a)
{
	stack	*last;
	stack	*first;
	stack	*tmp;

	if (!*a || !(*a)->next)
		return;
	first = *a;
	tmp = first;
	while(tmp->next && tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = first;
	*a=last;
}
void    rra(stack **a)
{
    reverse_rotate(a);
    write(1, "rra\n", 4);
}
void    rrb(stack **b)
{
    reverse_rotate(b);
    write(1, "rrb\n", 4);
}
void    rrr(stack **a, stack **b)
{
    reverse_rotate(a);
    reverse_rotate(b);
    write(1, "rrr\n", 4);
}