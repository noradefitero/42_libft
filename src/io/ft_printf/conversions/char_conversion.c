/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 23:37:52 by dde-fite          #+#    #+#             */
/*   Updated: 2026/08/18 19:46:52 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	write_char(const int stream, char c, t_modifiers *mods)
{
	int				paddng;

	paddng = ft_maxnbr(0, mods->width - 1);
	if (!mods->minus)
		fill_width(stream, paddng, false);
	ft_putchar_fd_buffered(stream, c);
	if (mods->minus)
		fill_width(stream, paddng, false);
	return (paddng + 1);
}
