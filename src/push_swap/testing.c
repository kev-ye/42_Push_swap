/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 20:40:07 by kaye              #+#    #+#             */
/*   Updated: 2021/03/21 13:08:02 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_stack_b(t_stack *stacks)
{
	while (stacks->b)
	{
		stacks->bigger = get_bigger(stacks->b);
		stacks->smaller = get_smaller(stacks->b);
		if ((int)stacks->b->content == stacks->smaller)
		{
			do_op(stacks, "pa");
			do_op(stacks, "ra");
		}
		else if ((int)stacks->b->content == stacks->bigger)
			do_op(stacks, "pa");
		else if ((int)ft_lstlast(stacks->b)->content == stacks->smaller
			|| (int)ft_lstlast(stacks->b)->content == stacks->bigger)
			do_op(stacks, "rrb");
		else if ((int)stacks->b->content > stacks->smaller
			&& (int)stacks->b->content < stacks->bigger)
			do_op(stacks, "rb");
	}
}

static void	in_stack_b(t_stack *stacks)
{
	int size;
	int i;
	
	stacks->small_median = get_median(stacks->b, stacks);
	size = ft_lstsize(stacks->b);
	i = size;
	while (i > size / 2)
	{
		if ((int)stacks->b->content >= stacks->small_median)
		{
			do_op(stacks, "pa");
			--i;
		}
		else
			do_op(stacks, "rb");
	}
	i = 0;
	while (i < size / 2)
	{
		if ((int)stacks->b->content < stacks->small_median)
		{
			do_op(stacks, "pa");
			++i;
		}
		else
			do_op(stacks, "rb");
	}
	while ((int)stacks->a->content < stacks->small_median)
		do_op(stacks, "pb");
	sort_stack_b(stacks);
	while ((int)stacks->a->content <= stacks->small_median)
		do_op(stacks, "ra");
	while ((int)stacks->a->content >= stacks->small_median && (int)stacks->a->content < stacks->median)
		do_op(stacks, "pb");
	sort_stack_b(stacks);
	while ((int)stacks->a->content >= stacks->small_median && (int)stacks->a->content < stacks->median)
		do_op(stacks, "ra");
}

static void	in_stack_b2(t_stack *stacks)
{
	int size;
	int i;
	
	stacks->big_median = get_median(stacks->b, stacks);
	size = ft_lstsize(stacks->b);
	i = size;
	while (i > size / 2)
	{
		if ((int)stacks->b->content >= stacks->big_median)
		{
			do_op(stacks, "pa");
			--i;
		}
		else
			do_op(stacks, "rb");
	}
	i = 0;
	while (i < size / 2)
	{
		if ((int)stacks->b->content < stacks->big_median)
		{
			do_op(stacks, "pa");
			++i;
		}
		else
			do_op(stacks, "rb");
	}
	while ((int)stacks->a->content < stacks->big_median)
		do_op(stacks, "pb");
	sort_stack_b(stacks);
	while ((int)stacks->a->content <= stacks->big_median)
		do_op(stacks, "ra");
	while ((int)stacks->a->content >= stacks->big_median)
		do_op(stacks, "pb");
	sort_stack_b(stacks);
	while ((int)stacks->a->content >= stacks->big_median)
		do_op(stacks, "ra");
}

static void	below_median(t_stack *stacks, int i, int size)
{
	int median;

	while (i < size / 2)
	{
		if ((int)stacks->a->content < stacks->median)
		{
			do_op(stacks, "pb");
			++i;
		}
		else
			do_op(stacks, "ra");
	}
}

static void	above_median(t_stack *stacks, int i, int size)
{
	while (i > size / 2)
	{
		if ((int)stacks->a->content >= stacks->median)
		{
			do_op(stacks, "pb");
			--i;
		}
	}
}

void	action_for_hundred_more(t_stack *stacks)
{
	int	i;
	int	size;

	size = ft_lstsize(stacks->a);
	i = 0;
	below_median(stacks, i, size);
	in_stack_b(stacks);
	i = size;
	above_median(stacks, i, size);
	in_stack_b2(stacks);
	exit(0);
	while (stacks->a && (int)stacks->a->content < stacks->median)
		do_op(stacks, "ra");
	i = size;
	above_median(stacks, i, size);
	in_stack_b(stacks);
	while (stacks->a && (int)stacks->a->content > stacks->median)
		do_op(stacks, "ra");
}
