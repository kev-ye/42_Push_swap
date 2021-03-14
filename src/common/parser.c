/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 19:04:29 by kaye              #+#    #+#             */
/*   Updated: 2021/03/14 19:18:38 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static int  data_check(void *data, t_stack *stacks)
{
    if ((long long)data > INT32_MAX || (long long)data < INT32_MIN)
    {
        clean_all(stacks, NULL);
        return (0);
    }
    return (1);
}

t_stack    *get_stack_data(int ac, char **av)
{
    t_stack *stacks;
    void *data;
    int i;

    i = 0;
    stacks = malloc(sizeof(t_stack));
    if (!stacks)
        return (NULL);
    ft_bzero(stacks, sizeof(t_stack));
    while (++i < ac)
    {
        data = (void *)(intptr_t)ft_atoll(av[i]);
        if (!data_check(data, stacks))
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