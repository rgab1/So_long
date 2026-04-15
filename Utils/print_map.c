/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabinrivault <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 22:43:23 by gabinrivault      #+#    #+#             */
/*   Updated: 2026/04/15 23:17:04 by gabinrivault     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <mlx.h>
#define WALL 0x00FF0000
#define PATH 0x000000FF
#define PLAYER_START 0x0000FF00
#define COLLECTIBLE 0x00FF00FF
#define EXIT 0x00FFFF00

static void	choose_print(t_game *game, int x, int y)
{
	int	px;
	int	py;

	px = x * SQUARE_LENGTH;
	py = y * SQUARE_LENGTH;
	if (game->map[y][x] == '1')
		print_wall(game, px, py);
	else if (game->map[y][x] == '0')
		print_floor(game, px, py);
	else if (game->map[y][x] == 'C')
		print_collectible(game, px, py);
	else if (game->map[y][x] == 'P')
		print_player(game, px, py);
	else if (game->map[y][x] == 'Z')
		print_player_exit(game, px, py);
	else
		print_exit(game, px, py);
}

void	print_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			choose_print(game, x, y);
			x++;
		}
		y++;
	}
	ft_printf("%d moves\n", game->moves);
}
