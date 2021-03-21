/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:27:33 by kaye              #+#    #+#             */
/*   Updated: 2021/03/21 13:09:11 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "common.h"

/*
** OPERATION
*/
void	do_op(t_stack *stacks, char *op_name);

/*
** ALGO
*/
void	action_for_tree_less(t_stack *stacks);
void	action_for_five_less(t_stack *stacks);
void	action_for_hundred_less(t_stack *stacks);
void	action_for_hundred_more(t_stack *stacks); // testing

/*
** UTILS
*/
int		get_bigger(t_list *a_b);
int		get_smaller(t_list *a_b);
int		get_median(t_list *a_b, t_stack *stacks);

#endif