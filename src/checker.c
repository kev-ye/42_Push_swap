/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 19:18:52 by kaye              #+#    #+#             */
/*   Updated: 2021/03/13 18:32:48 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "checker.h"

int main(int ac, char **av)
{
    t_stack *stacks;

    stacks = get_stack_data(ac, av);
    action(stacks, ac);
    return (0);
}