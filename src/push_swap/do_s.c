/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 22:02:36 by kaye              #+#    #+#             */
/*   Updated: 2021/03/16 22:04:05 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    do_sa(t_stack *stacks)
{
    op_sa(stacks);
    ft_putstr("sa\n");
}

void    do_sb(t_stack *stacks)
{
    op_sb(stacks);
    ft_putstr("sb\n");
}

void    do_ss(t_stack *stacks)
{
    op_ss(stacks);
    ft_putstr("ss\n");
}