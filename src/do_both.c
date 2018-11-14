/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_both.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:29:47 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/14 21:41:26 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	do_ss(t_ps *stack)
{
	if (TA <= 0 || TB <= 0)
		return ;
	ft_swap(&SA[TA], &SB[TB - 1]);
	ft_swap(&SB[TB], &SB[TB - 1]);
	if (stack->print)
		write(1, "ss\n", 3);
	if (stack->status)
		ps_print_stack(stack);
}

void	do_rr(t_ps *stack)
{
	const short	p = stack->print;
	const short	s = stack->status;

	stack->print = 0;
	stack->status = 0;
	do_ra(stack);
	do_rb(stack);
	stack->print = p;
	stack->status = s;
	if (stack->print)
		write(1, "rr\n", 3);
	if (stack->status)
		ps_print_stack(stack);
}

void	do_rrr(t_ps *stack)
{
	const short	p = stack->print;
	const short	s = stack->status;

	stack->print = 0;
	stack->status = 0;
	do_rra(stack);
	do_rrb(stack);
	stack->print = p;
	stack->status = s;
	if (stack->print)
		write(1, "rrr\n", 4);
	if (stack->status)
		ps_print_stack(stack);
}
