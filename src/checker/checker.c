/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 19:18:52 by kaye              #+#    #+#             */
/*   Updated: 2021/03/14 18:16:30 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int main(int ac, char **av)
{
    t_stack *stacks;

    if (ac == 1)
        return (0);
    stacks = get_stack_data(ac, av);
    if (!stacks)
    {
        ft_putstr("Error\n");
        return (0);
    }
    action(stacks, ac);
    return (0);
}