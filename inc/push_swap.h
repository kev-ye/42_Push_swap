/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:27:33 by kaye              #+#    #+#             */
/*   Updated: 2021/03/18 13:56:59 by kaye             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "common.h"

/*
** OPERATION
*/
void	do_sa(t_stack *stacks);
void	do_sb(t_stack *stacks);
void	do_ss(t_stack *stacks);
void	do_pa(t_stack *stacks);
void	do_pb(t_stack *stacks);
void	do_ra(t_stack *stacks);
void	do_rb(t_stack *stacks);
void	do_rr(t_stack *stacks);
void	do_rra(t_stack *stacks);
void	do_rrb(t_stack *stacks);
void	do_rrr(t_stack *stacks);
void	do_op(t_stack *stacks, char *op_name);

/*
** ALGO
*/
void	action_for_tree_less(t_stack *stacks);
void	action_for_five_less(t_stack *stacks);
void	action_for_hundred_less(t_stack *stacks);

/*
** UTILS
*/
int		get_bigger(t_list *a_b);
int		get_smaller(t_list *a_b);
void	get_median(t_list *a_b, t_stack *stacks);

#endif