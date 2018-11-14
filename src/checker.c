/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 19:04:34 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/14 17:42:45 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	define_cmd(char *s, t_ps *stack)
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

int define_flags(t_ps *stack, char ***argv, int *argc)
{
	int i;
	int fd;

	i = 1;
	fd = 0;
	stack->print = 0;
	stack->status = 0;
	while (argv[0][i][0] == '-')
	{
		if (argv[0][i][1] == 's')
			stack->status = 1;
		else if (argv[0][i][1] == 'f')
			fd = open(argv[++i], O_RDONLY);
		i++;
	}
	(*argv) += i;
	(*argc) -= i;
	return (fd);
}

int	main(int argc, char **argv)
{
	t_ps		stack;
	static cmd	f[11];
	int 		fd;

	argc == 1 ? ps_exit(0, NULL) : fd = define_flags(&stack, &argv, &argc);
	ps_init(&stack, argv, argc);
	f[0] = do_sa;
	f[1] = do_sb;
	f[2] = do_ss;
	f[3] = do_pa;
	f[4] = do_pb;
	f[5] = do_ra;
	f[6] = do_rb;
	f[7] = do_rr;
	f[8] = do_rra;
	f[9] = do_rrb;
	f[10] = do_rrr;
	while (ft_getline(fd, &stack.line) > 0)
	{
		f[define_cmd(stack.line, &stack)](&stack);
		print_stack(&stack);
	}
	check_order(stack.top[1] == -1 && stack.a, 0, stack.top[0])
		? write(2, "OK\n", 3) : write(2, "KO\n", 3);
	return (ps_exit(1, &stack));
}
