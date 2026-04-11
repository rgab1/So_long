#include <so_long.h>
#include <mlx.h>
#include <errors.h>
#include <keys.h>
#include <parsing_helper.h>

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


int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
		exit_error(ERROR_10, 10);
	game = 	parsing(av);
	game->mlx = mlx_init();
	game->moves = 0;
	init_graphics(game);
	print_map(game);
	mlx_hook(game->win, EVENT_KEYPRESS, K_MASK, key_handler, game);
	mlx_loop(game->mlx);
	return (0);
}
