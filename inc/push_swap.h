/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:48:52 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/16 19:43:58 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft.h"
#include "color.h"
#include "limits.h"
#include <stdio.h>

#define TA stack->top[0]
#define TB stack->top[1]
#define SA stack->a
#define SB stack->b

typedef struct	s_ps
{
	int 		*a;
	int 		*b;
	char 		*line;
	int			top[2];
	short		print;
	short		status;
}				t_ps;

typedef void	(*cmd)(t_ps *);

//void 	ps_sort(t_ps *stack, int start, int end);


void	sort_3a(t_ps *, int);
//void	sort_3ab(t_ps *, int);
void	sort_6(t_ps *, int);


int 	ps_init(t_ps *, char ***, int *, short);
void	ps_print_stack(t_ps *);
int		ps_exit(t_ps *, short);

int		check_order(int *, int, int);
int		check_order_b(int *, int, int);//for stack B
int		find_min(int *, int);
int		find_max(int *, int);
int		is_no_intermediate_values(int *, int);

void	do_sa(t_ps *);
void	do_sb(t_ps *);
void	do_ss(t_ps *);
void	do_pa(t_ps *);
void	do_pb(t_ps *);
void	do_ra(t_ps *);
void	do_rb(t_ps *);
void	do_rr(t_ps *);
void	do_rra(t_ps *);
void	do_rrb(t_ps *);
void	do_rrr(t_ps *);

#endif