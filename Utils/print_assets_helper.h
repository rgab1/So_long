#ifndef PRINT_ASSETS_HELPER_H
# include <so_long.h>

unsigned int	get_pixel_color(t_mlx *asset, int x, int y);
void			put_img_to_buffer(t_game *game, t_mlx *asset, int x, int y);

#endif
