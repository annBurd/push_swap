/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 19:42:08 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/14 15:49:44 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ps_choose_cmd(t_ps *stack, int start, int end, int min, int max)
{


}

void 	ps_sort(t_ps *stack, int start, int end)
{
	int	min;
	int max;

	min = check_min(SA, TA);
	max = check_max(SA, TA);
	while(1)
	{
		ps_choose_cmd(stack, start, end, min, max);
		//check for presence of values in stack B
		//return them back if their order ok
		//needs to rewrite
		if (TB >= 0 && check_order(SA, start, end) &&
				(!TB || check_reverse_order(SB, 0, TB)))
			while (TB >= 0)
				cmd_pb(stack, 1);
		if (end == TA && check_order(SA, 0, TA))
			break ;
	}
}

int 	main(int argc, char **argv)
{
	t_ps		stack;

	printf("push_swap\n");
	argc == 1 ? ps_exit(0, NULL) : ps_init(&stack, ++argv, --argc);
	ps_sort(&stack, 0, stack.top[0]);
	return (0);
}
