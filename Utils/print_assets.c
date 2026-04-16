/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_assets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabinrivault <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 13:39:52 by gabinrivault      #+#    #+#             */
/*   Updated: 2026/04/16 13:50:41 by gabinrivault     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <print_assets_helper.h>

void	print_floor(t_game *game, int x, int y)
{
	put_img_to_buffer(game, &game->assets->floor, x, y);
}

void	print_wall(t_game *game, int x, int y)
{
	print_floor(game, x, y);
	put_img_to_buffer(game, &game->assets->wall, x, y);
}

void	print_player(t_game *game, int x, int y)
{
	print_floor(game, x, y);
	put_img_to_buffer(game, &game->assets->player, x, y);
}

void	print_collectible(t_game *game, int x, int y)
{
	print_floor(game, x, y);
	put_img_to_buffer(game, &game->assets->collect, x, y);
}

void	print_exit(t_game *game, int x, int y)
{
	print_floor(game, x, y);
	put_img_to_buffer(game, &game->assets->exit, x, y);
}
