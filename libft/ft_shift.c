/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shift.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburdeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 18:37:04 by aburdeni          #+#    #+#             */
/*   Updated: 2018/07/31 20:21:36 by aburdeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_shift(char c, int n)
{
	if (c >= 'A' && c <= 'Z')
		c = (char)((c + n <= 'Z') ? c + n : ((c - 'A' + n) % 26 + 'A'));
	else if (c >= 'a' && c <= 'z')
		c = (char)((c + n <= 'z') ? c + n : ((c - 'a' + n) % 26 + 'a'));
	return (c);
}
