/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 19:18:52 by kaye              #+#    #+#             */
/*   Updated: 2021/03/28 20:43:41 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int ac, char **av)
{
	t_stack	*stacks;

	if (ac == 1)
		return (0);
	stacks = get_stack_data(ac, av);
	if (!stacks)
		quit(stacks, "Error\n", NULL);
	if (stacks->a)
	{
		stacks->max = get_bigger(stacks->a);
		action(stacks, ac);
	}
	return (0);
}
