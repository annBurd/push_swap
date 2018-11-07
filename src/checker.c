/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 19:04:34 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/07 19:57:12 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static instr	*get_instruction(void)
{
	static instr f[11];

	f[0] = do_swap_a;
	f[1] = do_swap_b;
	f[2] = do_swap_both;
	f[3] = do_push_a;
	f[4] = do_push_b;
	f[5] = do_rotate_a;
	f[6] = do_rotate_b;
	f[7] = do_rotate_both;
	f[8] = do_reverse_rotate_a;
	f[9] = do_reverse_rotate_b;
	f[10] = do_reverse_rotate_both;
	return (f);
}

static void		error_exit(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

int				validate_nums_in_arg(t_ps *stack, int n, char **arg)
{
	intmax_t	t;

	stack->size = n;
	stack->a = (int*)malloc(sizeof(int) * (stack->size));
	stack->top[0] = 0;
	t = 0;
	while (n > 0)
	{
		if (!ps_atoimax(arg[n], &t) || t > INT_MAX || t < INT_MIN ||
				!validate_duplicates(stack->a, (int)t, stack->top[0]))
		{
			free(stack->a);
			error_exit();
		}
		stack->a[stack->top[0]] = (int)t;
		n--;
		stack->top[0]++;
	}
	stack->b = (int*)malloc(sizeof(int) * (stack->size));
	stack->top[1] = -1;
	return (1);
}

int				main(int argc, char **argv)
{
	t_ps		stack;
	char		*line;
	const instr *f = get_instruction();
	int			i;

	argc == 1 ? exit(0) : argv++;
	if (validate_nums_in_arg(&stack, argc - 1, argv))
	{
		while (ft_getline(0, &line) > 0)
		{
			i = validate_instruction(line);
			i < 0 ? error_exit() : f[i](&stack);
		}
		validate_order(&stack) ? write(2, "OK\n", 3) : write(2, "KO\n", 3);
		free(stack.a);
		free(stack.b);
		free(line);
	}
	return (0);
}
