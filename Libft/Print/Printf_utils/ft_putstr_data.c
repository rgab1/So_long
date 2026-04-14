/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 03:19:41 by grivault          #+#    #+#             */
/*   Updated: 2025/12/07 23:34:14 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf_utils.h>

void	ft_putstr_data(char *str, t_data *data)
{
	size_t	len;

	if (!str)
	{
		write(1, "(null)", 6);
		data->written_c_count += 6;
		return ;
	}
	len = ft_strlen(str);
	data->written_c_count += len;
	write(1, str, len);
}
