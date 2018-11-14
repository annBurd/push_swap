/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 20:40:05 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/11 18:15:59 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
** In case of error, you must display "Error\n" on the standard error.
** Errors include for example:
**	- some arguments are not integers,
**	- some arguments are bigger than an integer,
**	- there are duplicates,
**	- an instruction don’t exist and/or is incorrectly formatted.
*/

int	ps_exit(short code, t_ps *stack)
{
	if (!code)
		exit(0);
	else if (code == -1)
	{
		free(stack->a);
		write(2, "Error\n", 6);
		exit(0);
	}
	else if (code == -2)
	{
		free(stack->a);
		free(stack->b);
		free(stack->line);
		write(2, "Error\n", 6);
		exit(0);
	}
	else if (code == 1)
	{
		free(stack->a);
		free(stack->b);
		free(stack->line);
	}
	return (0);
}

int	validate_int(const char *s, intmax_t *result)
{
	short	minus;

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

int	validate_duplicates(int *tab, int nbr, int size)
{
	int i;

	i = -1;
	while (++i < size)
		if (tab[i] == nbr)
			return (0);
	return (1);
}

int	validate_order(int *tab, int i, int end)
{
	while (i < end)
	{
		if (tab[i] < tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ps_init(t_ps *stack, char **arg, int size)
{
	intmax_t	t;
	int			n;

	n = size - 1;
	stack->a = (int*)malloc(sizeof(int) * (size));
	TA = -1;
	while (n >= 0)
	{
		if (!validate_int(arg[n], &t) || t > INT_MAX || t < INT_MIN
			|| !validate_duplicates(stack->a, (int)t, TA + 1))
			ps_exit(-1, stack);
		stack->a[++TA] = (int)t;
		n--;
	}
	stack->b = (int*)malloc(sizeof(int) * (size));
	TB = -1;
	print_stack(stack);
	return (1);
}
