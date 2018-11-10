/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 20:40:05 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/10 23:20:32 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
** In case of error, you must display Error followed by a ’\n’ on the standard error.
** Errors include for example:
**	- some arguments are not integers,
**	- some arguments are bigger than an integer,
**	- there are duplicates,
**	- an instruction don’t exist and/or is incorrectly formatted.
*/

int 	validate_command(char *s, t_ps *stack)
{
	if (ft_strequ(s, "sa"))
		return (0);
	else if (ft_strequ(s, "sb"))
		return (1);
	else if (ft_strequ(s, "ss"))
		return (2);
	else if (ft_strequ(s, "pa"))
		return (3);
	else if (ft_strequ(s, "pb"))
		return (4);
	else if (ft_strequ(s, "ra"))
		return (5);
	else if (ft_strequ(s, "rb"))
		return (6);
	else if (ft_strequ(s, "rr"))
		return (7);
	else if (ft_strequ(s, "rra"))
		return (8);
	else if (ft_strequ(s, "rrb"))
		return (9);
	else if (ft_strequ(s, "rrr"))
		return (10);
	else
		ps_exit(-2, stack);
	return (-1);
}

int		validate_int(const char *s, intmax_t *result)
{
	short	 minus;

	minus = 1;
	if (*s == '-')
	{
		minus = -1;
		s++;
	}
	if (*s < '0' || *s > '9')
		return (0);
	*result = 0;
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		*result = *result * 10 + *s++ - 48;
	}
	*result *= minus;
	return (1);
}

int		validate_duplicates(int *tab, int nbr, int size)
{
	int i;

	i = 0;
	while (i < size)
		if (tab[i++] == nbr)
			return (0);
	return (1);
}

int		validate_order(int *tab, int size)
{
	int i;

	i = -1;
	while (++i < size)
		if (tab[i] < tab[i + 1])
			return (0);
	return (1);
}

int		validate_arg(t_ps *stack, char **arg, int size)
{
	intmax_t	t;
	int 		n;

	n = size - 1;
	stack->a = (int*)malloc(sizeof(int) * (size));
	TA = -1;
	while (n >= 0)
	{
		if (!validate_int(arg[n], &t) || t > INT_MAX || t < INT_MIN)
//			|| !validate_duplicates(stack->a, (int)t, TA))
			ps_exit(-1, stack);
		stack->a[++TA] = (int)t;
		n--;
	}
	stack->b = (int*)malloc(sizeof(int) * (size));
	TB = -1;
	print_stack(stack);
	return (1);
}
