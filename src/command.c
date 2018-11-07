/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:29:47 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/07 20:55:08 by aburdeni         ###   ########.fr       */
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

void	do_swap_both(t_ps *stack)
{
	//	ft_swap(&stack->a[TA], &stack->a[TA - 1]);
	//	ft_swap(&stack->b[TB], &stack->b[TB - 1]);
	int	tmp;

	tmp = stack->a[TA];
	stack->a[TA] = stack->a[TA - 1];
	stack->a[TA - 1] = tmp;
	tmp = stack->b[TB];
	stack->b[TB] = stack->b[TB - 1];
	stack->b[TB - 1] = tmp;
}

void	do_rotate_both(t_ps *stack)
{
	int	tmp;
	int n;
	int top;

	n = stack->size - 1;
	top = stack->top[0];
	while (n--)
	{
		tmp = stack->a[top];
		stack->a[top] = stack->a[top - 1];
		stack->a[top - 1] = tmp;
		top--;
	}
	n = stack->size - 1;
	top = stack->top[1];
	while (n--)
	{
		tmp = stack->b[top];
		stack->b[top] = stack->b[top - 1];
		stack->b[top - 1] = tmp;
		top--;
	}
}

void	do_reverse_rotate_both(t_ps *stack)
{
	int tmp;
	int n;
	int top;

	n = stack->size - 1;
	top = 0;
	while (n--)
	{
		tmp = stack->a[top];
		stack->a[top] = stack->a[top + 1];
		stack->a[top + 1] = tmp;
		top++;
	}
	top = 0;
	n = stack->size - 1;
	while (n--)
	{
		tmp = stack->b[top];
		stack->b[top] = stack->b[top + 1];
		stack->b[top + 1] = tmp;
		top++;
	}
}

