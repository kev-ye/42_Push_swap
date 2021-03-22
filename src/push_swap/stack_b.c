/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 11:45:36 by kaye              #+#    #+#             */
/*   Updated: 2021/03/22 12:38:11 by kaye             ###   ########.fr       */
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

static void	median_split_b(t_stack *stacks, t_list **split_size)
{
	int	count;
	int	size;
	int	i;

	while (stacks->b)
	{
		count = 0;
		stacks->median_b = get_median(stacks->b, stacks);
		size = ft_lstsize(stacks->b);
		i = size;
		while (i > size / 2)
			if ((int)stacks->b->content >= stacks->median_b)
			{
				do_op(stacks, "pa");
				--i;
				++count;
			}
			else
				do_op(stacks, "rb");
		if (!split_size)
			*split_size = ft_lstnew((void *)(intptr_t)count);
		else
			ft_lstadd_front(&*split_size, ft_lstnew((void *)(intptr_t)count));
	}
}

void	stack_b_below_median_a(t_stack *stacks)
{
	int i;

	stacks->split_size = NULL;
	median_split_b(stacks, &stacks->split_size);
	while (stacks->split_size)
	{
		i = 0;
		while (i < (int)stacks->split_size->content)
		{
			do_op(stacks, "pb");
			i++;
		}
		int bigger;
		if (stacks->b)
			bigger = get_bigger(stacks->b);
		sort_stack_b(stacks);
		while ((int)stacks->a->content <= bigger)
			do_op(stacks, "ra");
		stacks->split_size = stacks->split_size->next;
	}
}

void	stack_b_above_median_a(t_stack *stacks)
{
	int	smaller_in_a;
	int	i;

	stacks->split_size = NULL;
	median_split_b(stacks, &stacks->split_size);
	while (stacks->split_size)
	{
		i = 0;
		while (i < (int)stacks->split_size->content)
		{
			do_op(stacks, "pb");
			i++;
		}
		int bigger;
		if (stacks->b)
			bigger = get_bigger(stacks->b);
		sort_stack_b(stacks);
		smaller_in_a = get_smaller(stacks->a);
		while ((int)stacks->a->content <= bigger && (int)stacks->a->content != smaller_in_a)
			do_op(stacks, "ra");
		stacks->split_size = stacks->split_size->next;
	}
}