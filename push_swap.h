/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorvenp <jkorvenp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:50:38 by jkorvenp          #+#    #+#             */
/*   Updated: 2025/06/19 17:41:05 by jkorvenp         ###   ########.fr       */
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
char	**ft_split(char const *s, char c);
long	ft_atoi(const char *nptr);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strdup(const char *s);

typedef struct{
	long	*stack;
	size_t	size;
} datastruct;



long	ft_atoi(const char *nptr);


#endif