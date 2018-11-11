/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:48:52 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/11 18:52:16 by aburdeni         ###   ########.fr       */
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

typedef struct	s_ps
{
	int 		*a;
	int 		*b;
	char 		*line;
	int			top[2];
}				t_ps;

typedef void	(*cmd)(t_ps *stack);

/*
** checker
*/



/*
** push_swap
*/


/*
** common
*/

void	print_stack(t_ps *stack);
int		ps_exit(short code, t_ps *stack);

int		validate_arg(t_ps *stack, char **arg, int size);
int		validate_int(const char *s, intmax_t *result);
int		validate_duplicates(int *tab, int nbr, int size);
int 	validate_command(char *s, t_ps *stack);
int		validate_order(int *tab, int size);

void	do_swap_a(t_ps *stack);
void	do_swap_b(t_ps *stack);
void	do_swap_both(t_ps *stack);
void	do_push_a(t_ps *stack);
void	do_push_b(t_ps *stack);
void	do_rotate_a(t_ps *stack);
void	do_rotate_b(t_ps *stack);
void	do_rotate_both(t_ps *stack);
void	do_reverse_rotate_a(t_ps *stack);
void	do_reverse_rotate_b(t_ps *stack);
void	do_reverse_rotate_both(t_ps *stack);

#endif