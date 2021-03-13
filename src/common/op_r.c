/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 19:18:24 by kaye              #+#    #+#             */
/*   Updated: 2021/03/13 22:08:47 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void    op_ra(t_stack *stacks)
{
    t_data *tmp;

    if (!stacks->a || lstsize(stacks->a) == 1)
        return ;
    tmp = stacks->a;
    stacks->a = stacks->a->next;
    tmp->next = NULL;
    lstadd_back(&stacks->a, tmp);
}

void    op_rb(t_stack *stacks)
{
    t_data *tmp;

    if (!stacks->b || lstsize(stacks->b) == 1)
        return ;
    tmp = stacks->b;
    stacks->b = stacks->b->next;
    tmp->next = NULL;
    lstadd_back(&stacks->b, tmp);
}

void    op_rr(t_stack *stacks)
{
    op_ra(stacks);
    op_rb(stacks);
}