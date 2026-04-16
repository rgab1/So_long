/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabinrivault <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 22:41:52 by gabinrivault      #+#    #+#             */
/*   Updated: 2026/04/16 19:21:33 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <keys.h>
#include <mlx.h>
#include <so_long.h>
#include <parsing_helper.h>

void	close_window_and_exit(t_game *game)
{
	free_game(game);
	exit(0);
}

int	key_handler(int keycode, t_game *game)
{
	if (keycode == K_ESC)
		close_window_and_exit(game);
	else if (keycode == K_W || keycode == K_UP)
		move_up(game);
	else if (keycode == K_A || keycode == K_LEFT)
		move_left(game);
	else if (keycode == K_S || keycode == K_DOWN)
		move_down(game);
	else if (keycode == K_D || keycode == K_RIGHT)
		move_right(game);
	else
		return (puterror("Key not supported\n"), 0);
	return (0);
}
