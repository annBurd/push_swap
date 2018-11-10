/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 19:04:34 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/10 21:45:06 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	print_stack(t_ps *stack)
{
	int	i;

	i = -1;
	printf("A: ");
	while (++i <= TA)
		printf("%d\t", stack->a[i]);
	printf("\nB: ");
	i = -1;
	while (++i <= TB)
		printf("%d\t", stack->b[i]);
	printf("\n");
}

static void		error_exit(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

// static void (*[11])(t_ps *)			*get_command()
// {
// 	static void	(*f[11])(t_ps*);

// 	f[0] = do_swap_a;
// 	f[1] = do_swap_b;
// 	f[2] = do_swap_both;
// 	f[3] = do_push_a;
// 	f[4] = do_push_b;
// 	f[5] = do_rotate_a;
// 	f[6] = do_rotate_b;
// 	f[7] = do_rotate_both;
// 	f[8] = do_reverse_rotate_a;
// 	f[9] = do_reverse_rotate_b;
// 	// f[10] = do_reverse_rotate_both;
// 	return (f);
// }

int				main(int argc, char **argv)
{
	t_ps			stack;
	char			*line;
	

	argc == 1 ? exit(0) : argv++;
	stack.size = argc - 1;
	if (validate_arg(&stack, argv))
	{
		print_stack(&stack);
		while (ft_getline(0, &line) > 0)
		{
			if (!validate_command(line, &stack))
				error_exit();
		}
		validate_order(stack.a, stack.top[0]) ? write(2, "OK\n", 3) : write(2, "KO\n", 3);
		free(stack.a);
		free(stack.b);
		free(line);
	}
	else
		error_exit();
	return (0);
}
