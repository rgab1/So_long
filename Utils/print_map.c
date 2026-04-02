#include <so_long.h>
#define WALL 0x00FF0000
#define PATH 0x000000FF
#define PLAYER_START 0x0000FF00
#define COLLECTIBLE 0x00FF00FF
#define EXIT 0x00FFFF00

typedef struct s_print
{
	int	i;
	int	y;
	int	offset_i;
	int	offset_y;
}				t_print;

static void	choose_print(t_data *img, char **map, t_print *data)
{
	if (map[data->y][data->i] == '1')
		print_square(img, data->offset_i, data->offset_y, WALL);
	else if (map[data->y][data->i] == '0')
		print_square(img, data->offset_i, data->offset_y, PATH);
	else if (map[data->y][data->i] == 'C')
		print_square(img, data->offset_i, data->offset_y, COLLECTIBLE);
	else if (map[data->y][data->i] == 'P')
		print_square(img, data->offset_i, data->offset_y, PLAYER_START);
	else
		print_square(img, data->offset_i, data->offset_y, EXIT);
}

void	print_map(t_data *img, char **map)
{
	t_print	data;

	data.i = 0;
	data.y = 0;
	data.offset_i = 0;
	data.offset_y = 0;
	while (map[data.y])
	{
		while (map[data.y][data.i])
		{
			choose_print(img, map, &data);
			data.i++;
			data.offset_i += SQUARE_LENGTH;
		}
		data.i = 0;
		data.offset_i = 0;
		data.offset_y += SQUARE_LENGTH;
		data.y++;
	}
}
