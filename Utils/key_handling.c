#include <keys.h>
#include <mlx.h>
#include <so_long.h>

void	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	ft_putnbr_fd(game->moves, 1);
	ft_putstr_fd(" moves\n", 1);
	exit(0);
}

int	key_handler(int keycode, t_game *game)
{
	if (keycode == K_ESC)
		close_window(game);
	else if (keycode == K_W || keycode == K_UP)
	{
		ft_putstr_fd("Moving UP!\n", 1); // Replace with move_player logic later
		game->moves += 1;
	}
	else if (keycode == K_A || keycode == K_LEFT)
	{
		ft_putstr_fd("Moving LEFT!\n", 1);
		game->moves += 1;
	}
	else if (keycode == K_S || keycode == K_DOWN)
	{
		ft_putstr_fd("Moving DOWN!\n", 1);
		game->moves += 1;
	}
	else if (keycode == K_D || keycode == K_RIGHT)
	{
		ft_putstr_fd("Moving RIGHT!\n", 1);
		game->moves += 1;
	}
	else
		return (puterror("Key not supported\n"), 0);
	print_map(game);
	return (0);
}
