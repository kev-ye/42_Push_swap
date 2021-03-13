/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 20:38:57 by kaye              #+#    #+#             */
/*   Updated: 2021/03/13 20:44:44 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void    clean_all(t_stack *stacks)
{
    if (stacks)
    {
        lstclear(&stacks->a);
        lstclear(&stacks->b);
    }
    free(stacks);
    stacks = NULL;
}