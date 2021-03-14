/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 17:38:13 by kaye              #+#    #+#             */
/*   Updated: 2021/03/14 22:37:00 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	print_stack(t_list *a, t_list *b)
{
	if (a == NULL && b == NULL)
		return ;
	if (a && b)
		ft_printf("%12d | %-12d\n", (int)a->content, (int)b->content);
	else if (a)
		ft_printf("%12d | %-12c\n", (int)a->content, ' ');
	else if (b)
		ft_printf("%12c | %-12d\n", ' ', (int)b->content);
	if (a && b)
		print_stack(a->next, b->next);
	else if (a)
		print_stack(a->next, NULL);
	else if (b)
		print_stack(NULL, b->next);
}