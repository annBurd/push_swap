/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_values.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 15:10:13 by aburdeni          #+#    #+#             */
/*   Updated: 2018/11/14 15:10:13 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ps_find_min(int *tab, int size)
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

int	ps_find_max(int *tab, int size)
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
