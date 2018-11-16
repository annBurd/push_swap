/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 15:10:13 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/16 21:27:35 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ps_min_index(int *tab, const int size)
{
	int i;
	int value;
	int res;

	i = 0;
	value = tab[i];
	res = i;
	while (i < size)
	{
		if (value > tab[i + 1])
		{
			value = tab[i + 1];
			res = i + 1;
		}
		i++;
	}
	return (res);
}

int	ps_max_index(int *tab, const int size)
{
	int i;
	int value;
	int res;

	i = 0;
	value = tab[i];
	res = i;
	while (i < size)
	{
		if (value < tab[i + 1])
		{
			value = tab[i + 1];
			res = i + 1;
		}
		i++;
	}
	return (res);
}
