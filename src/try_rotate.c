/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 15:08:13 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/14 15:08:13 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int		check_intermediate_values(int *tab, int end)
{
	int 		i;
	const int	first = tab[end];
	const int	last = tab[0];
	int			value;

	i = 1;
	while(i < end)
	{
		value = tab[i];
		if (value > last && value < first)
			return (0);
		i++;
	}
	return (1);
}

int 	choose_rotate(int *tab, int end)
{
	return (1); //for simple rotate otherway if 0 it will be reverse
}

void	try_rotate(t_ps *stack)
{
	const int	a = check_intermediate_values(A_ST, TA);
	const int	b = TB > 0 ? check_intermediate_values(B_ST, TB) : 0;
	const int	nullBigger_a = A_ST[0] > A_ST[TA] ? 1 : 0;
	const int	nullBigger_b = TB > 0 && B_ST[0] > B_ST[TB] ? 1 : 0;
	int 		choice[2];

	choice[0] = choose_rotate(A_ST, TA);
	choice[1] = choose_rotate(B_ST, TB);
	if ((!nullBigger_a && !nullBigger_b) || (!a && !b))
		return ;
	if (nullBigger_a && nullBigger_b && a && b && choice[0] == choice[1])
	{
		if (choice[0])
			do_rr(stack, true);
		else
			do_rrr(stack, true);
		return ;
	}
	if (nullBigger_a && a)
		choice[0] ? do_ra(stack, true) : do_rra(stack, true);
	if (nullBigger_b && b)
		choice[1] ? do_rb(stack, true) : do_rrb(stack, true);
}
