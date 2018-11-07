/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 20:40:05 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/07 15:45:16 by aburdeni         ###   ########.fr       */
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

int		ps_atoimax(const char *s, intmax_t *result)
{
	short	 minus;

	minus = 1;
	while (*s < 33)
		s++;
	if (*s == '-' || *s == '+')
		(*s++ == '-') && (minus = -1);
	if (*s < '0' || *s > '9')
		return (0);
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		*result = *result * 10 + *s++ - 48;
	}
	*result *= minus;
	return (1);
}

//int	ps_free_stack(t_ps *stack)
//{
//	if (SA)
//		free(SA);
//	if (SB)
//		free(SB);
//	return (0);
//}

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

int		validate_nums_in_arg(t_ps *stack, int n, char **arg)
{
	intmax_t	t;

	stack->size = n - 1;
	SA = (int*)malloc(sizeof(int) * (stack->size));
	TA = 0;
	t = 0;
	while (n > 0)
	{
		if (!ps_atoimax(arg[n], &t) || t > INT_MAX || t < INT_MIN ||
			!validate_duplicates(SA, (int)t, TA))
		{
			write(2, "Error\n", 6);
			free(SA);
			return (0);
		}
		SA[TA] = (int)t;
		n--;
		TA++;
	}
	SB = (int*)malloc(sizeof(int) * (stack->size));
	TB = 0;
	return (1);
}
