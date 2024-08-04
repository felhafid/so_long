/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_key_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felhafid <felhafid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:16:46 by felhafid          #+#    #+#             */
/*   Updated: 2024/05/27 12:49:22 by felhafid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	create_texture(t_so_long *p)
{
	p->texture[0] = mlx_load_png("imgs/coin/coin1.png");
	p->coins_sprit[0] = mlx_texture_to_image(p->mlx, p->texture[0]);
	p->texture[1] = mlx_load_png("imgs/coin/coin2.png");
	p->coins_sprit[1] = mlx_texture_to_image(p->mlx, p->texture[1]);
	p->texture[2] = mlx_load_png("imgs/coin/coin3.png");
	p->coins_sprit[2] = mlx_texture_to_image(p->mlx, p->texture[2]);
	p->texture[3] = mlx_load_png("imgs/coin/coin4.png");
	p->coins_sprit[3] = mlx_texture_to_image(p->mlx, p->texture[3]);
	p->texture[4] = mlx_load_png("imgs/coin/coin5.png");
	p->coins_sprit[4] = mlx_texture_to_image(p->mlx, p->texture[4]);
	p->i = 0;
	p->time = 0;
}

void	free_tex(t_so_long *p)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		mlx_delete_texture(p->texture[i]);
		i++;
	}
	return ;
}

void	sprite(t_so_long *p, int j, int i, int z)
{
	mlx_image_to_window(p->mlx, p->coins_sprit[z], j * 70, i * 70);
	if (z == 0)
	{
		mlx_delete_image(p->mlx, p->coins_sprit[4]);
		p->coins_sprit[4] = mlx_texture_to_image(p->mlx, p->texture[4]);
	}
	else
	{
		mlx_delete_image(p->mlx, p->coins_sprit[z - 1]);
		p->coins_sprit[z - 1] = mlx_texture_to_image(p->mlx, p->texture[z - 1]);
	}
}

void	check_c(t_so_long *p, int z)
{
	int		i;
	int		j;

	i = 0;
	while (p->map[i])
	{
		j = 0;
		while (p->map[i][j])
		{
			if (p->map[i][j] == 'C')
				sprite(p, j, i, z);
			j++;
		}
		i++;
	}
}

void	coins_loop(void *s)
{
	t_so_long	*p;

	p = (t_so_long *)s;
	if (p->time == 7)
	{
		p->time = 0;
		if (p->i > 4)
			p->i = 0;
		check_c(p, p->i);
		p->i++;
	}
	p->time++;
}
