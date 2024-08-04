/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key1_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felhafid <felhafid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 21:07:14 by felhafid          #+#    #+#             */
/*   Updated: 2024/05/27 11:18:37 by felhafid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	walls(char i)
{
	if (i == '1')
		return (1);
	else
		return (0);
}

void	zero_coins(t_so_long *p, int i, int j, int z)
{
	if (p->map[i][j] == 'C')
	{
		p->coins++;
		p->map[i][j] = '0';
	}
	if (p->map[i][j] == 'B')
	{
		frees(p->map);
		free_tex(p);
		exit(write(1, "You lose\n", 9));
	}
	if (p->coins == p->count)
	{
		if (z++ == 0)
			mlx_image_to_window(p->mlx, p->cave, p->x_exit * 70,
				p->y_exit * 70);
		if (p->map[i][j] == 'E')
		{
			frees(p->map);
			free_tex(p);
			write(1, "game over\n", 10);
			exit(0);
		}
	}
	return ;
}

void	fill(t_so_long *p, int i, char *str)
{
	static int	move;
	char		*s;
	void		*texture;

	s = ft_itoa(move);
	mlx_image_to_window(p->mlx, p->boxes, 0, 0);
	mlx_put_string(p->mlx, s, 27, 27);
	free(s);
	move++;
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
	if (p->map[p->yplayer / 70][p->xplayer / 70])
		mlx_image_to_window(p->mlx, p->img, p->xplayer, p->yplayer);
	zero_coins(p, p->yplayer / 70, p->xplayer / 70, 0);
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
		free_tex(p);
		exit(0);
	}
}
