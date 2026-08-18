/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 23:37:52 by dde-fite          #+#    #+#             */
/*   Updated: 2026/08/18 19:48:32 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	putstrn(const int stream, char *s, size_t len)
{
	while (len-- > 0)
		ft_putchar_fd_buffered(stream, *s++);
}

static int	null_management(const int stream, t_modifiers *mods)
{
	int	null_len;
	int	paddng;

	null_len = ft_strlen("(null)");
	if (!mods->is_precision || (mods->is_precision
			&& mods->precision >= null_len))
		paddng = ft_maxnbr(0, mods->width - null_len);
	else
		paddng = mods->width;
	if (!mods->minus)
		fill_width(stream, paddng, false);
	if (!mods->is_precision || (mods->is_precision
			&& mods->precision >= null_len))
		ft_putstr_fd_buffered(stream, "(null)", CONTINUE);
	else
		null_len = 0;
	if (mods->minus)
		fill_width(stream, paddng, false);
	return (null_len + paddng);
}

int	write_str(const int stream, char *str, t_modifiers *mods)
{
	size_t			str_len;
	int				paddng;

	if (!str)
		return (null_management(stream, mods));
	if (mods->is_precision)
		str_len = ft_minnbr(ft_strlen(str), mods->precision);
	else
		str_len = ft_strlen(str);
	paddng = ft_maxnbr(0, mods->width - str_len);
	if (!mods->minus)
		fill_width(stream, paddng, false);
	putstrn(stream, str, str_len);
	if (mods->minus)
		fill_width(stream, paddng, false);
	return (str_len + paddng);
}
