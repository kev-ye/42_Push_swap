/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 19:18:28 by kaye              #+#    #+#             */
/*   Updated: 2021/03/13 22:09:07 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void    op_rra(t_stack *stacks)
{
    t_data *tmp;
    t_data *tmp2;

    if (!stacks->a || lstsize(stacks->a) == 1)
        return ;
    tmp = lstlast(stacks->a);
    tmp2 = stacks->a;
    while (tmp2->next->next)
        tmp2 = tmp2->next;
    tmp2->next = NULL;
    lstadd_front(&stacks->a, tmp);
}

void    op_rrb(t_stack *stacks)
{
    t_data *tmp;
    t_data *tmp2;

    if (!stacks->b || lstsize(stacks->b) == 1)
        return ;
    tmp = lstlast(stacks->b);
    tmp2 = stacks->b;
    while (tmp2->next->next)
        tmp2 = tmp2->next;
    tmp2->next = NULL;
    lstadd_front(&stacks->b, tmp);
}

void    op_rrr(t_stack *stacks)
{
    op_rra(stacks);
    op_rrb(stacks);
}