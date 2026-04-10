#ifndef PARSING_HELPER_H
# define PARSING_HELPER_H
# include <so_long.h>

void	free_map(t_game *map);
t_game	*map_copy(t_game *map);
void	find_player_start(t_game *map);
void	flood_fill(t_game *map, int x, int y);

#endif
