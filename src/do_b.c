/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:29:30 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/14 21:41:39 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
** sb : swap b - swap the first 2 elements at the top of stack b.
** 		Do nothing if there is only one or no elements).
*/

void	do_sb(t_ps *stack)
{
	int	tmp;

	if (TB <= 0)
		return ;
	tmp = stack->b[TB];
	stack->b[TB] = stack->b[TB - 1];
	stack->b[TB - 1] = tmp;
	if (stack->print)
		write(1, "sb\n", 3);
	if (stack->status)
		ps_print_stack(stack);
}

/*
** pb : push b - take the first element at the top of a
** 		and put it at the top of b.
** 		Do nothing if a is empty.
*/

void	do_pb(t_ps *stack)
{
	if (TA < 0)
		return ;
	TB++;
	stack->b[TB] = stack->a[TA];
	TA--;
	if (stack->print)
		write(1, "pb\n", 3);
	if (stack->status)
		ps_print_stack(stack);
}

/*
** rb : rotate b - shift up all elements of stack b by 1.
** 		The first element becomes the last one.
*/

void	do_rb(t_ps *stack)
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
	if (stack->print)
		write(1, "rb\n", 3);
	if (stack->status)
		ps_print_stack(stack);
}

/*
** rrb : reverse rotate b - shift down all elements of stack b by 1.
** 		The last element becomes the first one.
*/

void	do_rrb(t_ps *stack)
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
	if (stack->print)
		write(1, "rrb\n", 4);
	if (stack->status)
		ps_print_stack(stack);
}
