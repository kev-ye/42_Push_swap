/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 22:05:36 by kaye              #+#    #+#             */
/*   Updated: 2021/03/17 20:37:52 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	do_rra(t_stack *stacks)
{
	op_rra(stacks);
	if (!stacks->flag_v)
		ft_putstr("rra\n");
	print_stack(stacks);
}

void	do_rrb(t_stack *stacks)
{
	op_rrb(stacks);
	if (!stacks->flag_v)
		ft_putstr("rrb\n");
	print_stack(stacks);
}

void	do_rrr(t_stack *stacks)
{
	op_rrr(stacks);
	if (!stacks->flag_v)
		ft_putstr("rrr\n");
	print_stack(stacks);
}
