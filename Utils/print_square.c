/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabinrivault <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 22:43:37 by gabinrivault      #+#    #+#             */
/*   Updated: 2026/04/14 22:43:38 by gabinrivault     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	print_square(t_mlx *img, int offset_i, int offset_y, int color)
{
	int		i;
	int		y;

	i = offset_i;
	y = offset_y;
	while (i < SQUARE_LENGTH + offset_i)
	{
		while (y < SQUARE_LENGTH + offset_y)
			my_mlx_pixel_put(img, i, y++, color);
		y = offset_y;
		i++;
	}
}
