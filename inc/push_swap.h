/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:48:52 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/05 20:29:01 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft.h"
#include <stdio.h> //printf()

typedef enum	e_st
{
	a,
	b,
	both
}				t_st;

typedef struct	s_tools
{
	int 		*a;
	int 		*b;
	const int	nums;
}				t_tools;

void	checker();

void	op_swap(t_tools stack, t_st which);
void	op_push(t_tools stack, t_st which);
void	op_rotate(t_tools stack, t_st which);
void	op_reverse_rotate(t_tools stack, t_st which);




#endif