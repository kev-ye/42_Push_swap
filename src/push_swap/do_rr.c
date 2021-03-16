/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 22:05:36 by kaye              #+#    #+#             */
/*   Updated: 2021/03/16 22:05:52 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void    do_rra(t_stack *stacks)
{
    op_rra(stacks);
    ft_putstr("rra\n");
}

void    do_rrb(t_stack *stacks)
{
    op_rrb(stacks);
    ft_putstr("rrb\n");
}

void    do_rrr(t_stack *stacks)
{
    op_rrr(stacks);
    ft_putstr("rrr\n");
}