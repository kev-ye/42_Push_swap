/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_less.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 18:48:53 by kaye              #+#    #+#             */
/*   Updated: 2021/03/17 20:31:34 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	action_for_tree_less(t_stack *stacks)
{
	int	bigger;

	bigger = get_bigger(stacks->a);
	if (bigger == (int)stacks->a->content)
	{
		do_ra(stacks);
		if ((int)stacks->a->content > (int)stacks->a->next->content)
			do_sa(stacks);
	}
	else if (bigger == (int)stacks->a->next->content)
	{
		do_rra(stacks);
		if ((int)stacks->a->content > (int)stacks->a->next->content)
			do_sa(stacks);
	}
	else if (bigger == (int)stacks->a->next->next->content)
		if ((int)stacks->a->content > (int)stacks->a->next->content)
			do_sa(stacks);
}

void	action_for_five_less(t_stack *stacks)
{
	int	bigger;
	int	smaller;

	bigger = get_bigger(stacks->a);
	smaller = get_smaller(stacks->a);
	while (ft_lstsize(stacks->b) != 2)
	{
		if ((int)stacks->a->content == bigger
			|| (int)stacks->a->content == smaller)
			do_pb(stacks);
		else
			do_ra(stacks);
	}
	action_for_tree_less(stacks);
	if ((int)stacks->b->content > (int)stacks->b->next->content)
		do_sb(stacks);
	do_pa(stacks);
	do_pa(stacks);
	do_ra(stacks);
}
