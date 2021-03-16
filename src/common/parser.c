/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 19:04:29 by kaye              #+#    #+#             */
/*   Updated: 2021/03/16 18:32:41 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static t_stack *flag_check(int ac, char **av, int *i)
{
	t_stack *stacks;

	stacks = malloc(sizeof(t_stack));
	if (!stacks)
		return (NULL);
	ft_bzero(stacks, sizeof(t_stack));
	while (++*i < ac)
	{
		if (!ft_strcmp("-v", av[*i]) && stacks->flag_v == 0)
			stacks->flag_v = 1;
		else
			break ;
	}
	if (*i > 0)
		--*i;
	return (stacks);
}

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

static int    duplication_check(t_list *a)
{
    t_list *tmp;
    t_list *tmp2;

    tmp = a;
    if (!a)
        return (1);
    while (tmp->next)
    {
        tmp2 = tmp->next;
        while (tmp2)
        {
            if ((int)tmp->content == (int)tmp2->content)
                return (0);
            tmp2 = tmp2->next;
        }
        tmp = tmp->next;
    }
    return (1);
}

t_stack	*get_stack_data(int ac, char **av)
{
	t_stack	*stacks;
	void	*data;
	int		i;

	i = 0;
	stacks = flag_check(ac, av, &i);
	if (!stacks)
		return (NULL);
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
	if (!duplication_check(stacks->a))
		return (NULL);
	return (stacks);
}
