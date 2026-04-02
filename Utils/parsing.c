#include <parsing_helper.h>
#include <so_long.h>

static int	file_error(char *map_name)
{
	int	name_len;
	int	fd;

	name_len = ft_strlen(map_name);
	if (ft_strncmp(map_name + (name_len - 4), ".ber", 4))
		puterror("Invalid file: The file provided is not a .ber file\n", 3);
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		puterror("Invalid file: The file provided does not exit\n", 4);
	return (fd);
}

static void	count_stuff(char *map_str, t_map *map)
{
	int	i;

	i = 0;
	map->collect = 0;
	map->exit = 0;
	map->player_start = 0;
	while (map_str[i])
	{
		if (map_str[i] == 'C')
			map->collect += 1;
		else if (map_str[i] == 'E')
			map->exit += 1;
		else if (map_str[i] == 'P')
			map->player_start += 1;
		else if (map_str[i] != '0' && map_str[i] != '1')
			puterror("Invalid map: Invalid caracter in the provided map\n", 5);
		i++;
	}
	map->map_2d = ft_split(map_str, '\n');
	if (map->player_start != 1 || map->exit != 1)
		puterror("Invalid map: Incorrect number of P or E\n", 7);
}

static t_map	*read_map(char *map_name)
{
	t_map	*map;
	int		fd;
	char	*line;
	char	*temp;
	char	*map_str;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		puterror("Malloc failed\n", 6);
	fd = file_error(map_name);
	line = get_next_line(fd);
	map_str = NULL;
	while (line)
	{
		temp = map_str;
		map_str = ft_strjoin(map_str, line);
		free(temp);
		line = get_next_line(fd);
	}
	close(fd);
	count_stuff(map_str, map);
	return (map);
}

static void	map_walls_check(t_map *map)
{
	int i;
	int	line_len;
	int nbr_lines;

	i = 0;
	nbr_lines = ft_tablen((void **)map->map_2d);
	line_len = ft_strlen(map->map_2d[0]);
	while (map->map_2d[0][i])
		if (map->map_2d[0][i++] != '1')
			puterror("Invalid map: Map is not delimited by ones\n", 8);
	i = 0;
	while (map->map_2d[i])
	{
		if (ft_strlen(map->map_2d[i]) != line_len)
			puterror("Invalid map: Map is not rectangular\n", 9);
		else if (map->map_2d[i][0] != '1'
				|| map->map_2d[i][line_len - 1] != '1')
			puterror("Invalid map: Map is not delimited by ones\n", 8);
		i++;
	}
	i = 0;
	while (map->map_2d[nbr_lines - 1][i])
		if (map->map_2d[nbr_lines - 1][i++] != '1')
			puterror("Invalid map: Map is not delimited by ones\n", 8);
}

char	**parsing(char **av)
{
	t_map	*map;
	t_map	*cpy;
	char	**temp;
	int		x;
	int		y;

	map = read_map(av[1]);
	map_walls_check(map);
	x = 0;
	y = 0;
	fin_player_start(map->map_2d, &x, &y);
	cpy = map_copy(map);
	flood_fill(cpy, x, y);
	if (cpy->collect != map->collect || cpy->exit != map->exit)
	{
		free_map(cpy);
		puterror("Invalid map: Cannot reach all C and E\n", 12);
	}
	free_map(cpy);
	temp = map->map_2d;
	free(map);
	return (temp);
}
