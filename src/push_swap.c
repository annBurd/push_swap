/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 19:42:08 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/14 20:47:32 by aburdeni         ###   ########.fr       */
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

void	sort_3(t_ps *stack, int size)
{
	if (size == MIN && MAX == 0)
		return ;
	else if (size == 1 && !MIN)
		do_sa(stack);
	else if (MIN == 2 && MAX == 1)
	{
		do_pb(stack);
		do_sa(stack);
		do_pa(stack);
	}
	else if (MIN == 0 && MAX == 1)
		do_rra(stack);
	else if (MAX == 2)
	{
		do_ra(stack);
		if (!MIN)
			do_sa(stack);
	}
}

void	sort_6(t_ps *stack, int size)
{

}

int 	main(int argc, char **argv)
{
	t_ps		stack;

	argc == 1 ? ps_exit(0, NULL) : ps_flags(&stack, &argv, &argc, 1);
	argc == 1 && ps_exit(0, NULL);
	ps_init(&stack, argv, argc);
	printf("push_swap\n");
	stack.min = check_min(stack.a, stack.top[0]);
	stack.max = check_max(stack.a, stack.top[0]);
	if (argc <= 3)
		sort_3(&stack, stack.top[0]);
	else if (argc <= 6)
		sort_6(&stack, stack.top[0]);
//	else if (argc <= 12)
//		sort_2(stack);
//	else
//		sort_3(stack);


//	ps_sort(&stack, 0, stack.top[0]);
	return (0);
}
