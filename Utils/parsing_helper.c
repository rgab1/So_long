#include <so_long.h>
#include <parsing_helper.h>
#include <errors.h>

void	free_map(t_map *map)
{
	free_strings(map->map_2d);
	free(map);
}

t_map	*map_copy(t_map *map)
{
	t_map	*cpy;
	int		i;

	cpy = (t_map *)malloc(sizeof(t_map));
	if (!cpy)
		return (free_map(map), puterror(ERROR_6, 6), NULL);
	i = 0;
	while (map->map_2d[i])
		i++;
	cpy->map_2d = (char **)malloc(sizeof(char *) * (i + 1));
	if (!cpy->map_2d)
		return (free_map(cpy), free_map(map), puterror(ERROR_6, 6), NULL);
	i = 0;
	while (map->map_2d[i])
	{
		cpy->map_2d[i] = ft_strdup(map->map_2d[i]);
		if (!cpy->map_2d[i])
			return (free_map(cpy), free_map(map), puterror(ERROR_6, 6), NULL);
		i++;
	}
	cpy->map_2d[i] = NULL;
	cpy->exit = 0;
	cpy->collect = 0;
	return (cpy);
}

void	find_player_start(t_map *map, int *x, int *y)
{
	while (map->map_2d[*y])
	{
		*x = 0;
		while (map->map_2d[*y][*x])
		{
			if (map->map_2d[*y][*x] == 'P')
				return ;
			*x += 1;
		}
		*y += 1;
	}
	return (free_map(map), puterror(ERROR_11, 11));
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
