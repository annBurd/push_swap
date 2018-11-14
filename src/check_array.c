/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 15:10:13 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/14 15:59:15 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	check_min(int *tab, int size)
{
	int i;
	int value;

	i = 0;
	value = 0;
	while(i < size)
	{
		if (tab[i] > tab[i + 1])
			value = i + 1;
		i++;
	}
	return (value);
}

int	check_max(int *tab, int size)
{
	int i;
	int value;

	i = 0;
	value = 0;
	while(i < size)
	{
		if (tab[i] < tab[i + 1])
			value = i + 1;
		i++;
	}
	return (value);
}

int	check_duplicates(int *tab, int nbr, int size)
{
	int i;

	i = -1;
	while (++i < size)
		if (tab[i] == nbr)
			return (0);
	return (1);
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

int	check_reverse_order(int *tab, int i, int end) //for stack B ??
{
	while (i < end)
	{
		if (tab[i] > tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}
