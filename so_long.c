#include <so_long.h>
#include <mlx.h>
#define SQUARE_LENGTH 50
#define RED 0x00FF0000
#define BLUE 0x000000FF

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	print_square(t_data *img, int offset_i, int offset_y, int color)
{
	int		i;
	int		y;

	i = offset_i;
	y = offset_y;
	while (i < SQUARE_LENGTH + offset_i)
	{
		while (y < SQUARE_LENGTH + offset_y)
			my_mlx_pixel_put(img, i, y++, color);
		y = offset_y;
		i++;
	}
}

int	main(void)
{
	void	*mlx;
	t_data	img;
	void	*mlx_win;
	int 	i;
	int		y;
	int		offset_i;
	int		offset_y;
	int		window_height;
	int		window_length;
	int		color;

	color = BLUE;
	i = 0;
	y = 0;
	offset_i = 0;
	offset_y = 0;
	window_height = 300;
	window_length = 600;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, window_length, window_height, "Hello world!");
	img.img = mlx_new_image(mlx, window_length, window_height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length
			, &img.endian);
	while (y < (window_length / SQUARE_LENGTH) / 2)
	{
		while (i < (window_length / SQUARE_LENGTH))
		{
			color = (color == BLUE ? RED : BLUE);
			print_square(&img, offset_i, offset_y, color);
			i++;
			offset_i += SQUARE_LENGTH;
		}
		i = 0;
		offset_i = 0;
		offset_y += SQUARE_LENGTH;
		y++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
