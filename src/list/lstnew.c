/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstnew.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 16:57:23 by kaye              #+#    #+#             */
/*   Updated: 2021/03/13 16:32:22 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

t_data	*lstnew(int data)
{
	t_data	*new;

	new = (t_data *)malloc(sizeof(t_data));
	if (new)
	{
		new->data = data;
		new->next = NULL;
	}
	return (new);
}
