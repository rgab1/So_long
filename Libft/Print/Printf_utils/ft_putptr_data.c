/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 13:16:12 by grivault          #+#    #+#             */
/*   Updated: 2025/12/07 23:13:27 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf_utils.h>

static void	ft_putul_data(unsigned long ul, t_data *data)
{
	char	*base;

	base = "0123456789abcdef";
	if (ul >= 16)
		ft_putul_data(ul / 16, data);
	data->written_c_count++;
	write(1, base + (ul % 16), 1);
}

void	ft_putptr_data(void *ptr, t_data *data)
{
	if (!ptr)
	{
		write(1, "(nil)", 5);
		data->written_c_count += 5;
		return ;
	}
	write(1, "0x", 2);
	data->written_c_count += 2;
	ft_putul_data((unsigned long)ptr, data);
}
