/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 19:42:08 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/14 17:46:02 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//void	ps_choose_cmd(t_ps *stack, int start, int end, int min, int max)
//{
//
//
//}
//
//void 	ps_sort(t_ps *stack, int start, int end)
//{
//	int	min;
//	int max;
//
//	min = check_min(SA, TA);
//	max = check_max(SA, TA);
//	while(1)
//	{
//		ps_choose_cmd(stack, start, end, min, max);
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

void	sort_0(t_ps *stack, int min, int max)
{
	if (min == 3)
		do_pb(stack);
}

//void	sort_1(t_ps *stack)
//{
//
//}
//
//void	sort_2(t_ps *stack)
//{
//
//}
//
//void	sort_3(t_ps *stack)
//{
//
//}

int 	main(int argc, char **argv)
{
	t_ps		stack;

	printf("push_swap\n");
	stack.print = 1;
	argc == 1 ? ps_exit(0, NULL) : ps_init(&stack, ++argv, --argc);

	if (argc <= 4)
		sort_0(&stack, check_min(stack.a, stack.a[stack.top[0]]),
				check_max(stack.a, stack.a[stack.top[0]]));
//	else if (argc <= 8)
//		sort_1(stack);
//	else if (argc <= 16)
//		sort_2(stack);
//	else
//		sort_3(stack);


//	ps_sort(&stack, 0, stack.top[0]);
	return (0);
}
