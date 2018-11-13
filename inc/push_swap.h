/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:48:52 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/11 19:07:07 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft.h"
#include "color.h"
#include "limits.h"

#include <stdio.h> //printf

#define TA stack->top[0] //current (end)
#define TB stack->top[1]
#define STACK_PART 8

typedef struct	s_ps
{
	int 		*a;
	int 		*b;
	char 		*line;
	int			top[2];
}				t_ps;

typedef enum	e_bool //do I really need it?
{
	true = 1,
	false = 0
}				t_bool;

typedef void	(*cmd)(t_ps *stack, t_bool print);

/*
** push_swap
*/

void 	ps_sorting(t_ps *stack, int start, int end);
int		validate_reverse_order(int *tab, int i, int end);

/*
** checker
*/

int 	define_cmd(char *s, t_ps *stack);

/*
** common
*/

void	print_stack(t_ps *stack); // del me
int		ps_exit(short code, t_ps *stack);

int		validate_arg(t_ps *stack, char **arg, int size);
int		validate_int(const char *s, intmax_t *result);
int		validate_duplicates(int *tab, int nbr, int size);
int		validate_order(int *tab, int start, int end);

void	do_swap_a(t_ps *stack, t_bool print);
void	do_swap_b(t_ps *stack, t_bool print);
void	do_swap_both(t_ps *stack, t_bool print);
void	do_push_a(t_ps *stack, t_bool print);
void	do_push_b(t_ps *stack, t_bool print);
void	do_rotate_a(t_ps *stack, t_bool print);
void	do_rotate_b(t_ps *stack, t_bool print);
void	do_rotate_both(t_ps *stack, t_bool print);
void	do_reverse_rotate_a(t_ps *stack, t_bool print);
void	do_reverse_rotate_b(t_ps *stack, t_bool print);
void	do_reverse_rotate_both(t_ps *stack, t_bool print);

#endif