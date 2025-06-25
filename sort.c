/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkorvenp <jkorvenp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 11:58:10 by jkorvenp          #+#    #+#             */
/*   Updated: 2025/06/25 14:09:04 by jkorvenp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//if < 2 num and sorted already?
//2 num -> swap or 3 num ->sot_three
// send to turk



# include "push_swap.h"

void    sort_triple(stack **a)
{

}


void    sort(stack **a, stack **b)
{
    if (stack_len(a) < 2)
        return;
    else if(stack_len(a)== 2)
    {
        if ((*a)->data > (*a)->next->data)
            sa(a);
    return;
    }
    else if(stack_len(a) == 3)
        sort_triple(a);
    else
        turk(a, b);


}
