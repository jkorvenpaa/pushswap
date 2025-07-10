/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorvenp <jkorvenp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 12:30:05 by jkorvenp          #+#    #+#             */
/*   Updated: 2025/07/10 18:14:46 by jkorvenp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_triple(stack **a)
{
	if (((*a)->data > (*a)->next->data))
		sa(*a);
	if ((*a)->next->data > (*a)->next->next->data)
		rra(a);
	if (((*a)->data > (*a)->next->data))
		sa(*a);
}

size_t	stack_len(stack *a)
{
	size_t	len;
	stack	*temp;

	if (!a)
		return (0);
	len = 0;
	temp = a;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	return (len);
}

stack	*max_node(stack *a)
{
	stack	*max;
	stack	*tmp;

	if (!a)
		return (NULL);
	max = a;
	tmp = a->next;
	while (tmp)
	{
		if (max->data < tmp->data)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

stack	*min_node(stack *a)
{
	stack	*min;
	stack	*tmp;

	if (!a)
		return (NULL);
	min = a;
	tmp = a->next;
	while (tmp)
	{
		if (min->data > tmp->data)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

bool	past_middle_node(stack *x, stack *target)
{
	size_t	i;
	stack	*head;

	head = x;
	i = 0;
	while (x)
	{
		if (x == target)
			break ;
		x = x->next;
		i++;
	}
	if (i > (stack_len(head) / 2))
		return (true);
	else
		return (false);
}
