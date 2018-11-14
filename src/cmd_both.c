/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_both.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:29:47 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/14 16:30:24 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	cmd_ss(t_ps *stack, short print)
{
	const short	show = stack->status;
	
	stack->status = 0;
	cmd_sa(stack, 0);
	cmd_sb(stack, 0);
	stack->status = show;
	if (print)
		write(1, "ss\n", 3);
	if (stack->status)
		ps_print_stack(stack);
}

void	cmd_rr(t_ps *stack, short print)
{
	const short	show = stack->status;

	stack->status = 0;
	cmd_ra(stack, 0);
	cmd_rb(stack, 0);
	stack->status = show;
	if (print)
		write(1, "rr\n", 3);
	if (stack->status)
		ps_print_stack(stack);
}

void	cmd_rrr(t_ps *stack, short print)
{
	const short	show = stack->status;

	stack->status = 0;
	cmd_rra(stack, 0);
	cmd_rrb(stack, 0);
	stack->status = show;
	if (print)
		write(1, "rrr\n", 4);
	if (stack->status)
		ps_print_stack(stack);
}
