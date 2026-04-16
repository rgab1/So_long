/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_assets_helper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <grivault@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 19:30:14 by grivault          #+#    #+#             */
/*   Updated: 2026/04/16 19:33:25 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

unsigned int	get_pixel_color(t_mlx *asset, int x, int y)
{
	char	*src;

	src = asset->addr + (y * asset->line_length
			+ x * (asset->bits_per_pixel / 8));
	return (*(unsigned int *)src);
}

void	put_img_to_buffer(t_game *game, t_mlx *asset, int px, int py)
{
	int				x;
	int				y;
	unsigned int	color;

	y = 0;
	while (y < SQUARE_LENGTH)
	{
		x = 0;
		while (x < SQUARE_LENGTH)
		{
			color = get_pixel_color(asset, x, y);
			if (color != 0xFF000000)
				my_mlx_pixel_put(&game->img, px + x, py + y, color);
			x++;
		}
		y++;
	}
}

void	print_player_exit(t_game *game, int x, int y)
{
	print_exit(game, x, y);
	put_img_to_buffer(game, &game->assets->player, x, y);
}
