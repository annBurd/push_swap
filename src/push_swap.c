/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 19:42:08 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/16 19:35:42 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//void 	ps_sort(t_ps *stack, int start, int end)
//{

//}

int 		main(int argc, char **argv)
{
	t_ps		stack;

	argc == 1 ? ps_exit(NULL, 1) : ps_init(&stack, &argv, &argc, 1);
	if (argc <= 3)
		sort_3a(&stack, stack.top[0]);
	else if (argc <= 6)
		sort_6(&stack, stack.top[0] + 1);
//	else if (argc <= 12)
//		sort_2(stack);
//	else
//		sort_3(stack);


//	ps_sort(&stack, 0, stack.top[0]);
	return (ps_exit(&stack, 0));
}
