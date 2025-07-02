/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorvenp <jkorvenp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:58:10 by jkorvenp          #+#    #+#             */
/*   Updated: 2025/07/02 17:12:41 by jkorvenp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




# include "push_swap.h"

#include <stdio.h>

void	turk(stack **a, stack **b)
{
	printf("WE ARE IN TURK\n");
	size_t	i;
	//size_t	cost;
	long	target;
	stack	*btemp;
	long	min;
	
	btemp = (*b);
	i = 0;
	pb(a, b);
	pb(a, b);
	min = min_node(*b);
	//target_node = next smallest:
	while (stack_len(*a) > 3)
	{
		if ((*a)->data < min)
			target = max_node(*b);
		else
			{
				while ((*a)->data > btemp->data && (btemp->data > btemp->next->data))
				{
					target = btemp->data;
					btemp = btemp->next;
				}
			}
		while((*b)->data != target && stack_len(*b) > i)
		{//if push_cost()
			rrb(b);
			i++;
		}
		pb (a, b);
	}
	//if (last_node(*b)->data > (*a)->data)


		/*
	while (stack_len(*a) > 3)
	{
		while (((*a)->data < (*b)->data) && (stack_len(*b) > i))
		{
			rrb(b);
			i++;
		}
		if ((*b)->data < (*b)->next->data)
			rb(b);
		pb(a, b);
	}
	sort_triple(a);
	rra(a);
	while(stack_len(*b) > 0)
	{
		pa(a, b);
	}
*/
}

int is_sorted(stack **a)
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

void    sort_triple(stack **a)
{
	if (((*a)->data > (*a)->next->data))
		sa(*a);
	if ((*a) ->next ->data > (*a)->next->next->data)
		rra(a);
	if (((*a)->data > (*a)->next->data))
		sa(*a);
}


void    sort(stack **a, stack **b)
{
	if (stack_len(*a) < 2)
		return;
	else if(stack_len(*a)== 2)
	{
		if ((*a)->data > (*a)->next->data)
			sa(*a);
		return;
	}
	else if(stack_len(*a) == 3)
	{
		sort_triple(a);
		return;
	}
	else
	{
		if(is_sorted(a) == 1)
		{
			printf("sorted=%d\n", is_sorted(a));
			return;
		}
		else
		{
		printf("sorted=%d\n", is_sorted(a));
		turk(a, b);
		}
	}

}
