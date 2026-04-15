/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabinrivault <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 22:38:30 by gabinrivault      #+#    #+#             */
/*   Updated: 2026/04/15 23:02:34 by gabinrivault     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <mlx.h>
#include <errors.h>
#include <keys.h>

static void	init_graphics(t_game *game)
{
	int	win_width;
	int	win_height;

	win_height = (ft_tablen((void **)game->map) * SQUARE_LENGTH);
	win_width = (ft_strlen(game->map[0]) * SQUARE_LENGTH);
	game->win = mlx_new_window(game->mlx, win_width, win_height, "So_long");
	game->img.img = mlx_new_image(game->mlx, win_width, win_height);
	game->img.addr = mlx_get_data_addr(game->img.img,
			&game->img.bits_per_pixel, &game->img.line_length,
			&game->img.endian);
}

void init_textures(t_game *game)
{
    int w;
    int h;

	game->assets = (t_assets *)malloc(sizeof(t_assets));
    game->assets->wall = mlx_xpm_file_to_image(game->mlx,
			"Sprites/Bush_small.xpm", &w, &h);
    game->assets->player = mlx_xpm_file_to_image(game->mlx,
			"Sprites/Character_front.xpm", &w, &h);
    game->assets->collect = mlx_xpm_file_to_image(game->mlx,
			"Sprites/Chess.xpm", &w, &h);
    game->assets->exit = mlx_xpm_file_to_image(game->mlx,
			"Sprites/Wooden_sign.xpm", &w, &h);
    game->assets->floor = mlx_xpm_file_to_image(game->mlx,
			"Sprites/Green.xpm", &w, &h);
    if (!game->assets->wall || !game->assets->player || !game->assets->collect
			|| !game->assets->exit || !game->assets->floor)
        exit_error(ERROR_14, 14);
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
		exit_error(ERROR_10, 10);
	game = parsing(av);
	game->mlx = mlx_init();
	game->moves = 0;
	game->p_collect = 0;
	init_graphics(game);
	init_textures(game);
	print_map(game);
	mlx_hook(game->win, EVENT_KEYPRESS, K_MASK, key_handler, game);
	mlx_loop(game->mlx);
	return (0);
}
