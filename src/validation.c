/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 20:40:05 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/09 20:27:21 by aburdeni         ###   ########.fr       */
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
		do_reverse_rotate_both(stack);
	else
		return (-1);
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

int		validate_duplicates(int *tab, int nbr, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		if (tab[i] == nbr)
			return (0);
		i++;
	}
	return (1);
}

int		validate_order(t_ps *stack)
{
	int	n;
	int i;

	if (stack->top[1] != -1 || stack->top[0] != stack->size - 1)
		return (0);
	n = stack->size - 1;
	i = 0;
	while (n--)
	{
		if (stack->a[i] < stack->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int						validate_arg(t_ps *stack, int n, char **arg)
{
	intmax_t	t;

	stack->size = n--;
	stack->a = (int*)malloc(sizeof(int) * (stack->size));
	stack->top[0] = 0;
	t = 0;
	while (n > 0)
	{
		if (!validate_int(arg[n], &t) || t > INT_MAX || t < INT_MIN ||
			!validate_duplicates(stack->a, (int)t, stack->top[0]))
		{
			free(stack->a);
			return (0);
		}
		stack->a[stack->top[0]] = (int)t;
		n--;
		stack->top[0]++;
	}
	stack->b = (int*)malloc(sizeof(int) * (stack->size));
	stack->top[1] = -1;
	return (1);
}
