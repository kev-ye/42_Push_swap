/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:27:33 by kaye              #+#    #+#             */
/*   Updated: 2021/03/27 18:44:30 by kaye             ###   ########.fr       */
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
void	action_for_hundred_more(t_stack *stacks);
void	stack_b_below_median_a(t_stack *stacks);
void	stack_b_above_median_a(t_stack *stacks);

/*
** UTILS
*/
int		get_bigger(t_list *a_b);
int		get_smaller(t_list *a_b);
int		get_median(t_list *a_b, t_stack *stacks, int size);
int		get_bigger_size(t_list *a_b, int size);
int		get_smaller_size(t_list *a_b, int size);

#endif