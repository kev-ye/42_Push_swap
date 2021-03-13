/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 19:18:21 by kaye              #+#    #+#             */
/*   Updated: 2021/03/13 21:14:50 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void    op_pa(t_stack *stacks)
{
    t_data *tmp;

    if (!stacks->b)
        return ;
    tmp = stacks->b->next;
    stacks->b->next = NULL;
    lstadd_front(&stacks->a, stacks->b);
    stacks->b = tmp;
}

void    op_pb(t_stack *stacks)
{
    t_data *tmp;

    if (!stacks->a)
        return ;
    tmp = stacks->a->next;
    stacks->a->next = NULL;
    lstadd_front(&stacks->b, stacks->a);
    stacks->a = tmp;
}