#ifndef PARSING_HELPER_H
# define PARSING_HELPER_H

typedef struct	s_map
{
	int		collect;
	int		exit;
	int		player_start;
	char	**map_2d;
}				t_map;

t_map	*map_copy(t_map *map);
void	find_player_start(char **map, int *x, int *y);
void	flood_fill(t_map *map, int x, int y);

#endif
