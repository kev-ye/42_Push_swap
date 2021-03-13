/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 19:01:40 by kaye              #+#    #+#             */
/*   Updated: 2021/03/13 21:49:15 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void    op_sa(t_stack *stacks)
{
    int tmp;

    if (!stacks->a || lstsize(stacks->a) == 1)
        return ;
    tmp = stacks->a->data;
    stacks->a->data = stacks->a->next->data;
    stacks->a->next->data = tmp;
}

void    op_sb(t_stack *stacks)
{
    int tmp;

    if (!stacks->b || lstsize(stacks->b) == 1)
        return ;
    tmp = stacks->b->data;
    stacks->b->data = stacks->b->next->data;
    stacks->b->next->data = tmp;
}

void    op_ss(t_stack *stacks)
{
    op_sa(stacks);
    op_sb(stacks);
}