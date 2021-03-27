/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:41:38 by kaye              #+#    #+#             */
/*   Updated: 2021/03/27 18:42:06 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_bigger_size(t_list *a_b, int size)
{
	t_list	*tmp;
	int		bigger;
	int 	i;

	tmp = a_b;
	bigger = (int)tmp->content;
	i = 0;
	while (tmp && i < size)
	{
		if ((int)tmp->content > bigger)
			bigger = (int)tmp->content;
		tmp = tmp->next;
		++i;
	}
	return (bigger);
}

int	get_smaller_size(t_list *a_b, int size)
{
	t_list	*tmp;
	int		smaller;
	int 	i;

	tmp = a_b;
	smaller = (int)tmp->content;
	while (tmp && i < size)
	{
		if ((int)tmp->content < smaller)
			smaller = (int)tmp->content;
		tmp = tmp->next;
		++i;
	}
	return (smaller);
}