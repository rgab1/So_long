/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putx_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 12:10:17 by grivault          #+#    #+#             */
/*   Updated: 2025/12/06 13:06:12 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf_utils.h>

void	ft_putx_data(unsigned int x, t_data *data)
{
	char	*base;

	base = "0123456789abcdef";
	if (x >= 16)
		ft_putx_data(x / 16, data);
	data->written_c_count++;
	write(1, base + (x % 16), 1);
}
