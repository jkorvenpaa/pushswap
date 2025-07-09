/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorvenp <jkorvenp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:50:38 by jkorvenp          #+#    #+#             */
/*   Updated: 2025/07/09 12:44:55 by jkorvenp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <limits.h>

typedef struct node{
	long	data;
	struct	node *prev;
	struct	node	*next;
	
} stack;

void	sa(stack *a);
void	sb(stack *b);
void	ss(stack *a, stack *b);
void	pb(stack **a, stack **b);
void	pa(stack **a, stack **b);
void    ra(stack **a);
void    rb(stack **b);
void    rr(stack **a, stack **b);
void    rra(stack **a);
void    rrb(stack **b);
void    rrr(stack **a, stack **b);
long	ft_atol(const char *nptr);
char	**ft_split(char const *s, char c);
size_t	stack_len(stack *a);
stack	*last_node(stack *a);
stack	*max_node(stack *a);
bool	past_middle_node(stack *x, stack *target);
stack	*min_node(stack *a);
void    sort(stack **a, stack **b);
void    turk(stack **a, stack **b);
stack   *find_target_pb(stack *a, stack *b);
stack   *find_target_pa(stack *a, stack *b);
stack	*cheapest_to_pb(stack *a, stack *b);
stack	*cheapest_to_pa(stack *a, stack *b);
void	move_to_push(stack **a, stack **b, stack *current_push, stack *target);
void print_B(stack *head);
void print_A(stack *head);

#endif