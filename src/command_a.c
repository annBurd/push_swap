/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 19:57:56 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/11 19:01:12 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	do_sa(t_ps *stack, t_bool print)
{
	int	tmp;

	tmp = stack->a[TA];
	stack->a[TA] = stack->a[TA - 1];
	stack->a[TA - 1] = tmp;
	if (print)
		write(1, "sa\n", 3);
}

void	do_pa(t_ps *stack, t_bool print)
{
	TB++;
	stack->b[TB] = stack->a[TA];
	TA--;
	if (print)
		write(1, "pa\n", 3);
}

void	do_ra(t_ps *stack, t_bool print)
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
}

void	do_rra(t_ps *stack, t_bool print)
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
}
