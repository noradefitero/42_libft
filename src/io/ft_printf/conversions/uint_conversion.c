/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 23:37:52 by dde-fite          #+#    #+#             */
/*   Updated: 2026/08/18 19:49:39 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	print_number(const int stream, unsigned int nbr, t_modifiers *mods)
{
	if (!(mods->is_precision && mods->precision == 0 && nbr == 0))
	{
		if (nbr >= INT_MAX)
		{
			ft_putnbr_fd_buffered(nbr / 10, stream);
			ft_putnbr_fd_buffered(nbr % 10, stream);
		}
		else
			ft_putnbr_fd_buffered(nbr, stream);
	}
}

unsigned int	write_uint(
	const int stream,
	unsigned int nbr,
	t_modifiers *mods
)
{
	int				nbr_len;
	int				paddng;
	int				precsn;

	if (mods->is_precision && mods->precision == 0 && nbr == 0)
		nbr_len = 0;
	else
		nbr_len = ft_nbrlen(nbr);
	precsn = ft_maxnbr(0, mods->precision - nbr_len);
	paddng = ft_maxnbr(0, mods->width - (nbr_len + precsn));
	if (!mods->minus)
		fill_width(stream, paddng, mods->zero);
	fill_char(stream, '0', precsn);
	print_number(stream, nbr, mods);
	if (mods->minus)
		fill_width(stream, paddng, mods->zero);
	return (nbr_len + paddng + precsn);
}
