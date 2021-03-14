/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 16:57:15 by kaye              #+#    #+#             */
/*   Updated: 2021/03/14 21:37:50 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int  do_action(t_stack *stacks,char *line)
{
    const t_op  op[OP_AMOUT] = {
        {"sa", op_sa}, {"sb", op_sb}, {"ss", op_ss}, {"pa", op_pa},
        {"pb", op_pb}, {"ra", op_ra}, {"rb", op_rb}, {"rr", op_rr},
        {"rra", op_rra}, {"rrb", op_rrb}, {"rrr", op_rrr}
    };
    int i;

    i = -1;
    while (++i < 11)
    {
        if (!ft_strcmp(line, op[i].name))
        {
            op[i].f(stacks);
            print_stack(stacks->a, stacks->b); // debug
            return (1);
        }
        else if (!*line)
            return (1);
    }
    clean_all(stacks, line);
    ft_putstr("ERROR\n");
    return (0);
}

static int    is_sorted(t_stack *stacks, int size)
{
    t_list *tmp;

    tmp = stacks->a;
    if (ft_lstsize(tmp) != size)
        return (0);
    while (tmp->next)
    {
        if ((int)tmp->content < (int)tmp->next->content)
            tmp = tmp->next;
        else
            return (0);
    }
    clean_all(stacks, NULL);
    return (1);
}

void    action(t_stack *stacks, int ac)
{
    char *line;
    int r;
    int size;

    size = ft_lstsize(stacks->a);
    r = 1;
    while (r > 0)
    {
        r = get_next_line(STDIN_FILENO, &line);
        if (!do_action(stacks, line))
            return ;
        free(line);
    }
    if (is_sorted(stacks, size))
        ft_putstr("OK\n");
    else
        ft_putstr("KO\n");
}