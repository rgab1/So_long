#include <so_long.h>

void	free_map(t_map *map)
{
	free_strings(map->map_2d);
	free(map);
}
