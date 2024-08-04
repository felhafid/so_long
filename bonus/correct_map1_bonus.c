/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_map1_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felhafid <felhafid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:02:39 by felhafid          #+#    #+#             */
/*   Updated: 2024/05/27 11:22:32 by felhafid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_x_y(t_so_long *p)
{
	int	a;

	p->y = 0;
	while (p->map[p->y])
	{
		p->x = 0;
		while (p->map[p->y][p->x])
			p->x++;
		p->y++;
	}
	a = 0;
	while (a < p->x)
	{
		if (p->map[0][a] != '1' || p->map[p->y - 1][a] != '1')
			return (write(2, "Error\ncheck your walls\n", 23), 0);
		a++;
	}
	a = 0;
	while (a < p->y)
	{
		if (p->map[a][0] != '1' || p->map[a][p->x - 1] != '1')
			return (write(2, "Error\ncheck your walls\n", 23), 0);
		a++;
	}
	return (1);
}

int	check_enemies(t_so_long *p)
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
			if (p->map[i][j] == 'B')
				a++;
			j++;
		}
		i++;
	}
	if (a >= 1)
		return (1);
	else
		return (write(2, "Error\ncheck your enemies\n", 25), 0);
}

void	flood_fill(char **s, int y, int x)
{
	if (s[y][x] == 'B')
	{
		s[y][x] = '1';
		return ;
	}
	s[y][x] = '1';
	if (s[y - 1][x] != '1')
		flood_fill(s, y - 1, x);
	if (s[y][x + 1] != '1')
		flood_fill(s, y, x + 1);
	if (s[y + 1][x] != '1')
		flood_fill(s, y + 1, x);
	if (s[y][x - 1] != '1')
		flood_fill(s, y, x - 1);
}

int	check_if_valid(t_so_long *p, int y, int x)
{
	int		i;
	int		j;

	i = 0;
	flood_fill(p->copy_map, y, x);
	while (p->copy_map[i])
	{
		j = 0;
		while (p->copy_map[i][j])
		{
			if (p->copy_map[i][j] == 'C' || p->copy_map[i][j] == 'E')
			{
				write(2, "Error\nInvalid map\n", 18);
				frees(p->copy_map);
				return (0);
			}
			j++;
		}
		i++;
	}
	frees(p->copy_map);
	return (1);
}

int	check_textures(t_so_long *p, int i)
{
	p->texturei = malloc(12 * sizeof(void *));
	p->texturei[0] = mlx_load_png("imgs/coin/coin1.png");
	p->texturei[1] = mlx_load_png("imgs/coin/coin2.png");
	p->texturei[2] = mlx_load_png("imgs/coin/coin3.png");
	p->texturei[3] = mlx_load_png("imgs/coin/coin4.png");
	p->texturei[4] = mlx_load_png("imgs/coin/coin5.png");
	p->texturei[5] = mlx_load_png("imgs/background.png");
	p->texturei[6] = mlx_load_png("imgs/bee.png");
	p->texturei[7] = mlx_load_png("imgs/boxes.png");
	p->texturei[8] = mlx_load_png("imgs/cave.png");
	p->texturei[9] = mlx_load_png("imgs/player.png");
	p->texturei[10] = mlx_load_png("imgs/player1.png");
	p->texturei[11] = NULL;
	while (i < 11)
	{
		if (p->texturei[i] == NULL)
		{
			write(2, "Error\ncheck your imgs\n", 22);
			return (free_tt(p->texturei), 0);
		}
		i++;
	}
	return (1);
}
