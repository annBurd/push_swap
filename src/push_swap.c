/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 19:42:08 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/14 21:32:07 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//void	ps_choose_cmd(t_ps *stack, int start, int end)
//{
//
//
//}
//
//void 	ps_sort(t_ps *stack, int start, int end)
//{
//	while(1)
//	{
//		ps_choose_cmd(stack, start, end);
//		//check for presence of values in stack B
//		//return them back if their order ok
//		//needs to rewrite
//		if (TB >= 0 && check_order(SA, start, end) &&
//				(!TB || check_reverse_order(SB, 0, TB)))
//			while (TB >= 0)
//				do_pb(stack);
//		if (end == TA && check_order(SA, 0, TA))
//			break ;
//	}
//}

static void	sort_3(t_ps *stack, int size)
{
	const int	min = check_min(stack->a, TA);
	const int	max = check_max(stack->a, TA);

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

static void	sort_6(t_ps *stack, int size)
{

}

int 		main(int argc, char **argv)
{
	t_ps		stack;

	argc == 1 ? ps_exit(NULL, 1) : ps_init(&stack, &argv, &argc, 1);
	if (argc <= 3)
		sort_3(&stack, stack.top[0]);
	else if (argc <= 6)
		sort_6(&stack, stack.top[0]);
//	else if (argc <= 12)
//		sort_2(stack);
//	else
//		sort_3(stack);


//	ps_sort(&stack, 0, stack.top[0]);
	return (ps_exit(&stack, 0));
}
