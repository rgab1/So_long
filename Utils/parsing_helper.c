#include <so_long.h>
#include <parsing_helper.h>
#include <errors.h>

void	free_game(t_game *game)
{
	free_strings(game->map);
	free(game);
}

t_game	*map_copy(t_game *map)
{
	t_game	*cpy;
	int		i;

	cpy = (t_game *)malloc(sizeof(t_game));
	if (!cpy)
		return (free_game(map), exit_error(ERROR_6, 6), NULL);
	i = 0;
	while (map->map[i])
		i++;
	cpy->map = (char **)malloc(sizeof(char *) * (i + 1));
	if (!cpy->map)
		return (free_game(cpy), free_game(map), exit_error(ERROR_6, 6), NULL);
	i = 0;
	while (map->map[i])
	{
		cpy->map[i] = ft_strdup(map->map[i]);
		if (!cpy->map[i])
			return (free_game(cpy), free_game(map), exit_error(ERROR_6, 6), NULL);
		i++;
	}
	cpy->map[i] = NULL;
	cpy->exit = 0;
	cpy->collect = 0;
	return (cpy);
}

void	find_player_start(t_game *map)
{
	while (map->map[map->p_y])
	{
		map->p_x = 0;
		while (map->map[map->p_y][map->p_x])
		{
			if (map->map[map->p_y][map->p_x] == 'P')
			{
				ft_putnbr_fd(map->p_y, 1);
				ft_putstr_fd(" y ", 1);
				ft_putnbr_fd(map->p_x, 1);
				ft_putstr_fd(" x\n", 1);
				return ;
			}
			map->p_x += 1;
		}
		map->p_y += 1;
	}
	return (free_game(map), exit_error(ERROR_11, 11));
}

void	flood_fill(t_game *cpy, int x, int y)
{
	if (cpy->map[y][x] == '1' || cpy->map[y][x] == 'V')
		return ;
	if (cpy->map[y][x] == 'C')
		cpy->collect++;
	else if (cpy->map[y][x] == 'E')
		cpy->exit++;
	cpy->map[y][x] = 'V';
	flood_fill(cpy, x + 1, y);
	flood_fill(cpy, x - 1, y);
	flood_fill(cpy, x, y + 1);
	flood_fill(cpy, x, y - 1);
}
