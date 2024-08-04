/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_string_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felhafid <felhafid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:39:48 by felhafid          #+#    #+#             */
/*   Updated: 2024/05/26 12:42:42 by felhafid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	len_nb(int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nb)
{
	int		i;
	int		a;
	int		j;
	char	*s;

	j = nb;
	s = malloc(len_nb(j) + 1);
	if (!s)
		return (NULL);
	s[len_nb(j)] = '\0';
	i = len_nb(j);
	while (i > 0)
	{
		a = nb;
		nb = nb / 10;
		a = a % 10;
		s[i - 1] = a + 48;
		i--;
	}
	return (s);
}
