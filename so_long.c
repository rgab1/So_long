/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabinrivault <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 22:38:30 by gabinrivault      #+#    #+#             */
/*   Updated: 2026/04/25 19:31:10 by gabinrivault     ###   ########.fr       */
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

static void	load_single_asset(t_game *game, t_mlx *asset, char *path)
{
	int	w;
	int	h;

	asset->img = mlx_xpm_file_to_image(game->mlx, path, &w, &h);
	if (!asset->img)
		return (free_game(game), exit_error(ERROR_14, 14));
	asset->addr = mlx_get_data_addr(asset->img, &asset->bits_per_pixel,
			&asset->line_length, &asset->endian);
}

static void	init_textures(t_game *game)
{
	game->assets = (t_assets *)ft_calloc(1, sizeof(t_assets));
	if (!game->assets)
		exit_error(ERROR_6, 6);
	load_single_asset(game, &game->assets->wall, "Sprites/Bush_small.xpm");
	load_single_asset(game, &game->assets->player, "Sprites/Character.xpm");
	load_single_asset(game, &game->assets->collect, "Sprites/Chess.xpm");
	load_single_asset(game, &game->assets->exit, "Sprites/Wooden_sign.xpm");
	load_single_asset(game, &game->assets->floor, "Sprites/Green.xpm");
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
	mlx_hook(game->win, EVENT_KEYPRESS, K_MASK,
		(int (*)(void))(void *)key_handler, game);
	mlx_hook(game->win, EVENT_DESTROY, 0,
		(int (*)(void))(void *)close_window_and_exit, game);
	mlx_loop(game->mlx);
	return (0);
}
