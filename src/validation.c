/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 20:40:05 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/10 21:49:22 by aburdeni         ###   ########.fr       */
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
		do_swap_a(stack);
	else if (ft_strequ(s, "sb"))
		do_swap_b(stack);
	else if (ft_strequ(s, "ss"))
		do_swap_both(stack);
	else if (ft_strequ(s, "pa"))
		do_push_a(stack);
	else if (ft_strequ(s, "pb"))
		do_push_b(stack);
	else if (ft_strequ(s, "ra"))
		do_rotate_a(stack);
	else if (ft_strequ(s, "rb"))
		do_rotate_b(stack);
	else if (ft_strequ(s, "rr"))
		do_rotate_both(stack);
	else if (ft_strequ(s, "rra"))
		do_reverse_rotate_a(stack);
	else if (ft_strequ(s, "rrb"))
		do_reverse_rotate_b(stack);
	else if (ft_strequ(s, "rrr"))
		do_reverse_rotate_both(stack);
	else
		return (0);
	return (1);
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

int		validate_arg(t_ps *stack, char **arg)
{
	intmax_t	t;
	int 		n;

	n = stack->size - 1;
	stack->a = (int*)malloc(sizeof(int) * (stack->size));
	TA = -1;
	while (n >= 0)
	{
		if (!validate_int(arg[n], &t) || t > INT_MAX || t < INT_MIN)
//			|| !validate_duplicates(stack->a, (int)t, TA))
		{
			free(stack->a);
			return (0);
		}
		stack->a[++TA] = (int)t;
		n--;
	}
	stack->b = (int*)malloc(sizeof(int) * (stack->size));
	TB = -1;
	return (1);
}
