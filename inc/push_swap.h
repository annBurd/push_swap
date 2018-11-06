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

typedef struct	s_stack
{
	int 		*ar;
	int			top;
	const int	size;
}				t_stack;

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

void	do_swap(t_stack stack);//ft_swap() ??
void	do_push(t_stack stack[2], short s);
void	do_rotate(t_stack stack);
void	do_reverse_rotate(t_stack stack[2]);

#endif