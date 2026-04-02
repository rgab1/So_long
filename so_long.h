#ifndef SO_LONG_H
# define SO_LONG_H
# include <keys.h>
# include <stddef.h>
# include <libft.h>
# include <fcntl.h>
# define SQUARE_LENGTH 25

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

char	**parsing(char **av);
void    print_square(t_data *img, int offset_i, int offset_y, int color);
void	print_map(t_data *img, char **map);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif
