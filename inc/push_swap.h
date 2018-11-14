/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:48:52 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/14 16:30:26 by aburdeni         ###   ########.fr       */
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

typedef struct	s_ps
{
	int 		*a;
	int 		*b;
	char 		*line;
	int			top[2];
	short		status;
}				t_ps;

typedef void	(*cmd)(t_ps *stack, short print);

/*
** push_swap
*/

void 	ps_sort(t_ps *stack, int start, int end);
void	ps_choose_cmd(t_ps *stack, int start, int end, int min, int max);


/*
** checker
*/

int 	define_cmd(char *s, t_ps *stack);

/*
** common
*/

void	ps_print_stack(t_ps *stack);
int		ps_exit(short code, t_ps *stack);
int		ps_init(t_ps *stack, char **arg, int size);
int		ps_get_int(const char *s, intmax_t *result);

int		check_duplicates(int *tab, int nbr, int size);
int		check_order(int *tab, int start, int end);
int		check_reverse_order(int *tab, int i, int end);
int		check_min(int *tab, int size);
int		check_max(int *tab, int size);
int		check_intermediate_values(int *tab, int end);

void	cmd_sa(t_ps *stack, short print);
void	cmd_sb(t_ps *stack, short print);
void	cmd_ss(t_ps *stack, short print);
void	cmd_pa(t_ps *stack, short print);
void	cmd_pb(t_ps *stack, short print);
void	cmd_ra(t_ps *stack, short print);
void	cmd_rb(t_ps *stack, short print);
void	cmd_rr(t_ps *stack, short print);
void	cmd_rra(t_ps *stack, short print);
void	cmd_rrb(t_ps *stack, short print);
void	cmd_rrr(t_ps *stack, short print);

#endif