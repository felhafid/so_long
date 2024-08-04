/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felhafid <felhafid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 11:31:24 by felhafid          #+#    #+#             */
/*   Updated: 2024/05/26 17:29:32 by felhafid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create(t_so_long *p)
{
	void	*background;
	void	*bx;
	void	*cv;
	void	*ply;
	void	*cns;

	background = mlx_load_png("imgs/background.png");
	p->img = mlx_texture_to_image(p->mlx, background);
	mlx_delete_texture(background);
	bx = mlx_load_png("imgs/boxes.png");
	p->boxes = mlx_texture_to_image(p->mlx, bx);
	mlx_delete_texture(bx);
	ply = mlx_load_png("imgs/player.png");
	p->player = mlx_texture_to_image(p->mlx, ply);
	mlx_delete_texture(ply);
	cv = mlx_load_png("imgs/cave.png");
	p->cave = mlx_texture_to_image(p->mlx, cv);
	mlx_delete_texture(cv);
	cns = mlx_load_png("imgs/coins.png");
	p->coins = mlx_texture_to_image(p->mlx, cns);
	mlx_delete_texture(cns);
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
			else if (p->map[i][j] == 'C')
				mlx_image_to_window(p->mlx, p->coins, j * 70, i * 70);
			j++;
		}
		i++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb_move)
{
	if (nb_move < 10)
		ft_putchar(nb_move + 48);
	else
	{
		ft_putnbr(nb_move / 10);
		ft_putnbr(nb_move % 10);
	}
}
