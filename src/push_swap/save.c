/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 11:45:36 by kaye              #+#    #+#             */
/*   Updated: 2021/03/27 18:11:41 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_bigger_size(t_list *a_b, int size)
{
	t_list	*tmp;
	int		bigger;
	int 	i;

	tmp = a_b;
	bigger = (int)tmp->content;
	i = 0;
	while (tmp && i < size)
	{
		if ((int)tmp->content > bigger)
			bigger = (int)tmp->content;
		tmp = tmp->next;
		++i;
	}
	return (bigger);
}

int	get_smaller_size(t_list *a_b, int size)
{
	t_list	*tmp;
	int		smaller;
	int 	i;

	tmp = a_b;
	smaller = (int)tmp->content;
	while (tmp && i < size)
	{
		if ((int)tmp->content < smaller)
			smaller = (int)tmp->content;
		tmp = tmp->next;
		++i;
	}
	return (smaller);
}

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
		stacks->median_b = get_median(stacks->b, stacks, ft_lstsize(stacks->b));
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
	int r_a;
	int i;
	int median;
	int	first_a;

	stacks->split_size = NULL;
	median_split_b(stacks, &stacks->split_size);
	while (stacks->split_size)
	{
		if ((int)stacks->split_size->content == 1)
			do_op(stacks, "ra");
		else if ((int)stacks->split_size->content == 2)
		{
			if ((int)stacks->a->content > (int)stacks->a->next->content)
				do_op(stacks, "sa");
			do_op(stacks, "ra");
			do_op(stacks, "ra");
		}
		else
		{
			i = 0;
			r_a = 0;
			median = get_median(stacks->a, stacks, (int)stacks->split_size->content);
			while (i < (int)stacks->split_size->content)
			{
				if ((int)stacks->a->content >= median)
				{
					do_op(stacks, "ra");
					++i;
					++r_a;
				}
				else
				{
					do_op(stacks, "pb");
					++i;
				}
			}
			i = 0;
			while (i < r_a)
			{
				do_op(stacks, "rra");
				++i;
			}
			first_a = (int)stacks->a->content;
			sort_stack_b(stacks);
			while ((int)stacks->a->content != first_a)
				do_op(stacks, "ra");
			while (i)
			{
				do_op(stacks, "pb");
				--i;
			}
			first_a = (int)stacks->a->content;
			sort_stack_b(stacks);
			while ((int)stacks->a->content != first_a)
				do_op(stacks, "ra");
		}
		stacks->split_size = stacks->split_size->next;
	}
}

void	stack_b_above_median_a(t_stack *stacks)
{
	int r_a;
	int i;
	int median;
	int	first_a;

	stacks->split_size = NULL;
	median_split_b(stacks, &stacks->split_size);
	while (stacks->split_size)
	{
		if ((int)stacks->split_size->content == 1)
			do_op(stacks, "ra");
		else if ((int)stacks->split_size->content == 2)
		{
			if ((int)stacks->a->content > (int)stacks->a->next->content)
				do_op(stacks, "sa");
			do_op(stacks, "ra");
			do_op(stacks, "ra");
		}
		else
		{
			i = 0;
			r_a = 0;
			median = get_median(stacks->a, stacks, (int)stacks->split_size->content);
			while (i < (int)stacks->split_size->content)
			{
				if ((int)stacks->a->content >= median)
				{
					do_op(stacks, "ra");
					++i;
					++r_a;
				}
				else
				{
					do_op(stacks, "pb");
					++i;
				}
			}
			i = 0;
			while (i < r_a)
			{
				do_op(stacks, "rra");
				++i;
			}
			first_a = (int)stacks->a->content;
			sort_stack_b(stacks);
			while ((int)stacks->a->content != first_a)
				do_op(stacks, "ra");
			while (i)
			{
				do_op(stacks, "pb");
				--i;
			}
			first_a = (int)stacks->a->content;
			sort_stack_b(stacks);
			while ((int)stacks->a->content != first_a)
				do_op(stacks, "ra");
		}
		stacks->split_size = stacks->split_size->next;
	}
}