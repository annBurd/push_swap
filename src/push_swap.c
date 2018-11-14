/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 19:42:08 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/14 15:11:28 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	validate_reverse_order(int *tab, int i, int end) //for stack B ??
{
	while (i < end)
	{
		if (tab[i] > tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	ps_choose_cmd(t_ps *stack, int start, int end, int min, int max)
{


}

void 	ps_sorting(t_ps *stack, int start, int end)
{
	int	min;
	int max;

	min = ps_find_min(A_ST, TA);
	max = ps_find_max(A_ST, TA);
	while(1)
	{
		ps_choose_cmd(stack, start, end, min, max);
		//check for presence of values in stack B
		//return them back if their order ok
		//needs to rewrite
		if (TB >= 0 && validate_order(A_ST, start, end) &&
				(!TB || validate_reverse_order(B_ST, 0, TB)))
			while (TB >= 0)
				do_pb(stack, true);
		if (end == TA && validate_order(A_ST, 0, TA))
			break ;
	}
}

int 	main(int argc, char **argv)
{
	t_ps		stack;

	printf("push_swap\n");
	argc == 1 ? ps_exit(0, NULL) : ps_init(&stack, ++argv, --argc);
	ps_sorting(&stack, 0, stack.top[0]);
	return (0);
}
