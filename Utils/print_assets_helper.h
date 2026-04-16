/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_assets_helper.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <grivault@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 19:32:44 by grivault          #+#    #+#             */
/*   Updated: 2026/04/16 19:32:46 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_ASSETS_HELPER_H
# define PRINT_ASSETS_HELPER_H
# include <so_long.h>

unsigned int	get_pixel_color(t_mlx *asset, int x, int y);
void			put_img_to_buffer(t_game *game, t_mlx *asset, int x, int y);

#endif
