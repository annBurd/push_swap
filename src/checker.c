/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 19:04:34 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/07 20:55:11 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static command			*get_command(void)
{
	static command	f[11];

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

static inline void		error_exit(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

int						main(int argc, char **argv)
{
	t_ps			stack;
	char			*line;
	const command	*f = get_command();
	int				i;

	argc == 1 ? exit(0) : argv++;
	if (validate_arg(&stack, argc - 1, argv))
	{
		while (ft_getline(0, &line) > 0)
		{
			i = validate_command(line);
			i < 0 ? error_exit() : f[i](&stack);
		}
		validate_order(&stack) ? write(2, "OK\n", 3) : write(2, "KO\n", 3);
		free(stack.a);
		free(stack.b);
		free(line);
	}
	else
		error_exit();
	return (0);
}
