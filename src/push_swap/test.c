/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:42:31 by kaye              #+#    #+#             */
/*   Updated: 2021/03/16 19:38:48 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void ft_list_sort(t_list **list)
{
	t_list *tmp;
	void *content;

	tmp = *list;
	while (tmp && tmp->next)
	{
	if (((int)tmp->content - (int)tmp->next->content) > 0)
	{
		content = tmp->content;
		tmp->content = tmp->next->content;
		tmp->next->content = content;
		tmp = *list;
	}
	else
		tmp = tmp->next;
	}
}

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
		if ((int)tmp->content > smaller)
			smaller = (int)tmp->content;
		tmp = tmp->next;
	}
	return (smaller);
}

void	*get_median(t_list *a)
{
	t_list *tmp;
	int size;
	int i;
	int median;

	tmp = a;
	size = ft_lstsize(tmp);
	tmp = malloc(sizeof(t_list) * size);
	if (!tmp)
		return (void *)0;
	ft_memcpy(tmp, a, sizeof(t_list) * size);
	ft_list_sort(&tmp);
	while (i < size / 2)
	{
		median = (int)tmp->content;
		tmp = tmp->next;
	}
	return (median);
}

