#include <parsing_helper.h>
#include <so_long.h>
#include <errors.h>

static int	file_error(char *map_name)
{
	int	name_len;
	int	fd;

	name_len = ft_strlen(map_name);
	if (ft_strncmp(map_name + (name_len - 4), ".ber", 4))
		exit_error(ERROR_3, 3);
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		exit_error(ERROR_4, 4);
	return (fd);
}

static void	count_stuff(char *map_str, t_game *map)
{
	int	i;

	i = 0;
	map->collect = 0;
	map->exit = 0;
	map->player_start = 0;
	while (map_str[i])
	{
		if (map_str[i] == '\n')
			i++;
		else if (map_str[i] == 'C')
			map->collect += 1;
		else if (map_str[i] == 'E')
			map->exit += 1;
		else if (map_str[i] == 'P')
			map->player_start += 1;
		else if (map_str[i] != '0' && map_str[i] != '1')
			return (free_map(map), exit_error(ERROR_5, 5));
		i++;
	}
	map->map = ft_split(map_str, '\n');
	if (map->player_start != 1 || map->exit != 1)
		return (free_map(map), exit_error(ERROR_7, 7));
	if (map->collect < 1)
		return (free_map(map), exit_error(ERROR_13, 13));
}

static t_game	*read_map(char *map_name)
{
	t_game	*map;
	int		fd;
	char	*line;
	char	*temp;
	char	*map_str;

	map = (t_game *)ft_calloc(1, sizeof(t_game));
	if (!map)
		exit_error(ERROR_6, 6);
	fd = file_error(map_name);
	line = get_next_line(fd);
	map_str = ft_strdup("");
	while (line)
	{
		temp = map_str;
		map_str = ft_strjoin(map_str, line);
		free(temp);
		line = get_next_line(fd);
	}
	close(fd);
	count_stuff(map_str, map);
	return (free(map_str), map);
}

static void	map_walls_check(t_game *map)
{
	int		i;
	size_t	line_len;
	size_t	nbr_lines;

	i = 0;
	nbr_lines = ft_tablen((void **)map->map);
	line_len = ft_strlen(map->map[0]);
	while (map->map[0][i])
		if (map->map[0][i++] != '1')
			return (free_map(map), exit_error(ERROR_8, 8));
	i = 0;
	while (map->map[i])
	{
		if (ft_strlen(map->map[i]) != line_len)
			return (free_map(map), exit_error(ERROR_9, 9));
		else if (map->map[i][0] != '1'
				|| map->map[i][line_len - 1] != '1')
			return (free_map(map), exit_error(ERROR_8, 8));
		i++;
	}
	i = 0;
	while (map->map[nbr_lines - 1][i])
		if (map->map[nbr_lines - 1][i++] != '1')
			return (free_map(map), exit_error(ERROR_8, 8));
}

char	**parsing(char **av)
{
	t_game	*map;
	t_game	*cpy;
	char	**temp;

	map = read_map(av[1]);
	map_walls_check(map);
	map->p_x = 0;
	map->p_y = 0;
	find_player_start(map);
	cpy = map_copy(map);
	flood_fill(cpy, map->p_x, map->p_y);
	if (cpy->collect != map->collect || cpy->exit != map->exit)
		return (free_map(cpy), free_map(map), exit_error(ERROR_12, 12), NULL);
	free_map(cpy);
	temp = map->map;
	free(map);
	return (temp);
}
