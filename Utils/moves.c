/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabinrivault <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 22:42:12 by gabinrivault      #+#    #+#             */
/*   Updated: 2026/04/14 22:47:25 by gabinrivault     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	move_up(t_game *game)
{
	if (game->p_y < 2)
		return ;
	if (game->map[game->p_y - 1][game->p_x] != '1')
	{
		check_collect(game, game->map[game->p_y - 1][game->p_x]);
		check_exit(game, game->map[game->p_y - 1][game->p_x]);
		if (game->map[game->p_y - 1][game->p_x] == 'E')
			game->map[game->p_y - 1][game->p_x] = 'Z';
		else
			game->map[game->p_y - 1][game->p_x] = 'P';
		if (game->map[game->p_y][game->p_x] == 'Z')
			game->map[game->p_y][game->p_x] = 'E';
		else
			game->map[game->p_y][game->p_x] = '0';
		game->p_y -= 1;
		game->moves += 1;
		print_map(game);
	}
}

void	move_down(t_game *game)
{
	if (game->p_y >= (int)ft_tablen((void **)game->map) - 2)
		return ;
	if (game->map[game->p_y + 1][game->p_x] != '1')
	{
		check_collect(game, game->map[game->p_y + 1][game->p_x]);
		check_exit(game, game->map[game->p_y + 1][game->p_x]);
		if (game->map[game->p_y + 1][game->p_x] == 'E')
			game->map[game->p_y + 1][game->p_x] = 'Z';
		else
			game->map[game->p_y + 1][game->p_x] = 'P';
		if (game->map[game->p_y][game->p_x] == 'Z')
			game->map[game->p_y][game->p_x] = 'E';
		else
			game->map[game->p_y][game->p_x] = '0';
		game->p_y += 1;
		game->moves += 1;
		print_map(game);
	}
}

void	move_right(t_game *game)
{
	if (game->p_x >= (int)ft_strlen(game->map[0]) - 2)
		return ;
	if (game->map[game->p_y][game->p_x + 1] != '1')
	{
		check_collect(game, game->map[game->p_y][game->p_x + 1]);
		check_exit(game, game->map[game->p_y][game->p_x + 1]);
		if (game->map[game->p_y][game->p_x + 1] == 'E')
			game->map[game->p_y][game->p_x + 1] = 'Z';
		else
			game->map[game->p_y][game->p_x + 1] = 'P';
		if (game->map[game->p_y][game->p_x] == 'Z')
			game->map[game->p_y][game->p_x] = 'E';
		else
			game->map[game->p_y][game->p_x] = '0';
		game->p_x += 1;
		game->moves += 1;
		print_map(game);
	}
}

void	move_left(t_game *game)
{
	if (game->p_x < 2)
		return ;
	if (game->map[game->p_y][game->p_x - 1] != '1')
	{
		check_collect(game, game->map[game->p_y][game->p_x - 1]);
		check_exit(game, game->map[game->p_y][game->p_x - 1]);
		if (game->map[game->p_y][game->p_x - 1] == 'E')
			game->map[game->p_y][game->p_x - 1] = 'Z';
		else
			game->map[game->p_y][game->p_x - 1] = 'P';
		if (game->map[game->p_y][game->p_x] == 'Z')
			game->map[game->p_y][game->p_x] = 'E';
		else
			game->map[game->p_y][game->p_x] = '0';
		game->p_x -= 1;
		game->moves += 1;
		print_map(game);
	}
}
