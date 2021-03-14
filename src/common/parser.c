/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 19:04:29 by kaye              #+#    #+#             */
/*   Updated: 2021/03/14 13:05:58 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

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
        data = (void *)(uintptr_t)ft_atoi(av[i]);
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