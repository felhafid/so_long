/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felhafid <felhafid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 21:07:14 by felhafid          #+#    #+#             */
/*   Updated: 2024/05/26 17:18:08 by felhafid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	walls(char i)
{
	if (i == '1')
		return (1);
	else
		return (0);
}

void	zero_coins(t_so_long *p, int i, int j)
{
	int	z;

	z = 0;
	if (p->map[i][j] == 'C')
	{
		p->count_coins++;
		p->map[i][j] = '0';
	}
	if (p->count_coins == p->count)
	{
		if (z == 0)
			mlx_image_to_window(p->mlx, p->cave, p->x_exit * 70,
				p->y_exit * 70);
		z++;
		if (p->map[i][j] == 'E')
		{
			mlx_image_to_window(p->mlx, p->img, p->xplayer, p->yplayer);
			mlx_image_to_window(p->mlx, p->player, p->xplayer, p->yplayer);
			frees(p->map);
			write(1, "game over\n", 10);
			exit(0);
		}
	}
	else
		return ;
}

void	fill(t_so_long *p, int i, char *str)
{
	static int	move;
	void		*texture;

	ft_putnbr(++move);
	write(1, "\n", 1);
	mlx_delete_image(p->mlx, p->player);
	texture = mlx_load_png(str);
	p->player = mlx_texture_to_image(p->mlx, texture);
	mlx_delete_texture(texture);
	if (i == 2)
		p->xplayer += 70;
	else if (i == -2)
		p->xplayer -= 70;
	else if (i == -1)
		p->yplayer += 70;
	else if (i == 1)
		p->yplayer -= 70;
	if (p->map[p->yplayer / 70][p->xplayer / 70] == 'C')
		mlx_image_to_window(p->mlx, p->img, p->xplayer, p->yplayer);
	zero_coins(p, p->yplayer / 70, p->xplayer / 70);
	mlx_image_to_window(p->mlx, p->player, p->xplayer, p->yplayer);
}

void	keypress(mlx_key_data_t keydata, void *param)
{
	t_so_long	*p;

	p = (t_so_long *)param;
	if (keydata.key == 'D' && keydata.action
		&& walls(p->map[p->yplayer / 70][p->xplayer / 70 + 1]) == 0)
		fill(p, 2, "imgs/player.png");
	else if (keydata.key == 'A' && keydata.action 
		&& walls(p->map[p->yplayer / 70][p->xplayer / 70 - 1]) == 0)
		fill(p, -2, "imgs/player1.png");
	else if (keydata.key == 'S' && keydata.action 
		&& walls(p->map[p->yplayer / 70 + 1][p->xplayer / 70]) == 0)
		fill(p, -1, "imgs/player.png");
	else if (keydata.key == 'W' && keydata.action 
		&& walls(p->map[p->yplayer / 70 - 1][p->xplayer / 70]) == 0)
		fill(p, 1, "imgs/player.png");
	else if (keydata.key == MLX_KEY_ESCAPE)
	{
		frees(p->map);
		exit(0);
	}
}
