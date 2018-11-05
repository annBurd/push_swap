/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 19:57:56 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/05 20:48:15 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
** sa : swap a - swap the first 2 elements at the top of stack a.
** Do nothing if there is only one or no elements).
**
** sb : swap b - swap the first 2 elements at the top of stack b.
** Do nothing if there is only one or no elements).
**
** ss : sa and sb at the same time.
*/

void	do_swap(t_tools stack, t_st which)
{
	//ft_swap() ??
}

/*
** pa : push a - take the first element at the top of b and put it at the top of a.
** Do nothing if b is empty.
**
** pb : push b - take the first element at the top of a and put it at the top of b.
** Do nothing if a is empty.
*/

void	do_push(t_tools stack, t_st which)
{

}

/*
** ra : rotate a - shift up all elements of stack a by 1.
** The first element becomes the last one.
**
** rb : rotate b - shift up all elements of stack b by 1.
** The first element becomes the last one.
**
** rr : ra and rb at the same time.
*/

void	do_rotate(t_tools stack, t_st which)
{

}

/*
** rra : reverse rotate a - shift down all elements of stack a by 1.
** The last element becomes the first one.
**
** rrb : reverse rotate b - shift down all elements of stack b by 1.
** The last element becomes the first one.
**
** rrr : rra and rrb at the same time.
*/

void	do_reverse_rotate(t_tools stack, t_st which)
{

}
