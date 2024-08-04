/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felhafid <felhafid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 17:40:36 by felhafid          #+#    #+#             */
/*   Updated: 2024/08/01 12:32:11 by felhafid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 13
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../MLX42/include/MLX42/MLX42.h"

typedef struct so_long{
	char		**map;
	char		**copy_map;
	int			xplayer;
	int			yplayer;
	int			x_exit;
	int			y_exit;
	int			coins;
	int			x;
	int			y;
	mlx_t		*mlx;
	mlx_image_t	*img;
	mlx_image_t	*boxes;
	mlx_image_t	*player;
	mlx_image_t	*enemie;
	mlx_image_t	*honey;
	void		*texture[5];
	mlx_image_t	*coins_sprit[5];
	int			count;
	mlx_image_t	*cave;
	void		*cv;
	int			i;
	int			time;
	void		**texturei;

}t_so_long;

int		map_name(char *s);
int		ft_strlen(char *s);
char	**ft_split(char *s);
char	**fill_map(int fd, t_so_long *p);
void	start_player(t_so_long *p);
int		check_x_y(t_so_long *p);
int		check_enemies(t_so_long *p);
int		check_if_valid(t_so_long *p, int x, int y);
void	frees(char **s);
int		check_textures(t_so_long *p, int i);
void	free_tt(void **texturei);
int		correct_map(t_so_long *p);
void	build_map(t_so_long *p);
void	create_texture(t_so_long *p);
void	keypress(mlx_key_data_t keydata, void *param);
void	coins_loop(void *p);
void	free_tex(t_so_long *p);
char	*ft_itoa(int nb);
char	*ft_afterline(char *s);
char	*ft_strjoin(char *s, char *s1);
char	*get_next_line(int fd);

#endif