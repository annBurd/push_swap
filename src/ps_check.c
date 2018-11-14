/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 15:10:13 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/14 21:43:54 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	check_min(int *tab, int size)
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

int	check_max(int *tab, int size)
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

int	check_order(int *tab, int i, int end)
{
	while (i < end)
	{
		if (tab[i] < tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	check_reverse_order(int *tab, int i, int end)
{
	while (i < end)
	{
		if (tab[i] > tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}
