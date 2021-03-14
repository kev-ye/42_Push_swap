/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 19:18:52 by kaye              #+#    #+#             */
/*   Updated: 2021/03/14 21:38:07 by kaye             ###   ########.fr       */
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

int main(int ac, char **av)
{
    t_stack *stacks;

    if (ac == 1)
        return (0);
    stacks = get_stack_data(ac, av);
    if (!stacks || !duplication_check(stacks->a))
    {
        clean_all(stacks, NULL);
        ft_putstr("Error\n");
        return (0);
    }
    action(stacks, ac);
    return (0);
}