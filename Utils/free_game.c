/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <grivault@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 19:31:27 by grivault          #+#    #+#             */
/*   Updated: 2026/04/16 19:31:28 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	free_game(t_game *game)
{
	free_strings(game->map);
	if (game->mlx)
	{
		if (game->assets)
		{
			if (game->assets->wall.img)
				mlx_destroy_image(game->mlx, game->assets->wall.img);
			if (game->assets->player.img)
				mlx_destroy_image(game->mlx, game->assets->player.img);
			if (game->assets->collect.img)
				mlx_destroy_image(game->mlx, game->assets->collect.img);
			if (game->assets->exit.img)
				mlx_destroy_image(game->mlx, game->assets->exit.img);
			if (game->assets->floor.img)
				mlx_destroy_image(game->mlx, game->assets->floor.img);
			free(game->assets);
		}
		if (game->img.img)
			mlx_destroy_image(game->mlx, game->img.img);
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free(game);
}
