/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 09:42:24 by kaye              #+#    #+#             */
/*   Updated: 2021/03/16 23:19:37 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_bigger(t_list *b)
{
	t_list *tmp;
	int bigger;

	tmp = b;
	bigger = (int)tmp->content;
	while (tmp)
	{
		if ((int)tmp->content > bigger)
			bigger = (int)tmp->content;
		tmp = tmp->next;
	}
	return (bigger);
}

int	get_smaller(t_list *b)
{
	t_list *tmp;
	int smaller;

	tmp = b;
	smaller = (int)tmp->content;
	while (tmp)
	{
		if ((int)tmp->content < smaller)
			smaller = (int)tmp->content;
		tmp = tmp->next;
	}
	return (smaller);
}

void	ft_sort_int_tab(int *tab, int size)
{
	int i;
	int j;
	int tmp;

	i = 0;
	j = 0;
	tmp = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	ft_lst_to_tab(int *tab, t_list *a, int size)
{
	int i;
	t_list *tmp;

	i = 0;
	tmp = a;
	while (i < size)
	{
		tab[i++] = (int)tmp->content;
		tmp = tmp->next;
	}
}

int	get_median(t_list *a, t_stack *stacks)
{
	int *tab;
	int size;
	int median;
	int i;

	size = ft_lstsize(a);
	tab = malloc(sizeof(int) * size);
	if (!tab)
	{
		clean_all(stacks, NULL);
		ft_putstr("ERROR\n");
		exit(0);
	}
	ft_bzero(tab, sizeof(int) * size);
	ft_lst_to_tab(tab, a, size);
	ft_sort_int_tab(tab, size);
	i = 0;
	median = tab[size / 2];
	return (median);
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

void	action(t_stack *stacks)
{
	int i;
	int size;

	i = 0;
	size = ft_lstsize(stacks->a);
	while (i < size / 2)
	{
		if ((int)stacks->a->content < stacks->median)
		{
			do_pb(stacks);
			++i;
		}
		else
			do_ra(stacks);
		print_stack(stacks);
	}
	if (stacks->b)
	{
		while (stacks->b)
		{
			stacks->bigger = get_bigger(stacks->b);
			stacks->smaller = get_smaller(stacks->b);
			if ((int)stacks->b->content == stacks->smaller)
			{
				do_pa(stacks);
				do_ra(stacks);
			}
			else if ((int)stacks->b->content == stacks->bigger)
				do_pa(stacks);
			else if ((int)stacks->b->content > stacks->smaller && (int)stacks->b->content < stacks->smaller)
				do_ra(stacks);
			print_stack(stacks);
		}
	}
	while (stacks->a && (int)stacks->a->content < stacks->median)
		do_ra(stacks);
	i = size;
	while (i > size / 2)
	{
		if ((int)stacks->a->content >= stacks->median)
		{
			do_pb(stacks);
			--i;
		}
		print_stack(stacks);
	}
	if (stacks->b)
	{
		while (stacks->b)
		{
			stacks->bigger = get_bigger(stacks->b);
			stacks->smaller = get_smaller(stacks->b);
			if ((int)stacks->b->content == stacks->smaller)
			{
				do_pa(stacks);
				do_ra(stacks);
			}
			else if ((int)stacks->b->content == stacks->bigger)
				do_pa(stacks);
			else if ((int)stacks->b->content > stacks->smaller && (int)stacks->b->content < stacks->smaller)
				do_ra(stacks);
			print_stack(stacks);
		}
	}
	while (stacks->a && (int)stacks->a->content > stacks->median)
		do_ra(stacks);
	print_stack(stacks);
}

int main(int ac, char **av)
{
	t_stack *stacks;

    if (ac == 1)
        return (0);
    stacks = get_stack_data(ac, av);
    if (!stacks)
    {
        clean_all(stacks, NULL);
        ft_putstr("Error\n");
        return (0);
    }
	stacks->median = get_median(stacks->a, stacks);
	action(stacks);
	// while (stacks->a)
	// {
	// 	printf("%d\n", (int)stacks->a->content);
	// 	stacks->a = stacks->a->next;
	// }
	return (0);
}