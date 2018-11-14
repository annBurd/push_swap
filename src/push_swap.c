/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 19:42:08 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/14 19:31:03 by aburdeni         ###   ########.fr       */
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
////		ps_choose_cmd(stack, start, end);
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

void	sort_3(int *tab, int min, int max, int size)
{
	if (size == 1 && !min)
		do_sa(stack);
	if (!size || (size == 1 && min == 1) || (min == 2 && MAX == 0))
		return ;
	else if (MIN == 2 && MAX == 1)
	{
		do_pb(stack);
		do_sa(stack);
		do_pa(stack);
	}
	else if (MIN == 1 && MAX == 0)
		do_sa(stack);
	else if (MIN == 1 && MAX == 2)
		do_ra(stack);
	else if (MIN == 0 && MAX == 1)
		do_rra(stack);
	else if (MIN == 0 && MAX == 2)
	{
		do_ra(stack);
		do_sa(stack);
	}
}

//void	sort_6(t_ps *stack)
//{
//
//}

int 	main(int argc, char **argv)
{
	t_ps		stack;

	printf("push_swap\n");
	argc == 1 ? ps_exit(0, NULL) : ps_flags(&stack, &argv, &argc, 1);
	ps_init(&stack, argv, argc);
	stack.min = check_min(stack.a, stack.top[0]);
	stack.max = check_max(stack.a, stack.top[0]);
	if (argc <= 3)
		sort_3(&stack);
//	else if (argc <= 6)
//		sort_6(stack);
//	else if (argc <= 12)
//		sort_2(stack);
//	else
//		sort_3(stack);


//	ps_sort(&stack, 0, stack.top[0]);
	return (0);
}
