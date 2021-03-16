/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 19:18:52 by kaye              #+#    #+#             */
/*   Updated: 2021/03/16 14:06:46 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int    duplication_check(t_list *a)
{
    t_list *tmp;
    t_list *tmp2;

    tmp = a;
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

static t_stack *flag_check(int *ac, char **av)
{
    t_stack *stacks;
    int i;

    stacks = malloc(sizeof(t_stack));
    if (!stacks)
        return (NULL);
    ft_bzero(stacks, sizeof(t_stack));
    i = 0;
    while (++i < *ac)
    {
        if (ft_strcmp("-v", av[i]))
        {
            stacks->flag_v = 1;
            --*ac;
        }
        else
            break ;
    }
    return (stacks);
}

int main(int ac, char **av)
{
    t_stack *stacks;

    if (ac == 1)
        return (0);
    stacks = flag_check(&ac, av);
    if (!stacks)
    {
        clean_all(stacks, NULL);
        ft_putstr("Error\n");
        return (0);
    }
    stacks = get_stack_data(ac, av, stacks);
    if (!duplication_check(stacks->a))
    {
        clean_all(stacks, NULL);
        ft_putstr("Error\n");
        return (0);
    }
    action(stacks, ac);
    return (0);
}