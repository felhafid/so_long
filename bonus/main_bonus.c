/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felhafid <felhafid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 19:43:26 by felhafid          #+#    #+#             */
/*   Updated: 2024/05/27 12:56:39 by felhafid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int c, char **v)
{
	t_so_long	p;
	int			fd;

	if (c == 2)
	{
		fd = open(v[1], O_RDONLY);
		if (fd < 0 || map_name(v[1]) == 1)
			exit(write(2, "Error\nInvalid file or extention\n", 32));
		p.map = fill_map(fd, &p);
		correct_map(&p);
		p.mlx = mlx_init(p.x * 70, p.y * 70, "so_long_bonus", 1);
		build_map(&p);
		create_texture(&p);
		mlx_loop_hook(p.mlx, coins_loop, &p);
		p.xplayer *= 70;
		p.yplayer *= 70;
		mlx_key_hook(p.mlx, keypress, &p);
		mlx_loop(p.mlx);
		frees(p.map);
		free_tex(&p);
		free_tt(p.texturei);
		mlx_terminate(p.mlx);
	}
	else
		write(2, "Error\ncheck arguments\n", 22);
}
