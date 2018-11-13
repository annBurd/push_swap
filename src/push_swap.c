/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 19:42:08 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/11 19:53:55 by aburdeni         ###   ########.fr       */
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

//void	ps_find_cmd(t_ps *stack)
//{
//
//}

//void	ps_sort_part(t_ps *stack, int start, int end)
//{
//
//}

void 	ps_sorting(t_ps *stack, int start, int end)
{
	while (end > STACK_PART)
		end = TA / 2;
	while(1)
	{
		//ps_sort_part()
		//check for presence of values in stack B. It must be somewhere here...
		if (end == TA && validate_order(stack->a, 0, TA))
			break ;
		else if (validate_order(stack->a, start, end)) //reassigning to next part
		{
			start = end;
			end = end + STACK_PART > TA ? TA : end + STACK_PART;
		}
	}
}

int 	main(int argc, char **argv)
{
	t_ps		stack;

	printf("push_swap\n");
	argc == 1 ? ps_exit(0, NULL) : validate_arg(&stack, ++argv, --argc);
	ps_sorting(&stack, 0, stack.top[0]);
	return (0);
}
