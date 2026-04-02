#include <so_long.h>

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
