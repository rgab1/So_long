#include <so_long.h>
#include <mlx.h>
#define WALL 0x00FF0000
#define PATH 0x000000FF
#define PLAYER_START 0x0000FF00
#define COLLECTIBLE 0x00FF00FF
#define EXIT 0x00FFFF00

static void	choose_print(t_game *game, int x, int y)
{
	int	px;
	int	py;

	px = x * SQUARE_LENGTH;
	py = y * SQUARE_LENGTH;
	if (game->map[y][x] == '1')
		print_square(&game->img, px, py, WALL);
	else if (game->map[y][x] == '0')
		print_square(&game->img, px, py, PATH);
	else if (game->map[y][x] == 'C')
		print_square(&game->img, px, py, COLLECTIBLE);
	else if (game->map[y][x] == 'P')
		print_square(&game->img, px, py, PLAYER_START);
	else if ( game->map[y][x] == 'Z')
		print_square(&game->img, px, py, PLAYER_START);
	else
		print_square(&game->img, px, py, EXIT);
}

void	print_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			choose_print(game, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	ft_printf("%d moves\n", game->moves);
}
