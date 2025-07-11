/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorvenp <jkorvenp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 12:30:05 by jkorvenp          #+#    #+#             */
/*   Updated: 2025/07/11 15:57:27 by jkorvenp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	stack_len(t_stack *a)
{
	size_t	len;
	t_stack	*temp;

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

t_stack	*max_node(t_stack *a)
{
	t_stack	*max;
	t_stack	*tmp;

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

t_stack	*min_node(t_stack *a)
{
	t_stack	*min;
	t_stack	*tmp;

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

bool	past_middle_node(t_stack *x, t_stack *target)
{
	size_t	i;
	t_stack	*head;

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
