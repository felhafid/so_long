/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felhafid <felhafid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 19:51:02 by felhafid          #+#    #+#             */
/*   Updated: 2024/05/27 12:01:43 by felhafid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_player(t_so_long *p, int i, int j, int a)
{
	int	b;

	b = 0;
	while (p->map[i])
	{
		j = 0;
		while (p->map[i][j])
		{
			if (p->map[i][j] == 'P')
				a++;
			if (p->map[i][j] == 'E')
			{
				p->y_exit = i;
				p->x_exit = j;
				b++;
			}
			j++;
		}
		i++;
	}
	if (a == 1 && b == 1)
		return (1);
	else
		return (write(2, "Error\ncheck your player or your exit\n", 37), 0);
}

int	check_characters(t_so_long *p)
{
	int	i;
	int	j;
	int	a;

	i = 0;
	a = 0;
	while (p->map[i])
	{
		j = 0;
		while (p->map[i][j])
		{
			if (p->map[i][j] == 'C')
				a++;
			j++;
		}
		i++;
	}
	if (a >= 1)
	{
		p->count = a;
		return (1);
	}
	else
		return (write(2, "Error\ncheck your coins\n", 23), 0);
}

int	check_others(t_so_long *p)
{
	int	i;
	int	j;

	i = 0;
	while (p->map[i])
	{
		j = 0;
		while (p->map[i][j])
		{
			if (p->map[i][j] != 'P' && p->map[i][j] != 'E' 
				&& p->map[i][j] != 'C' && p->map[i][j] != '1'
					&& p->map[i][j] != '0')
				return (write(2, "Error\ninvalid character map\n", 28), 0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_len(t_so_long *p)
{
	int	i;
	int	len;

	if (p->map == NULL)
		return (0);
	len = ft_strlen(p->map[0]);
	i = 1;
	while (p->map[i])
	{
		if (len != ft_strlen(p->map[i]))
			return (write(2, "Error\ncheck len of map\n", 23), 0);
		i++;
	}
	return (1);
}

int	correct_map(t_so_long *p)
{
	start_player(p);
	if (check_player(p, 0, 0, 0) == 0 || check_others(p) == 0 || 
		check_characters(p) == 0 || check_len(p) == 0
		|| check_x_y(p) == 0 || check_if_valid(p, p->yplayer, p->xplayer) == 0
		|| check_textures(p) == 0)
	{
		frees(p->map);
		exit(1);
	}
	else if (p->x > 36 || p->y > 18)
	{
		frees(p->map);
		write(2, "Error\nyour map is way too big\n", 30);
		exit(1);
	}
	else
		return (1);
}
