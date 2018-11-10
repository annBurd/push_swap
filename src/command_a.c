/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 19:57:56 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/10 19:41:35 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	do_swap_a(t_ps *stack)
{
	int	tmp;

	tmp = stack->a[TA];
	stack->a[TA] = stack->a[TA - 1];
	stack->a[TA - 1] = tmp;
	print_stack(stack);
}




void	do_push_a(t_ps *stack)
{
	TB++;
	stack->b[TB] = stack->a[TA];
	TA--;
	print_stack(stack);
}

void	do_rotate_a(t_ps *stack)
{
	int	tmp;
	int n;
	int top;

	n = stack->size - 1;
	top = TA;
	while (n--)
	{
		tmp = stack->a[top];
		stack->a[top] = stack->a[top - 1];
		stack->a[top - 1] = tmp;
		top--;
	}
	print_stack(stack);
}

void	do_reverse_rotate_a(t_ps *stack)
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
	print_stack(stack);
}
