/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_less.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 18:48:53 by kaye              #+#    #+#             */
/*   Updated: 2021/03/27 22:39:50 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_lst_is_sorted(t_list *lst)
{
	t_list *tmp;

	tmp = lst;
	while (tmp)
	{
		if (tmp->next && (int)tmp->content > (int)tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	action_for_tree_less(t_stack *stacks)
{
	int	bigger;

	if (ft_lst_is_sorted(stacks->a))
		return ;
	bigger = get_bigger(stacks->a);
	if (bigger == (int)stacks->a->content)
	{
		do_op(stacks, "ra");
		if ((int)stacks->a->content > (int)stacks->a->next->content)
			do_op(stacks, "sa");
	}
	else if (bigger == (int)stacks->a->next->content)
	{
		do_op(stacks, "rra");
		if ((int)stacks->a->content > (int)stacks->a->next->content)
			do_op(stacks, "sa");
	}
	else if (bigger == (int)stacks->a->next->next->content)
		if ((int)stacks->a->content > (int)stacks->a->next->content)
			do_op(stacks, "sa");
}

void	action_for_five_less(t_stack *stacks)
{
	int	bigger;
	int	smaller;

	if (ft_lst_is_sorted(stacks->a))
		return ;
	bigger = get_bigger(stacks->a);
	smaller = get_smaller(stacks->a);
	while (ft_lstsize(stacks->b) != 2)
	{
		if ((int)stacks->a->content == bigger
			|| (int)stacks->a->content == smaller)
			do_op(stacks, "pb");
		else
			do_op(stacks, "ra");
	}
	action_for_tree_less(stacks);
	if ((int)stacks->b->content > (int)stacks->b->next->content)
		do_op(stacks, "sb");
	do_op(stacks, "pa");
	do_op(stacks, "pa");
	do_op(stacks, "ra");
}
