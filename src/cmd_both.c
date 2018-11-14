/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_both.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:29:47 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/14 15:52:38 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
** sa : swap a - swap the first 2 elements at the top of stack a.
** 		Do nothing if there is only one or no elements).
**
** sb : swap b - swap the first 2 elements at the top of stack b.
** 		Do nothing if there is only one or no elements).
**
** ss : sa and sb at the same time.
**
** pa : push a - take the first element at the top of b
** 		and put it at the top of a.
** 		Do nothing if b is empty.
**
** pb : push b - take the first element at the top of a
** 		and put it at the top of b.
** 		Do nothing if a is empty.
**
** ra : rotate a - shift up all elements of stack a by 1.
** 		The first element becomes the last one.
**
** rb : rotate b - shift up all elements of stack b by 1.
** 		The first element becomes the last one.
**
** rr : ra and rb at the same time.
**
** rra : reverse rotate a - shift down all elements of stack a by 1.
** 		The last element becomes the first one.
**
** rrb : reverse rotate b - shift down all elements of stack b by 1.
** 		The last element becomes the first one.
**
** rrr : rra and rrb at the same time.
*/

void	do_ss(t_ps *stack, t_bool print)
{
	do_sa(stack, false);
	do_sb(stack, false);
	if (print)
		write(1, "ss\n", 3);
}

void	do_rr(t_ps *stack, t_bool print)
{
	do_ra(stack, false);
	do_rb(stack, false);
	if (print)
		write(1, "rr\n", 3);
}

void	do_rrr(t_ps *stack, t_bool print)
{
	do_rra(stack, false);
	do_rrb(stack, false);
	if (print)
		write(1, "rrr\n", 4);
}
