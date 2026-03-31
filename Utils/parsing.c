#include <so_long.h>

typedef struct	s_map
{
	int		collect;
	int		access_collect;
	int		exit;
	int		access_exit;
	int		player_start;
	char	**map_2d;
}				t_map

static int	file_error(char *map_name)
{
	int	name_len;
	int	fd;

	name_len = ft_strlen(map_name);
	if (ft_strncmp(map_name + (name_len - 4), ".ber", 4))
	{
		ft_putstr_fd("Error\nThe file provided is not a .ber file\n", 2);
		exit(3);
	}
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nThe file provided does not exit\n", 2);
		exit(4);
	}
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
		{
			ft_pustr_fd("Error\nAn invalid caracter is in the provided map\n");
			exit(5);
		}
		i++;
	}
	map->map_2d = ft_split(map_str, '\n');
	if (player_start != 1)
		return (ft_putstr_fd("Error\nIncorrect number of P\n"), exit(7));
}

t_map	*read_map(char *map_name)
{
	t_map	*map;
	int		fd;
	char	*line;
	char	*temp;
	char	*map_str;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		exit(6);
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
	nbr_lines = ft_strlen(map->map_2d);
	line_len = ft_strlen(map->map_2d[0]);
	while (map->map_2d[0][i])
		if (->map_2d[0][i++] != '1')
			puterror("Map is not delimited by ones\n", 8);
	i = 0;
	while (map->map_2d[i])
	{
		if (ft_strlen(map->map_2d[i]) != line_len)
			puterror("Map is not rectangular\n", 9);
		else if (map->map_2d[i][0] != '1'
				|| map->map_2d[i][line_len - 1] != '1')
			puterror("Map is not delimited by ones\n", 8);
		i++;
	}
	i = 0;
	while (map->map_2d[nbr_lines - 1][i])
		if (map->map_2d[nbr_lines - 1][i++] != '1')
			puterror("Map is not delimited by ones\n", 8);
}

char	**parsing(t_map *map)
{
	char	**temp;
	int		collect;
	int		exit;


}
