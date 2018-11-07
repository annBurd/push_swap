/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 19:57:56 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/07 19:45:44 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	do_swap_a(t_ps *stack)
{
	int	tmp;

	tmp = stack->a[TA];
	stack->a[TA] = stack->a[TA - 1];
	stack->a[TA - 1] = tmp;
}

void	do_push_a(t_ps *stack)
{
	TB++;
	stack->b[TB] = stack->a[TA];
//	stack->a[TA] = 0;
	TA--;
}

void	do_rotate_a(t_ps *stack)
{

}

void	do_reverse_rotate_a(t_ps *stack)
{

}
