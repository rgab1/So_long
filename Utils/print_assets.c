#include <so_long.h>

void	print_floor(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->assets->floor, 
		x, y);
}

void	print_wall(t_game *game, int x, int y)
{
	print_floor(game, x, y);
	mlx_put_image_to_window(game->mlx, game->win, game->assets->wall, 
		x, y);
}

void	print_player(t_game *game, int x, int y)
{
	print_floor(game, x, y);
	mlx_put_image_to_window(game->mlx, game->win, game->assets->player, 
		x, y);
}

void	print_collectible(t_game *game, int x, int y)
{
	print_floor(game, x, y);
	mlx_put_image_to_window(game->mlx, game->win, game->assets->collect, 
		x, y);
}

void	print_exit(t_game *game, int x, int y)
{
	print_floor(game, x, y);
	mlx_put_image_to_window(game->mlx, game->win, game->assets->exit, 
		x, y);
}

void	print_player_exit(t_game *game, int x, int y)
{
	print_exit(game, x, y);
	print_player(game, x, y);
}
