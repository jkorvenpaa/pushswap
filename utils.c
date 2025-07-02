/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorvenp <jkorvenp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 12:30:05 by jkorvenp          #+#    #+#             */
/*   Updated: 2025/07/02 17:04:56 by jkorvenp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//stack len, last node, max node , min node.

# include "push_swap.h"
# include<stdio.h>

size_t	push_cost(stack *x, stack *target)
{
	size_t	cost;

	cost = 0;
	while (x->next)
	{
		if(x->data == target->data)
			return (cost);
		x = x->next;
		cost++;
	}
	return(cost);
}

size_t	stack_len(stack *a)
{
	size_t	len;
	stack	*temp;

	if (!a)
		return(0);
	len = 1;
	temp = a;
	while(temp->next)
	{
		temp = temp->next;
		len++;
	}
	//printf("stacklen:%zu\n", len);
	return (len);
}

stack	last_node(stack *a)
{
	stack	*last;
	last = a;
	while(last->next)
	{
		last = last->next;
	}
	 printf("lastnode_data:%ld\n", last->data);
	return (*last);
}

long	max_node(stack *a)
{
	stack	*max;
	stack	*tmp;
	
	max = a;
	tmp= a->next;
	while(tmp)
	{
		if (max->data < tmp->data)
			max = tmp;
		tmp = tmp->next;
	}
	 printf("max_node_data:%ld\n", max->data);
	return (max->data);
}
long	min_node(stack *a)
{
	stack	*min;
	stack	*tmp;

	min = a;
	tmp= a->next;
	while(tmp)
	{
		if (min->data > tmp->data)
			min = tmp;
		tmp = tmp->next;
	}
	 printf("min_node_data:%ld\n", min->data);
	return (min->data);
}