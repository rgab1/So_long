/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabinrivault <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 22:52:30 by gabinrivault      #+#    #+#             */
/*   Updated: 2026/04/16 22:34:55 by gabinrivault     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <keys.h>
# include <stddef.h>
# include <libft.h>
# include <fcntl.h>
# include <mlx.h>
# define SQUARE_LENGTH 16

typedef struct s_mlx
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_mlx;

typedef struct s_assets
{
	t_mlx	wall;
	t_mlx	player;
	t_mlx	collect;
	t_mlx	exit;
	t_mlx	floor;
}				t_assets;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_mlx		img;
	char		**map;
	int			moves;
	int			p_x;
	int			p_y;
	int			collect;
	int			p_collect;
	int			exit;
	int			player_start;
	t_assets	*assets;
}				t_game;

int		close_window_and_exit(t_game *game);
void	check_collect(t_game *game, char c);
void	check_exit(t_game *game, char c);
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_right(t_game *game);
void	move_left(t_game *game);
t_game	*parsing(char **av);
void	print_square(t_mlx *img, int offset_i, int offset_y, int color);
void	print_map(t_game *game);
void	print_floor(t_game *game, int x, int y);
void	print_wall(t_game *game, int x, int y);
void	print_player(t_game *game, int x, int y);
void	print_collectible(t_game *game, int x, int y);
void	print_exit(t_game *game, int x, int y);
void	print_player_exit(t_game *game, int x, int y);
void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color);
int		key_handler(int keycode, t_game *game);

#endif
