/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundred_more.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 12:45:37 by kaye              #+#    #+#             */
/*   Updated: 2021/03/21 14:00:45 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	tree_less(t_stack *stacks)
{
	int	bigger;

	bigger = get_bigger(stacks->a);
	if (bigger == (int)stacks->a->content)
	{
		do_op(stacks, "rb");
		if ((int)stacks->a->content > (int)stacks->a->next->content)
			do_op(stacks, "sb");
	}
	else if (bigger == (int)stacks->a->next->content)
	{
		do_op(stacks, "rrb");
		if ((int)stacks->a->content > (int)stacks->a->next->content)
			do_op(stacks, "sb");
	}
	else if (bigger == (int)stacks->a->next->next->content)
		if ((int)stacks->a->content > (int)stacks->a->next->content)
			do_op(stacks, "sb");
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

static int	push_b_size(t_stack *stacks, int actual_size, int median)
{
	t_list	*tmp;
	int		size;
	int 	i;

	tmp = stacks->a;
	i = 0;
	size = 0;
	while (i < actual_size)
	{
		if ((int)tmp->content <= median)
			size = i;
		tmp = tmp->next;
		++i;
	}
	return (size);
}

static void	in_stack_b(t_stack *stacks)
{
	int size;
	int i;
	int median;
	int actuel_size;
	int smaller;
	int	push_b;
	t_list *median_size_regroup;
	int for_size_regroup;

	median_size_regroup = NULL;
	while (stacks->b)
	{
		for_size_regroup = 0;
		stacks->small_median = get_median(stacks->b, stacks);
		printf("- median : %d\n", stacks->small_median);
		size = ft_lstsize(stacks->b);
		i = size;
		while (i > size / 2)
		{
			if ((int)stacks->b->content >= stacks->small_median)
			{
				//printf("- - - push a : %d\n",(int)stacks->b->content);
				do_op(stacks, "pa");
				--i;
				++for_size_regroup;
			}
			else
				do_op(stacks, "rb");
		}
		if (!median_size_regroup)
			median_size_regroup = ft_lstnew((void *)(intptr_t)for_size_regroup);
		else
			ft_lstadd_front(&median_size_regroup, ft_lstnew((void *)(intptr_t)for_size_regroup));
		printf("- - size : %d\n", for_size_regroup);
	}
	// exit(0);
	// while (median_size_regroup)
	// {
	// 	printf("%d\n", (int)median_size_regroup->content);
	// 	median_size_regroup = median_size_regroup->next;
	// }
	// exit(0);
	int j = 0;
	int k;
	while (median_size_regroup)
	{
		j = 0;
		while (j < (int)median_size_regroup->content)
		{
			do_op(stacks, "pb");
			j++;
		}
		// median = (int)stacks->a->content;
		// actuel_size = stacks->size_small - j;
		// push_b = push_b_size(stacks, actuel_size, median);
		// k = 0;
		// while (k <= push_b)
		// {
		// 	do_op(stacks, "pb");
		// 	++k;
		// }
		// while (stacks->b)
		// {
		// 	smaller = get_smaller(stacks->b);
		// 	if ((int)stacks->b->content == smaller)
		// 	{
		// 		do_op(stacks, "pa");
		// 		do_op(stacks, "ra");
		// 		++j;
		// 	}
		// 	else
		// 		do_op(stacks, "rb");
		// }
		while (stacks->b)
		{
			stacks->bigger = get_bigger(stacks->b);
			stacks->smaller = get_smaller(stacks->b);
			if ((int)stacks->b->content == stacks->smaller)
			{
				do_op(stacks, "pa");
				do_op(stacks, "ra");
				// ++j;
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
		median_size_regroup = median_size_regroup->next;
	}
	while ((int)stacks->a->content < stacks->median)
			do_op(stacks, "ra");
}

static void	in_stack_b2(t_stack *stacks)
{
	int size;
	int i;
	int median;
	int actuel_size;
	int smaller;
	int	push_b;
	t_list *median_size_regroup;
	int for_size_regroup;

	median_size_regroup = NULL;
	while (stacks->b)
	{
		for_size_regroup = 0;;
		stacks->big_median = get_median(stacks->b, stacks);
		//printf("- median : %d\n", stacks->big_median);
		size = ft_lstsize(stacks->b);
		i = size;
		while (i > size / 2)
		{
			if ((int)stacks->b->content >= stacks->big_median)
			{
				printf("- - - push a : %d\n",(int)stacks->b->content);
				do_op(stacks, "pa");
				--i;
			}
			else
				do_op(stacks, "rb");
		}
		if (!median_size_regroup)
			median_size_regroup = ft_lstnew((void *)(intptr_t)for_size_regroup);
		else
			ft_lstadd_front(&median_size_regroup, ft_lstnew((void *)(intptr_t)for_size_regroup));
	}
	// while (median_size_regroup)
	// {
	// 	printf("%d\n", (int)median_size_regroup->content);
	// 	median_size_regroup = median_size_regroup->next;
	// }
	exit(0);
	int j = 0;
	int k;
	while (median_size_regroup)
	{
		j = 0;
		while (j <= (int)median_size_regroup->content)
		{
			do_op(stacks, "pb");
			j++;
		}
		// exit(0);
		// median = (int)stacks->a->content;
		// actuel_size = stacks->size_small - j;
		// push_b = push_b_size(stacks, actuel_size, median);
		// k = 0;
		// while (k <= push_b)
		// {
		// 	do_op(stacks, "pb");
		// 	++k;
		// }
		// while (stacks->b)
		// {
		// 	smaller = get_smaller(stacks->b);
		// 	if ((int)stacks->b->content == smaller)
		// 	{
		// 		do_op(stacks, "pa");
		// 		do_op(stacks, "ra");
		// 		++j;
		// 	}
		// 	else
		// 		do_op(stacks, "rb");
		// }
		while (stacks->b)
		{
			stacks->bigger = get_bigger(stacks->b);
			stacks->smaller = get_smaller(stacks->b);
			if ((int)stacks->b->content == stacks->smaller)
			{
				do_op(stacks, "pa");
				do_op(stacks, "ra");
				// ++j;
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
		median_size_regroup = median_size_regroup->next;
	}
	while ((int)stacks->a->content > stacks->median)
			do_op(stacks, "ra");
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
	exit(0);
	i = size;
	above_median(stacks, i, size);
	in_stack_b2(stacks);
}
