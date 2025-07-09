/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorvenp <jkorvenp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:35:42 by jkorvenp          #+#    #+#             */
/*   Updated: 2025/07/09 12:44:50 by jkorvenp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*converts the initial portion of the string pointed to by nptr to int.*/

#include "push_swap.h"

long	ft_atol(const char *nptr)
{
	long	i;
	long	minc;
	long	out;

	i = 0;
	minc = 0;
	out = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
		{
			minc++;
		}
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		out = out * 10 + nptr[i] - '0';
		i++;
	}
	if (minc % 2 != 0)
		out *= -1;
	return (out);
}
