/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundred_less.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 18:57:45 by kaye              #+#    #+#             */
/*   Updated: 2021/03/17 20:39:27 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	in_stack_b(t_stack *stacks)
{
	while (stacks->b)
	{
		stacks->bigger = get_bigger(stacks->b);
		stacks->smaller = get_smaller(stacks->b);
		if ((int)stacks->b->content == stacks->smaller)
		{
			do_pa(stacks);
			do_ra(stacks);
		}
		else if ((int)stacks->b->content == stacks->bigger)
			do_pa(stacks);
		else if ((int)stacks->b->content > stacks->smaller
			&& (int)stacks->b->content < stacks->bigger)
			do_rb(stacks);
	}
}

static void	below_median(t_stack *stacks, int i, int size)
{
	while (i < size / 2)
	{
		if ((int)stacks->a->content < stacks->median)
		{
			do_pb(stacks);
			++i;
		}
		else
			do_ra(stacks);
	}
}

static void	above_median(t_stack *stacks, int i, int size)
{
	while (i > size / 2)
	{
		if ((int)stacks->a->content >= stacks->median)
		{
			do_pb(stacks);
			--i;
		}
	}
}

void	action_for_hundred_less(t_stack *stacks)
{
	int	i;
	int	size;

	size = ft_lstsize(stacks->a);
	i = 0;
	below_median(stacks, i, size);
	in_stack_b(stacks);
	while (stacks->a && (int)stacks->a->content < stacks->median)
		do_ra(stacks);
	i = size;
	above_median(stacks, i, size);
	in_stack_b(stacks);
	while (stacks->a && (int)stacks->a->content > stacks->median)
		do_ra(stacks);
}
