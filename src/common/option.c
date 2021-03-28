/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 17:38:13 by kaye              #+#    #+#             */
/*   Updated: 2021/03/28 16:37:50 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static void	show_stack(t_list *a, t_list *b)
{
	if (a == NULL && b == NULL)
		return ;
	if (a && b)
		ft_printf("| %12d | %-12d |\n", (int)a->content, (int)b->content);
	else if (a)
		ft_printf("| %12d | %-12c |\n", (int)a->content, ' ');
	else if (b)
		ft_printf("| %12c | %-12d |\n", ' ', (int)b->content);
	if (a && b)
		show_stack(a->next, b->next);
	else if (a)
		show_stack(a->next, NULL);
	else if (b)
		show_stack(NULL, b->next);
}

void	option_v(t_stack *stacks)
{
	if (stacks->flag_v != 1)
		return ;
	usleep(50000);
	ft_putstr("\033[2J\033[H");
	ft_printf("-------------------------------\n");
	ft_printf("| %12s | %-12s |\n", "Stack A", "Stack B");
	ft_printf("-------------------------------\n");
	show_stack(stacks->a, stacks->b);
	ft_printf("-------------------------------\n");
}

void	option_b(t_stack *stacks)
{
	int max;

	if (stacks->flag_b != 1)
		return ;
	usleep(50000);
}