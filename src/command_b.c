/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:29:30 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/07 20:55:06 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	do_swap_b(t_ps *stack)
{
	int	tmp;

	tmp = stack->b[TB];
	stack->b[TB] = stack->b[TB - 1];
	stack->b[TB - 1] = tmp;
}

void	do_push_b(t_ps *stack)
{
	TA++;
	stack->a[TA] = stack->b[TB];
//	stack->b[TB] = 0;
	TB--;
}

void	do_rotate_b(t_ps *stack)
{
	int	tmp;
	int n;
	int top;

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

void	do_reverse_rotate_b(t_ps *stack)
{
	int tmp;
	int n;
	int top;

	n = stack->size - 1;
	top = 0;
	while (n--)
	{
		tmp = stack->b[top];
		stack->b[top] = stack->b[top + 1];
		stack->b[top + 1] = tmp;
		top++;
	}
}
