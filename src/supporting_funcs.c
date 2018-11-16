/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supporting_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 20:40:05 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/14 21:38:53 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
** In case of error, you must display "Error\n" on the standard error.
** Errors include for example:
**	- some arguments are not integers // -1
**	- some arguments are bigger than an integer // -1
**	- there are duplicates // -1
**	- an instruction don’t exist and/or is incorrectly formatted // -2
*/

int		ps_exit(t_ps *stack, short code)
{
	if (stack)
	{
		free(stack->a);
		if (code != -1)
			free(stack->b);
		if (!stack->print)
			free(stack->line);
	}
	code < 0 && write(2, "Error\n", 6);
	exit(code);
}

void	ps_print_stack(t_ps *stack)
{
	int	i;

	i = TA;
	write(1, "A:", 2);
	while (i >= 0)
		printf(" %d", stack->a[i--]);
	write(1, "\nB:", 3);
	i = TB;
	while (i >= 0)
		printf(" %d", stack->b[i--]);
	write(1, "\n", 1);
}
