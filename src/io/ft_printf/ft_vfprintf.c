/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 07:37:42 by dde-fite          #+#    #+#             */
/*   Updated: 2026/08/18 19:46:42 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Modifiers
	int		plus;
	int		minus;
	int		blank;
	int		width;
	int		zero;
	int		precision;
*/

static int	interruption_event(
	const int stream,
	const char **str,
	va_list *args_ptr
)
{
	t_modifiers	mods;

	if (!**str)
		return (0);
	(*str)++;
	*str = get_flags(&mods, *str);
	*str = get_width(&mods, *str);
	*str = get_precision(&mods, *str, args_ptr);
	if (**str == '%')
	{
		ft_putchar_fd_buffered(stream, '%');
		*str += 1;
		return (1);
	}
	if (mods.is_precision || mods.minus)
		mods.zero = 0;
	return (write_switch(stream, (*str)++, &mods, args_ptr));
}

int	ft_vfprintf(const int stream, const char *format, va_list ap)
{
	int			chrs_count;

	if (!format)
		return (0);
	chrs_count = 0;
	while (*format)
	{
		if (*format == '%')
			chrs_count += interruption_event(stream, &format, &ap);
		else
		{
			ft_putchar_fd_buffered(stream, *(char *)format++);
			chrs_count++;
		}
	}
	ft_putstr_fd_buffered(stream, NULL, END);
	return (chrs_count);
}
