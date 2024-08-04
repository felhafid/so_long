/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felhafid <felhafid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 11:31:24 by felhafid          #+#    #+#             */
/*   Updated: 2024/05/27 12:49:05 by felhafid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	create(t_so_long *p)
{
	void		*background;
	void		*bx;
	void		*ply;
	void		*enm;
	void		*hn;

	background = mlx_load_png("imgs/background.png");
	p->img = mlx_texture_to_image(p->mlx, background);
	mlx_delete_texture(background);
	bx = mlx_load_png("imgs/boxes.png");
	p->boxes = mlx_texture_to_image(p->mlx, bx);
	mlx_delete_texture(bx);
	ply = mlx_load_png("imgs/player.png");
	p->player = mlx_texture_to_image(p->mlx, ply);
	mlx_delete_texture(ply);
	p->cv = mlx_load_png("imgs/cave.png");
	p->cave = mlx_texture_to_image(p->mlx, p->cv);
	mlx_delete_texture(p->cv);
	enm = mlx_load_png("imgs/bee.png");
	p->enemie = mlx_texture_to_image(p->mlx, enm);
	mlx_delete_texture(enm);
	hn = mlx_load_png("imgs/coin/coin1.png");
	p->honey = mlx_texture_to_image(p->mlx, hn);
	mlx_delete_texture(hn);
}

void	start_player(t_so_long	*p)
{
	int			i;
	int			j;

	i = 0;
	while (p->map[i])
	{
		j = 0;
		while (p->map[i][j])
		{
			if (p->map[i][j] == 'P')
			{
				p->yplayer = i;
				p->xplayer = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	build_map(t_so_long *p)
{
	int		i;
	int		j;

	create(p);
	i = 0;
	p->coins = 0;
	while (i < p->y)
	{
		j = 0;
		while (j < p->x)
		{
			mlx_image_to_window(p->mlx, p->img, j * 70, i * 70);
			if (p->map[i][j] == '1')
				mlx_image_to_window(p->mlx, p->boxes, j * 70, i * 70);
			else if (p->map[i][j] == 'P')
				mlx_image_to_window(p->mlx, p->player, j * 70, i * 70);
			else if (p->map[i][j] == 'B')
				mlx_image_to_window(p->mlx, p->enemie, j * 70, i * 70);
			else if (p->map[i][j] == 'C')
				mlx_image_to_window(p->mlx, p->honey, j * 70, i * 70);
			j++;
		}
		i++;
	}
}
