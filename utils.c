/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorvenp <jkorvenp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 12:30:05 by jkorvenp          #+#    #+#             */
/*   Updated: 2025/07/05 17:22:32 by jkorvenp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//stack len, last node, max node , min node.

# include "push_swap.h"
# include<stdio.h>



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

stack	*last_node(stack *a)
{
	stack	*last;
	last = a;
	while(last->next)
	{
		last = last->next;
	}
	 printf("lastnode_data:%ld\n", last->data);
	return (last);
}

stack	*max_node(stack *a)
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
	//printf("max_node_data:%ld\n", max->data);
	return (max);
}
stack	*min_node(stack *a)
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
	return (min);
}
size_t	past_middle_node(stack *x, stack *target)
{
	size_t	i;

	i = 1;
	while(x->next)
	{
		if (x == target)
			break;
		x = x->next;
		i++;
	}
	if (i > stack_len(x)/2)
		return(1);
	else
		return(0);
}