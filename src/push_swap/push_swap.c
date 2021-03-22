/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 09:42:24 by kaye              #+#    #+#             */
/*   Updated: 2021/03/22 12:24:34 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	action(t_stack *stacks)
{
	if (ft_lstsize(stacks->a) <= 3)
		action_for_tree_less(stacks);
	else if (ft_lstsize(stacks->a) <= 5)
		action_for_five_less(stacks);
	else
		action_for_hundred(stacks);
	return ;
}

int	main(int ac, char **av)
{
	t_stack	*stacks;

	if (ac <= 2)
		return (0);
	stacks = get_stack_data(ac, av);
	if (!stacks)
	{
		clean_all(stacks, NULL);
		ft_putstr("Error\n");
		return (0);
	}
	stacks->median_a = get_median(stacks->a, stacks);
	action(stacks);
	return (0);
}
