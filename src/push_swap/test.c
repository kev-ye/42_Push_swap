/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundred_more.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 12:45:37 by kaye              #+#    #+#             */
/*   Updated: 2021/03/19 23:20:56 by kaye             ###   ########.fr       */
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

static int	get_smaller_with_size(t_list *a_b, int size)
{
	t_list	*tmp;
	int		smaller;
	int 	i;

	tmp = a_b;
	smaller = (int)tmp->content;
	i = 0;
	while (tmp && i < size)
	{
		if ((int)tmp->content < smaller)
			smaller = (int)tmp->content;
		tmp = tmp->next;
		++i;
	}
	return (smaller);
}

static void	in_stack_b(t_stack *stacks)
{
	int size;
	int i;
	int median;
	int size_small;
	int smaller;
	
	while (stacks->b)
	{
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
	}
	int j = 0;
	size_small = stacks->size_small;
	while (j < stacks->size_small)
	{
		median = (int)stacks->a->content;
		while ((int)stacks->a->content <= median || (int)stacks->a->next->content <= median)
			do_op(stacks, "pb");
		while (stacks->b)
		{
			smaller = get_smaller(stacks->b);
			if ((int)stacks->b->content == smaller)
			{
				do_op(stacks, "pa");
				do_op(stacks, "ra");
				++j;
			}
			else
				do_op(stacks, "rb");
		}
	}
}

static void	in_stack_b2(t_stack *stacks)
{
	int size;
	int i;
	int median;
	int size_bigger;
	int smaller;
	
	while (stacks->b)
	{
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
	}
	int j = 0;
	size_bigger = stacks->size_bigger;
	while (j < stacks->size_bigger)
	{
		median = (int)stacks->a->content;
		while (((int)stacks->a->content <= median || (int)stacks->a->next->content <= median) && (int)stacks->a->content >= stacks->median)
			do_op(stacks, "pb");
		while (stacks->b)
		{
			smaller = get_smaller(stacks->b);
			if ((int)stacks->b->content == smaller)
			{
				do_op(stacks, "pa");
				do_op(stacks, "ra");
				++j;
			}
			else
				do_op(stacks, "rb");
		}
	}
}

static void	below_median(t_stack *stacks, int i, int size)
{
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
	stacks->size_small = ft_lstsize(stacks->b);
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
	stacks->size_bigger = ft_lstsize(stacks->b);
}

void	action_for_hundred_more(t_stack *stacks)
{
	int	i;
	int	size;

	size = ft_lstsize(stacks->a);
	i = 0;
	below_median(stacks, i, size);
	in_stack_b(stacks);
	// exit(0);
	i = size;
	above_median(stacks, i, size);
	in_stack_b2(stacks);
}
