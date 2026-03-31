#ifndef SO_LONG_H
# define SO_LONG_H
# include <keys.h>

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	puterror(char *error_msg, int exit_code);
char	**parsing(t_map *map);
#endif
