/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:48:52 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/07 19:52:55 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft.h"
#include "color.h"
#include "limits.h"
#include <stdio.h> //printf

/*
**	write
**	read
**	malloc
**	free
**	exit
*/

#define TA stack->top[0] //top of A
#define TB stack->top[1] //top of B
#define ERROR	write(2, "Error\n", 6); \
				exit(0);

typedef struct	s_ps
{
	int 		*a;
	int 		*b;
	int			top[2];
	int			size;
}				t_ps;

typedef void	(*instr)(t_ps *stack);

/*
** checker
*/

int main(int argc, char **argv);

/*
** push_swap
*/

void	push_swap();

/*
** common
*/

int		ps_atoimax(const char *s, intmax_t *result);
int		validate_nums_in_arg(t_ps *stack, int n, char **arg);
int		validate_duplicates(int *tab, int nbr, int n);
int 	validate_instruction(char *s);
int		validate_order(t_ps *stack);

void	do_swap_a(t_ps *stack);
void	do_push_a(t_ps *stack);
void	do_rotate_a(t_ps *stack);
void	do_reverse_rotate_a(t_ps *stack);
void	do_swap_b(t_ps *stack);
void	do_push_b(t_ps *stack);
void	do_rotate_b(t_ps *stack);
void	do_reverse_rotate_b(t_ps *stack);
void	do_swap_both(t_ps *stack);
void	do_rotate_both(t_ps *stack);
void	do_reverse_rotate_both(t_ps *stack);

#endif