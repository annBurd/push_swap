/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:48:52 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/05 20:48:15 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft.h"
#include <stdio.h> //printf

typedef enum	e_st
{
	a = 0,
	b = 1,
	both = 2
}				t_st;

#define A(x) stack->a[x]
#define B(x) stack->b[x]
#define TA stack->top[0] //top of A
#define TB stack->top[1] //analogically

typedef struct	s_ps
{
	int 		*a;
	int 		*b;
	int			top[2];
	const int	size;
}				t_ps;

// static int aa[4][3] = {
//   {11, 12, 13},
//   {21, 22, 23},
//   {31, 32, 33},
//   {41, 42, 43}
// };

/*
** checker
*/

void	checker();

/*
** push_swap
*/

void	push_swap();

/*
** common
*/

int		validate_nums_in_arg(char **arg);

void	do_swap(t_ps *stack, t_st goal);//ft_swap() ??
void	do_push(t_ps *stack, t_st goal);
void	do_rotate(t_ps *stack, t_st goal);
void	do_reverse_rotate(t_ps *stack, t_st goal);

#endif