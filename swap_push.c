/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorvenp <jkorvenp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:49:10 by jkorvenp          #+#    #+#             */
/*   Updated: 2025/06/18 11:48:24 by jkorvenp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one element or none.
sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one element or none.
ss : sa and sb at the same time.
pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.
*/
# include"push_swap.h"

void	sa(stack *a)
{
	long	tmp;

	if (a && a->next != NULL)
	{
		tmp = a->data;
		a->data = a->next->data;
		a->next->data = tmp;
		write(1, "sa\n", 3);
	}
}

void	sb(stack *b)
{
	long	tmp;

	if (b && b->next != NULL)
	{
		tmp = b->data;
		b->data = b->next->data;
		b->next->data = tmp;
		write(1, "sb\n", 3);
	}
}
void	ss(stack *a, stack *b)
{
	long	tmp;

	if (a && a->next != NULL)
	{
		tmp = a->data;
		a->data = a->next->data;
		a->next->data = tmp;
	}
		if (b && b->next != NULL)
	{
		tmp = b->data;
		b->data = b->next->data;
		b->next->data = tmp;
	}
	write(1, "ss\n", 3);
}

void	pb(stack **a, stack **b)
{
	stack	*tmp;

	if (!*a)
		return;
	tmp = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	tmp->next = *b;
	if (*b)
		(*b)->prev = tmp;
	*b = tmp;
	write(1, "pb\n", 3);
}
void	pa(stack **a, stack **b)
{
	stack	*tmp;

	if (!*b)
		return;
	tmp = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->prev = NULL;
	tmp->next = *a;
	if (*a)
		(*a)->prev = tmp;
	*a = tmp;
	write(1, "pa\n", 3);
}
