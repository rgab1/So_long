#include <so_long.h>

void	check_collect(t_game *game, char c)
{
	if (c == 'C')
		game->p_collect += 1;
}

void	check_exit(t_game *game, char c)
{
	if (c == 'E')
	{
		if (game->p_collect == game->collect)
		{
			game->moves += 1;
			ft_printf("You managed to exit in %d moves!!!\n", game->moves);
			close_window_and_exit(game);
		}
	}
}
