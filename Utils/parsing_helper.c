#include <so_long.h>
#include <parsing_helper.h>

t_map	*map_copy(t_map *map)
{
	t_map	*cpy;
	int		i;

	cpy = (t_map *)malloc(sizeof(t_map));
	if (!cpy)
		puterror("Malloc failed\n", 6);
	i = 0;
	while (map->map_2d[i])
		i++;
	cpy->map_2d = (char **)malloc(sizeof(char *) * (i + 1));
	if (!cpy->map_2d)
		puterror("Malloc failed\n", 6);
	i = 0;
	while (map->map_2d[i])
	{
		cpy->map_2d[i] = ft_strdup(map->map_2d[i]);
		if (!cpy->map_2d[i])
			return (free_map(cpy), puterror("Malloc failed\n", 6));
		i++;
	}
	cpy->map_2d[i] = NULL;
	cpy->exit = 0;
	cpy->collect = 0;
	return (cpy);
}

void	find_player_start(char **map, int *x, int *y)
{
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				return (void);
			x++;
		}
		y++;
	}
	puterror("DEBUG no P found\n", 11);
}

void	flood_fill(t_map *cpy, int x, int y)
{
	if (cpy->map_2d[y][x] == '1' || cpy->map_2d[y][x] == 'V')
		return ;
	if (cpy->map_2d[y][x] == 'C')
		cpy->collect++;
	else if (cpy->map_2d[y][x] == 'E')
		cpy->exit++;
	cpy->map_2d[y][x] = 'V';
	flood_fill(cpy, x + 1, y);
	flood_fill(cpy, x - 1, y);
	flood_fill(cpy, x, y + 1);
	flood_fill(cpy, x, y - 1);
}
