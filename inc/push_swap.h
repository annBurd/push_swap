/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:48:52 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/07 15:40:03 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft.h"
#include "color.h"
#include "limits.h"
#include <stdio.h> //printf

typedef enum	e_st
{
	a = 0,
	b = 1,
	both = 2
}				t_st;

#define SA stack->a
#define SB stack->b
//#define SA(x) stack->a[x]
//#define SB(x) stack->b[x]
#define TA stack->top[0] //top of A
#define TB stack->top[1] //analogically

typedef struct	s_ps
{
	int 		*a;
	int 		*b;
	int			top[2];
	int			size;
}				t_ps;

/*
** checker
*/

int main(int argc, char **argv);
void	checker();

int		ps_atoimax(const char *s, intmax_t *result);
int		validate_nums_in_arg(t_ps *stack, int n, char **arg);
int		ps_free_stack(t_ps *stack);
int		validate_duplicates(int *tab, int nbr, int n);

/*
** push_swap
*/

void	push_swap();

/*
** common
*/


void	do_swap(t_ps *stack, t_st goal);//ft_swap() ??
void	do_push(t_ps *stack, t_st goal);
void	do_rotate(t_ps *stack, t_st goal);
void	do_reverse_rotate(t_ps *stack, t_st goal);

#endif