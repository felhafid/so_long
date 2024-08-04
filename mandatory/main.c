/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felhafid <felhafid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 19:43:26 by felhafid          #+#    #+#             */
/*   Updated: 2024/05/27 12:23:35 by felhafid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		p.mlx = mlx_init(p.x * 70, p.y * 70, "so_long", 1);
		build_map(&p);
		p.xplayer *= 70;
		p.yplayer *= 70;
		mlx_key_hook(p.mlx, keypress, &p);
		mlx_loop(p.mlx);
		frees(p.map);
		mlx_terminate(p.mlx);
	}
	else
		write(2, "Error\ncheck arguments\n", 22);
}
