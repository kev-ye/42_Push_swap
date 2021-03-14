/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 20:38:57 by kaye              #+#    #+#             */
/*   Updated: 2021/03/14 19:19:25 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void    clean_all(t_stack *stacks, char *line)
{
    if (line)
        free(line);
    if (stacks)
    {
        ft_lstclear(&stacks->a, NULL);
        ft_lstclear(&stacks->b, NULL);
    }
    free(stacks);
    stacks = NULL;
}