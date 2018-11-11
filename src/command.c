/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:29:47 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/10 19:16:03 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
** sa : swap a - swap the first 2 elements at the top of stack a.
** 		Do nothing if there is only one or no elements).
**
** sb : swap b - swap the first 2 elements at the top of stack b.
** 		Do nothing if there is only one or no elements).
**
** ss : sa and sb at the same time.
**
** pa : push a - take the first element at the top of b
** 		and put it at the top of a.
** 		Do nothing if b is empty.
**
** pb : push b - take the first element at the top of a
** 		and put it at the top of b.
** 		Do nothing if a is empty.
**
** ra : rotate a - shift up all elements of stack a by 1.
** 		The first element becomes the last one.
**
** rb : rotate b - shift up all elements of stack b by 1.
** 		The first element becomes the last one.
**
** rr : ra and rb at the same time.
**
** rra : reverse rotate a - shift down all elements of stack a by 1.
** 		The last element becomes the first one.
**
** rrb : reverse rotate b - shift down all elements of stack b by 1.
** 		The last element becomes the first one.
**
** rrr : rra and rrb at the same time.
*/

void	do_swap_both(t_ps *stack)
{
	do_swap_a(stack);
	do_swap_b(stack);
}

void	do_rotate_both(t_ps *stack)
{
	do_rotate_a(stack);
	do_rotate_b(stack);
}

void	do_reverse_rotate_both(t_ps *stack)
{
	do_reverse_rotate_a(stack);
	do_reverse_rotate_b(stack);
}

void	print_stack(t_ps *stack)
{
	int	i;

	i = TA;
	printf("A:");
	while (i >= 0)
		printf(" %d", stack->a[i--]);
	printf("\nB:");
	i = TB;
	while (i >= 0)
		printf(" %d", stack->b[i--]);
	printf("\n");
}

int		ps_exit(short code, t_ps *stack)
{
	if (!code)
		exit(0);
	else if (code == -1)
	{
		free(stack->a);
		write(2, "Error\n", 6);
		exit(0);
	}
	else if (code == -2)
	{
		free(stack->a);
		free(stack->b);
		free(stack->line);
		write(2, "Error\n", 6);
		exit(0);
	}
	else if (code == 1)
	{
		free(stack->a);
		free(stack->b);
		free(stack->line);
	}
	return (0);
}
