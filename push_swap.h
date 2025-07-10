/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorvenp <jkorvenp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:50:38 by jkorvenp          #+#    #+#             */
/*   Updated: 2025/07/10 17:51:29 by jkorvenp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>

typedef struct node
{
	long		data;
	struct node	*prev;
	struct node	*next;
} stack;

void	sa(stack *a);
void	sb(stack *b);
void	ss(stack *a, stack *b);
void	pb(stack **a, stack **b);
void	pa(stack **a, stack **b);
void	ra(stack **a);
void	rb(stack **b);
void	rr(stack **a, stack **b);
void	rra(stack **a);
void	rrb(stack **b);
void	rrr(stack **a, stack **b);
long	ft_atol(const char *nptr);
void	sort(stack **a, stack **b);
void	sort_triple(stack **a);
size_t	stack_len(stack *a);
stack	*max_node(stack *a);
stack	*min_node(stack *a);
bool	past_middle_node(stack *x, stack *target);
stack   *find_target_pb(stack *a, stack *b);
stack   *find_target_pa(stack *a, stack *b);
stack	*cheapest_to_pb(stack *a, stack *b);
stack	*cheapest_to_pa(stack *a, stack *b);

#endif