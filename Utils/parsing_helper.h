/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helper.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabinrivault <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 22:43:13 by gabinrivault      #+#    #+#             */
/*   Updated: 2026/04/14 22:43:14 by gabinrivault     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_HELPER_H
# define PARSING_HELPER_H
# include <so_long.h>

void	free_game(t_game *game);
t_game	*map_copy(t_game *map);
void	find_player_start(t_game *map);
void	flood_fill(t_game *map, int x, int y);

#endif
