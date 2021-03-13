/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 16:57:15 by kaye              #+#    #+#             */
/*   Updated: 2021/03/13 22:07:50 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int  action_check(char *line)
{
    if (!ft_strncmp(line, "sa\n", 3) || !ft_strcmp(line, "sa"))
        return (1);
    else if (!ft_strncmp(line, "sb\n", 3) || !ft_strcmp(line, "sb"))
        return (1);
    else if (!ft_strncmp(line, "ss\n", 3) || !ft_strcmp(line, "ss"))
        return (1);
    else if (!ft_strncmp(line, "pa\n", 3) || !ft_strcmp(line, "pa"))
        return (1);
    else if (!ft_strncmp(line, "pb\n", 3) || !ft_strcmp(line, "pb"))
        return (1);
    else if (!ft_strncmp(line, "ra\n", 3) || !ft_strcmp(line, "ra"))
        return (1);
    else if (!ft_strncmp(line, "rb\n", 3) || !ft_strcmp(line, "rb"))
        return (1);
    else if (!ft_strncmp(line, "rra\n", 4) || !ft_strcmp(line, "rra"))
        return (1);
    else if (!ft_strncmp(line, "rrb\n", 4) || !ft_strcmp(line, "rrb"))
        return (1);
    else if (!ft_strncmp(line, "rrr\n", 4) || !ft_strcmp(line, "rrr"))
        return (1);
    else if (!*line)
        return (1);
    return (0);
}

static void do_action(t_stack *stacks, char *line, int ac)
{
    if (!ft_strncmp(line, "sa\n", 3) || !ft_strcmp(line, "sa"))
        op_sa(stacks);
    else if (!ft_strncmp(line, "sb\n", 3) || !ft_strcmp(line, "sb"))
        op_sb(stacks);
    else if (!ft_strncmp(line, "ss\n", 3) || !ft_strcmp(line, "ss"))
        op_ss(stacks);
    else if (!ft_strncmp(line, "pa\n", 3) || !ft_strcmp(line, "pa"))
        op_pa(stacks);
    else if (!ft_strncmp(line, "pb\n", 3) || !ft_strcmp(line, "pb"))
        op_pb(stacks);
    else if (!ft_strncmp(line, "ra\n", 3) || !ft_strcmp(line, "ra"))
        op_ra(stacks);
    else if (!ft_strncmp(line, "rb\n", 3) || !ft_strcmp(line, "rb"))
        op_rb(stacks);
    else if (!ft_strncmp(line, "rr\n", 4) || !ft_strcmp(line, "rr"))
        op_rr(stacks);
    else if (!ft_strncmp(line, "rra\n", 4) || !ft_strcmp(line, "rra"))
        op_rra(stacks);
    else if (!ft_strncmp(line, "rrb\n", 4) || !ft_strcmp(line, "rrb"))
        op_rrb(stacks);
    else if (!ft_strncmp(line, "rrr\n", 4) || !ft_strcmp(line, "rrr"))
        op_rrr(stacks);
}

static int    is_sorted(t_stack *stacks, int size)
{
    t_data *tmp;

    tmp = stacks->a;
    if (lstsize(tmp) != size)
        return (0);
    while (tmp->next)
    {
        if (tmp->data < tmp->next->data)
            tmp = tmp->next;
        else
            return (0);
    }
    clean_all(stacks);
    return (1);
}

static void     print_stack(t_data *a, t_data *b) // debug
{
    if (a == NULL && b == NULL)
        return ;
    if (a && b)
        printf("A : %d | b : %d\n", a->data, b->data);
    else if (a)
        printf("A : %d | b : \n", a->data);
    else if (b)
        printf("A :   | b : %d\n", b->data);
    if (a && b)
        print_stack(a->next, b->next);
    else if (a)
        print_stack(a->next, NULL);
    else if (b)
        print_stack(NULL, b->next);
}

void    action(t_stack *stacks, int ac)
{
    char *line;
    int r;
    int size;

    size = lstsize(stacks->a);
    r = 1;
    while (r)
    {
        r = get_next_line(STDIN_FILENO, &line);
        if (!action_check(line))
        {
            free(line);
            ft_putstr("ERROR\n");
            return ;
        }
        do_action(stacks, line, ac);
        print_stack(stacks->a, stacks->b); // debug
        free(line);
    }
    if (is_sorted(stacks, size))
        ft_putstr("OK\n");
    else
        ft_putstr("KO\n");
}
