/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:29:30 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/14 16:30:12 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
** sb : swap b - swap the first 2 elements at the top of stack b.
** 		Do nothing if there is only one or no elements).
*/

void	cmd_sb(t_ps *stack, short print)
{
	int	tmp;

	tmp = stack->b[TB];
	stack->b[TB] = stack->b[TB - 1];
	stack->b[TB - 1] = tmp;
	if (print)
		write(1, "sb\n", 3);
	if (stack->status)
		ps_print_stack(stack);
}

/*
** pb : push b - take the first element at the top of a
** 		and put it at the top of b.
** 		Do nothing if a is empty.
*/

void	cmd_pb(t_ps *stack, short print)
{
	if (TB >= 0)
	{
		TA++;
		stack->a[TA] = stack->b[TB];
		TB--;
	}
	if (print)
		write(1, "pb\n", 3);
	if (stack->status)
		ps_print_stack(stack);
}

/*
** rb : rotate b - shift up all elements of stack b by 1.
** 		The first element becomes the last one.
*/

void	cmd_rb(t_ps *stack, short print)
{
	int	tmp;
	int n;
	int top;

	n = TB;
	top = TB;
	while (n-- > 0)
	{
		tmp = stack->b[top];
		stack->b[top] = stack->b[top - 1];
		stack->b[top - 1] = tmp;
		top--;
	}
	if (print)
		write(1, "rb\n", 3);
	if (stack->status)
		ps_print_stack(stack);
}

/*
** rrb : reverse rotate b - shift down all elements of stack b by 1.
** 		The last element becomes the first one.
*/

void	cmd_rrb(t_ps *stack, short print)
{
	int tmp;
	int n;
	int top;

	n = TB;
	top = 0;
	while (n-- > 0)
	{
		tmp = stack->b[top];
		stack->b[top] = stack->b[top + 1];
		stack->b[top + 1] = tmp;
		top++;
	}
	if (print)
		write(1, "rrb\n", 4);
	if (stack->status)
		ps_print_stack(stack);
}
