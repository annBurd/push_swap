/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 15:08:13 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/16 21:49:00 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//int 	get_next_value(int *tab, int i_cur)
//{
//
//}

void	ps_move_min_to_top_A(t_ps *stack, int size)//needs test
{
	int 		min;

	min = ps_min_index(SA, size);
	if (min > TA / 2)
		while (TA - min-- > 0)
			do_rra(stack);
	else
		while (min-- >= 0)
			do_ra(stack);
}

int		is_no_intermediate_values(int *tab, int end)
{
	int 		i;
	const int	first = tab[end];
	const int	last = tab[0];
	int			value;

	i = 0;
	while(++i < end)
	{
		value = tab[i];
		if (value > last && value < first)
			return (0);
	}
	return (1);
}

//int 	choose_rotate(int *tab, int end)
//{
//	const int min = find_min(tab, end);
//	const int max = find_max(tab, end);
//
//
//
//	return (1); //1 for simple rotate otherway if 0 it will be reverse
//}

//void	try_rotate(t_ps *stack)
//{
//	const int	a = check_intermediate_values(SA, TA);
//	const int	b = TB > 0 ? check_intermediate_values(SB, TB) : 0;
//	const int	nullBigger_a = SA[0] > SA[TA] ? 1 : 0;
//	const int	nullBigger_b = TB > 0 && SB[0] > SB[TB] ? 1 : 0;
//	int 		choice[2];
//
//	choice[0] = choose_rotate(SA, TA);
//	choice[1] = choose_rotate(SB, TB);
//	if ((!nullBigger_a && !nullBigger_b) || (!a && !b))
//		return ;
//	if (nullBigger_a && nullBigger_b && a && b && choice[0] == choice[1])
//	{
//		if (choice[0])
//			do_rr(stack);
//		else
//			do_rrr(stack);
//		return ;
//	}
//	if (nullBigger_a && a)
//		choice[0] ? do_ra(stack) : do_rra(stack);
//	if (nullBigger_b && b)
//		choice[1] ? do_rb(stack) : do_rrb(stack);
//}
