/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundred_less.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 18:57:45 by kaye              #+#    #+#             */
/*   Updated: 2021/03/17 19:34:40 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int    is_sorted(t_stack *stacks, int size)
{
    t_list *tmp;

    tmp = stacks->a;
    if (ft_lstsize(tmp) != size)
        return (0);
    while (tmp->next)
    {
        if ((int)tmp->content < (int)tmp->next->content)
            tmp = tmp->next;
        else
            return (0);
    }
    clean_all(stacks, NULL);
    return (1);
}

void    action_for_hundred_less(t_stack *stacks)
{
	int i;
	int size;

	size = ft_lstsize(stacks->a);
    i = 0;
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
		else if ((int)stacks->b->content > stacks->smaller && (int)stacks->b->content < stacks->bigger)
			do_rb(stacks);
		print_stack(stacks);
	}
	while (stacks->a && (int)stacks->a->content < stacks->median)
		do_ra(stacks);
	i = size;
	while (i > size / 2)
	{
		if ((int)stacks->a->content >= stacks->median)
		{
			do_pb(stacks);
			--i;
		}
		print_stack(stacks);
	}
	if (stacks->b)
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
			else if ((int)stacks->b->content > stacks->smaller && (int)stacks->b->content < stacks->bigger)
				do_rb(stacks);
			print_stack(stacks);
		}
	}
	while (stacks->a && (int)stacks->a->content > stacks->median)
		do_ra(stacks);
	print_stack(stacks);
}