#include <keys.h>
#include <mlx.h>
#include <so_long.h>
#include <parsing_helper.h>

void	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	ft_putnbr_fd(game->moves, 1);
	ft_putstr_fd(" moves\n", 1);
	free_game(game);
	exit(0);
}

int	key_handler(int keycode, t_game *game)
{
	if (keycode == K_ESC)
		close_window(game);
	else if (keycode == K_W || keycode == K_UP)
		move_up(game);
	else if (keycode == K_A || keycode == K_LEFT)
		move_left(game);
	else if (keycode == K_S || keycode == K_DOWN)
		move_down(game);
	else if (keycode == K_D || keycode == K_RIGHT)
		move_right(game);
	else
		return (puterror("Key not supported\n"), 0);
	return (0);
}
