#include <so_long.h>
#include <mlx.h>
#include <errors.h>

void	*win_init(void *mlx, char **map)
{
	void	*mlx_win;
	int		win_height;
	int		win_width;

	win_height = (ft_tablen((void **)map) * SQUARE_LENGTH);
	win_width = (ft_strlen(map[0]) * SQUARE_LENGTH);
	mlx_win = mlx_new_window(mlx, win_width, win_height, "So_long");
	return (mlx_win);
}

t_data	img_init(void *mlx, char **map)
{
	t_data	img;
	int		win_height;
	int		win_width;

	win_height = (ft_tablen((void **)map) * SQUARE_LENGTH);
	win_width = (ft_strlen(map[0]) * SQUARE_LENGTH);
	img.img = mlx_new_image(mlx, win_width, win_height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	return (img);
}

int	main(int ac, char **av)
{
	void	*mlx;
	t_data	img;
	void	*mlx_win;
	char	**map;

	if (ac != 2)
		puterror(ERROR_10, 10);
	map = parsing(av);
	mlx = mlx_init();
	mlx_win = win_init(mlx, map);
	img = img_init(mlx, map);
	print_map(&img, map);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
