/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorvenp <jkorvenp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:50:38 by jkorvenp          #+#    #+#             */
/*   Updated: 2025/07/11 16:04:31 by jkorvenp         ###   ########.fr       */
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
}	t_stack;

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pb(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
long	ft_atol(const char *nptr);
bool	is_sorted(t_stack **a);
void	sort(t_stack **a, t_stack **b);
size_t	stack_len(t_stack *a);
t_stack	*max_node(t_stack *a);
t_stack	*min_node(t_stack *a);
bool	past_middle_node(t_stack *x, t_stack *target);
t_stack	*find_target_pb(t_stack *a, t_stack *b);
t_stack	*find_target_pa(t_stack *a, t_stack *b);
t_stack	*cheapest_to_pb(t_stack *a, t_stack *b);
t_stack	*cheapest_to_pa(t_stack *a, t_stack *b);
void	move_pb(t_stack **a, t_stack **b, t_stack *current, t_stack *target);
void	move_pa(t_stack **a, t_stack **b, t_stack *current, t_stack *target);

#endif