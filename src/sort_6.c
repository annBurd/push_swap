/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 19:26:31 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/16 21:13:26 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void		sort_3a(t_ps *stack, const int size)
{
	const int	min = ps_min_index(stack->a, TA);
	const int	max = ps_max_index(stack->a, TA);

	if (size == min && max == 0)
		return ;
	else if (size == 1 && !min)
		do_sa(stack);
	else if (min == 2 && max == 1)
	{
		do_pb(stack);
		do_sa(stack);
		do_pa(stack);
	}
	else if (min == 0 && max == 1)
		do_rra(stack);
	else if (max == 2)
	{
		do_ra(stack);
		if (!min)
			do_sa(stack);
	}
}

static void	sort_3ab(t_ps *stack, const int size)
{
	const int	minA = ps_min_index(stack->a, TA);
	const int	maxA = ps_max_index(stack->a, TA);
	const int	minB = ps_min_index(stack->b, TB);
	const int	maxB = ps_max_index(stack->b, TB);

	if (minA == size && !maxA && !minB && maxB == size)
		return ;
//	else if ()
}

void	sort_6(t_ps *stack, int size)
{
	int	min;
	int	max;
	int i;

	min = ps_min_index(stack->a, TA);
	max = ps_max_index(stack->a, TA);
	//	if (min <= 2)
	//	{
	//		i = min + 1;
	//		while
	//	}
	if (min > 2)
	{
		i = size - min;
		while(i-- > 0)
			do_pb(stack);
	}
	min = ps_min_index(stack->a, TA);
	if (!TB && min == TA)
	{
		do_pb(stack);
		min = ps_min_index(stack->a, TA);
		if (!min)
			do_rra(stack);
		else if (min == TA - 1)
		{
			if ()
		}
		if (min == TA)
	}


	if (TA == 2)
		is_ascending_order(SB, TB) ? sort_3a(stack, TB) : sort_3ab(stack, TB);


	while (TB > -1)
		do_pa(stack);
	if (!is_descending_order(SA, TA))
		sort_6(stack, TA + 1);
}
