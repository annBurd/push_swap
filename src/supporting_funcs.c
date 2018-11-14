/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supporting_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 20:40:05 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/14 19:07:01 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
** In case of error, you must display "Error\n" on the standard error.
** Errors include for example:
**	- some arguments are not integers // -1
**	- some arguments are bigger than an integer // -1
**	- there are duplicates // -1
**	- an instruction don’t exist and/or is incorrectly formatted // -2
*/

int		ps_exit(short code, t_ps *stack)
{
	if (!code)
		exit(0);
	else
	{
		free(stack->a);
		if (code == -2 || code == 1)
		{
			free(stack->b);
			free(stack->line);
		}
		if (code < 0)
		{
			write(2, "Error\n", 6);
			exit(0);
		}
	}
	return (0);
}

void	ps_print_stack(t_ps *stack)
{
	int	i;

	i = TA;
	write(1, "A:", 2);
	while (i >= 0)
	{
		write(1, " ", 1);
		ft_putnbr(stack->a[i--]);
	}
	write(1, "\nB:", 3);
	i = TB;
	while (i >= 0)
	{
		write(1, " ", 1);
		ft_putnbr(stack->b[i--]);
	}
	write(1, "\n", 1);
}

int		ps_get_int(const char *s, intmax_t *result)
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

int		ps_init(t_ps *stack, char **arg, int size)
{
	intmax_t	t;
	int			n;

	stack->a = (int*)malloc(sizeof(int) * (size));
	TA = -1;
	n = size - 1;
	while (n >= 0)
	{
		if (!ps_get_int(arg[n], &t) || t > INT_MAX || t < INT_MIN
			|| !check_duplicates(stack->a, (int)t, TA + 1))
			ps_exit(-1, stack);
		stack->a[++TA] = (int)t;
		n--;
	}
	stack->b = (int*)malloc(sizeof(int) * (size));
	TB = -1;
	return (1);
}

int ps_flags(t_ps *stack, char ***argv, int *argc, short p)
{
	int i;
	int fd;

	i = 1;
	fd = 0;
	stack->print = p;
	stack->status = 0;
	while (argv[0][i][0] == '-')
	{
		if (argv[0][i][1] == 's')
			stack->status = 1;
		else if (argv[0][i][1] == 'f')
			fd = open(argv[0][++i], O_RDONLY);
		i++;
	}
	(*argv) += i;
	(*argc) -= i;
	return (fd);
}
