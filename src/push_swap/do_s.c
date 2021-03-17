/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 22:02:36 by kaye              #+#    #+#             */
/*   Updated: 2021/03/17 20:38:16 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_sa(t_stack *stacks)
{
	op_sa(stacks);
	if (!stacks->flag_v)
		ft_putstr("sa\n");
	print_stack(stacks);
}

void	do_sb(t_stack *stacks)
{
	op_sb(stacks);
	if (!stacks->flag_v)
		ft_putstr("sb\n");
	print_stack(stacks);
}

void	do_ss(t_stack *stacks)
{
	op_ss(stacks);
	if (!stacks->flag_v)
		ft_putstr("ss\n");
	print_stack(stacks);
}
