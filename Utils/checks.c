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
			close_window(game);
			exit(0);
		}
	}
}
