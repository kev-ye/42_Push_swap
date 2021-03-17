/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 22:04:48 by kaye              #+#    #+#             */
/*   Updated: 2021/03/17 20:38:12 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	do_ra(t_stack *stacks)
{
	op_ra(stacks);
	if (!stacks->flag_v)
		ft_putstr("ra\n");
	print_stack(stacks);
}

void	do_rb(t_stack *stacks)
{
	op_rb(stacks);
	if (!stacks->flag_v)
		ft_putstr("rb\n");
	print_stack(stacks);
}

void	do_rr(t_stack *stacks)
{
	op_rr(stacks);
	if (!stacks->flag_v)
		ft_putstr("rr\n");
	print_stack(stacks);
}
