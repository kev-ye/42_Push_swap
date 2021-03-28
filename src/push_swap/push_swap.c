/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 09:42:24 by kaye              #+#    #+#             */
/*   Updated: 2021/03/28 20:40:25 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	ft_lst_is_sorted(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (tmp->next && (int)tmp->content > (int)tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static void	action(t_stack *stacks)
{
	if (ft_lst_is_sorted(stacks->a))
		return ;
	if (ft_lstsize(stacks->a) <= 3)
		action_for_tree_less(stacks);
	else if (ft_lstsize(stacks->a) <= 5)
		action_for_five_less(stacks);
	else
		action_for_hundred_more(stacks);
	return ;
}

int	main(int ac, char **av)
{
	t_stack	*stacks;

	stacks = get_stack_data(ac, av);
	if (stacks && !stacks->flag_v && ac <= 2)
		quit(stacks, NULL, NULL);
	else if (stacks && stacks->flag_v && ac <= 3)
		quit(stacks, NULL, NULL);
	if (!stacks)
		quit(stacks, "Error\n", NULL);
	stacks->median_a = get_median(stacks->a, stacks, ft_lstsize(stacks->a));
	stacks->max = get_bigger(stacks->a);
	action(stacks);
	clean_all(stacks, NULL);
	return (0);
}
