/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 19:57:56 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/14 16:30:16 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
** sa : swap a - swap the first 2 elements at the top of stack a.
** 		Do nothing if there is only one or no elements).
*/

void	cmd_sa(t_ps *stack, short print)
{
	int	tmp;

	tmp = stack->a[TA];
	stack->a[TA] = stack->a[TA - 1];
	stack->a[TA - 1] = tmp;
	if (print)
		write(1, "sa\n", 3);
	if (stack->status)
		ps_print_stack(stack);
}

/*
** pa : push a - take the first element at the top of b
** 		and put it at the top of a.
** 		Do nothing if b is empty.
*/

void	cmd_pa(t_ps *stack, short print)
{
	if (TA >= 0)
	{
		TB++;
		stack->b[TB] = stack->a[TA];
		TA--;
	}
	if (print)
		write(1, "pa\n", 3);
	if (stack->status)
		ps_print_stack(stack);
}

/*
** ra : rotate a - shift up all elements of stack a by 1.
** 		The first element becomes the last one.
*/

void	cmd_ra(t_ps *stack, short print)
{
	int	tmp;
	int n;
	int top;

	n = TA;
	top = TA;
	while (n-- > 0)
	{
		tmp = stack->a[top];
		stack->a[top] = stack->a[top - 1];
		stack->a[top - 1] = tmp;
		top--;
	}
	if (print)
		write(1, "ra\n", 3);
	if (stack->status)
		ps_print_stack(stack);
}

/*
** rra : reverse rotate a - shift down all elements of stack a by 1.
** 		The last element becomes the first one.
*/

void	cmd_rra(t_ps *stack, short print)
{
	int tmp;
	int n;
	int top;

	n = TA;
	top = 0;
	while (n-- > 0)
	{
		tmp = stack->a[top];
		stack->a[top] = stack->a[top + 1];
		stack->a[top + 1] = tmp;
		top++;
	}
	if (print)
		write(1, "rra\n", 4);
	if (stack->status)
		ps_print_stack(stack);
}
