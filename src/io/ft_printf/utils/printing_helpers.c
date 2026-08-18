/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 22:34:41 by dde-fite          #+#    #+#             */
/*   Updated: 2026/08/18 08:04:59 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	fill_width(const int stream, unsigned int pd, bool zeroes)
{
	if (zeroes)
		fill_char(stream, '0', pd);
	else
		fill_char(stream, ' ', pd);
}

void	fill_char(const int stream, char c, unsigned int nbr)
{
	while (nbr-- > 0)
	{
		ft_putchar_fd(c, stream);
	}
}
