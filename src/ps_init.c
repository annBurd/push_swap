/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 21:22:53 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/14 21:42:41 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	check_duplicates(int *tab, int nbr, int size)
{
	int i;

	i = -1;
	while (++i < size)
		if (tab[i] == nbr)
			return (0);
	return (1);
}

static int	ps_get_int(const char *s, intmax_t *result)
{
	short	minus;

	minus = 1;
	if (*s == '-')
	{
		minus = -1;
		s++;
	}
	*result = 0;
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		*result = *result * 10 + *s++ - 48;
	}
	*result *= minus;
	if (*result > INT_MAX || *result < INT_MIN)
		return (0);
	return (1);
}

static int	ps_fill(t_ps *stack, char **arg, int size)
{
	intmax_t	t;
	int			n;

	stack->a = (int*)malloc(sizeof(int) * (size));
	TA = -1;
	n = size - 1;
	while (n >= 0)
	{
		if (!ps_get_int(arg[n], &t) ||
			!check_duplicates(stack->a, (int)t, TA + 1))
			ps_exit(stack, -1);
		stack->a[++TA] = (int)t;
		n--;
	}
	stack->b = (int*)malloc(sizeof(int) * (size));
	TB = -1;
	return (1);
}

int			ps_init(t_ps *stack, char ***argv, int *argc, short p)
{
	int i;
	int fd;

	i = 1;
	fd = 0;
	stack->print = p;
	stack->status = 0;
	while (argv[0][i][0] == '-')
	{
		if (ft_strequ(argv[0][i], "-s"))
			stack->status = 1;
		else if (ft_strequ(argv[0][i], "-f"))
			fd = open(argv[0][++i], O_RDONLY);
		else
			ps_exit(NULL, -1);
		i++;
	}
	(*argv) += i;
	(*argc) -= i;
	if (stack->print && *argc == 1)
		ps_exit(NULL, 0);
	ps_fill(stack, *argv, *argc);
	return (fd);
}
