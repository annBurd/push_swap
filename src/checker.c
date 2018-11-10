/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 19:04:34 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/10 23:26:01 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	print_stack(t_ps *stack)
{
	int	i;

	i = TA;
	printf("A:");
	while (i >= 0)
		printf(" %d", stack->a[i--]);
	printf("\nB:");
	i = TB;
	while (i >= 0)
		printf(" %d", stack->b[i--]);
	printf("\n");
}

int		ps_exit(short code, t_ps *stack)
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

int		main(int argc, char **argv)
{
	t_ps				stack;
	static const cmd	f[11] =
	{
		do_swap_a,
		do_swap_b,
		do_swap_both,
		do_push_a,
		do_push_b,
		do_rotate_a,
		do_rotate_b,
		do_rotate_both,
		do_reverse_rotate_a,
		do_reverse_rotate_b,
		do_reverse_rotate_both,
	};

	argc == 1 ? ps_exit(0, NULL) : validate_arg(&stack, argv + 1, argc - 1);
	while (ft_getline(0, &stack.line) > 0)
		(void)f[validate_command(stack.line, &stack)];
	validate_order(stack.a, stack.top[0])
		? write(2, "OK\n", 3) : write(2, "KO\n", 3);
	return (ps_exit(1, &stack));
}
