/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorvenp <jkorvenp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:50:38 by jkorvenp          #+#    #+#             */
/*   Updated: 2025/07/02 17:04:37 by jkorvenp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<stdlib.h>
# include<unistd.h>

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
long	ft_atoi(const char *nptr);
size_t	stack_len(stack *a);
stack	last_node(stack *a);
long	max_node(stack *a);
char	**ft_split(char const *s, char c);
long	min_node(stack *a);
void    sort(stack **a, stack **b);
void    sort_triple(stack **a);
int		is_sorted(stack **a);
void    turk(stack **a, stack **b);
size_t	push_cost(stack *x, stack *target);





#endif