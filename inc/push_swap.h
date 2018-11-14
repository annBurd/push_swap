/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:48:52 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/14 21:38:53 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft.h"
#include "color.h"
#include "limits.h"

#include <stdio.h> //printf

#define TA stack->top[0]
#define TB stack->top[1]
#define SA stack->a
#define SB stack->b
#define MIN stack->min
#define MAX stack->max

typedef struct	s_ps
{
	int 		*a;
	int 		*b;
	char 		*line;
	int			top[2];
	short		print;
	short		status;
	int 		min;
	int 		max;
}				t_ps;

typedef void	(*cmd)(t_ps *stack);

/*
** push_swap
*/

//void 	ps_sort(t_ps *stack, int start, int end);
//void	ps_choose_cmd(t_ps *stack, int start, int end);

//void	sort_6(t_ps *stack, int size);

/*
** checker
*/


/*
** common
*/

int 	ps_init(t_ps *stack, char ***argv, int *argc, short p);
void	ps_print_stack(t_ps *stack);
int		ps_exit(t_ps *stack, short code);

int		check_order(int *tab, int start, int end);
int		check_reverse_order(int *tab, int start, int end);//for stack B
int		check_min(int *tab, int size);
int		check_max(int *tab, int size);
int		check_intermediate_values(int *tab, int end);

void	do_sa(t_ps *stack);
void	do_sb(t_ps *stack);
void	do_ss(t_ps *stack);
void	do_pa(t_ps *stack);
void	do_pb(t_ps *stack);
void	do_ra(t_ps *stack);
void	do_rb(t_ps *stack);
void	do_rr(t_ps *stack);
void	do_rra(t_ps *stack);
void	do_rrb(t_ps *stack);
void	do_rrr(t_ps *stack);

#endif