/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 19:04:29 by kaye              #+#    #+#             */
/*   Updated: 2021/03/14 21:30:58 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static void	*data_check(t_stack *stacks, char **av, int index)
{
	void *data;
	int i;

	i = 0;
	if (av[index][i] == '-' || ft_isdigit(av[index][i]))
		++i;
	else
		return (void *)0;
	while (av[index][i])
	{
		if (!ft_isdigit(av[index][i++]))
			return (void *)0;
	}
	data = (void *)(intptr_t)ft_atoll(av[index]);
	if ((long long)data > INT32_MAX || (long long)data < INT32_MIN)
	{
		clean_all(stacks, NULL);
		return (void *)0;
	}
	return (data);
}

t_stack	*get_stack_data(int ac, char **av)
{
	t_stack	*stacks;
	void	*data;
	int		i;

	i = 0;
	stacks = malloc(sizeof(t_stack));
	if (!stacks)
		return (NULL);
	ft_bzero(stacks, sizeof(t_stack));
	while (++i < ac)
	{
		data = data_check(stacks, av, i);
		if (!data)
			return (NULL);
		if (!stacks->a)
		{
			stacks->a = ft_lstnew(data);
			if (!stacks->a)
				return (NULL);
		}
		else
			ft_lstadd_back(&stacks->a, ft_lstnew(data));
	}
	return (stacks);
}

