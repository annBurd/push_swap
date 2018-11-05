/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 20:47:23 by aburdeni          #+#    #+#             */
/*   Updated: 2018/07/17 20:47:34 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_max(int *tab, size_t len)
{
	int i;

	if (len == 0)
		return (0);
	i = *tab;
	if (len == 1)
		return (i);
	while (len > 1)
	{
		tab++;
		if (i < *tab)
			i = *tab;
		len--;
	}
	return (i);
}
