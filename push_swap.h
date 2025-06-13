/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorvenp <jkorvenp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 12:50:38 by jkorvenp          #+#    #+#             */
/*   Updated: 2025/06/13 12:05:35 by jkorvenp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<stdlib.h>

typedef struct{
	long	*stack;
	size_t	size;
} datastruct;

typedef struct node{
	long	data;
	struct	node *prev;
	struct	node	*next;
	
} stack;

long	ft_atoi(const char *nptr);


#endif