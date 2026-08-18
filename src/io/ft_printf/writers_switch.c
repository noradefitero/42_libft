/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writers_switch.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 22:36:15 by dde-fite          #+#    #+#             */
/*   Updated: 2026/08/18 08:03:35 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_switch(
	const int stream,
	const char *str,
	t_modifiers *mods,
	va_list *args_ptr
)
{
	if (*str == 'd' || *str == 'i')
		return (write_int(stream, get_int(args_ptr), mods));
	else if (*str == 'u')
		return (write_uint(stream, get_uint(args_ptr), mods));
	else if (*str == 'c')
		return (write_char(stream, get_char(args_ptr), mods));
	else if (*str == 's')
		return (write_str(stream, get_str(args_ptr), mods));
	else if (*str == 'x')
		return (write_hex(stream, get_uint(args_ptr), mods, false));
	else if (*str == 'X')
		return (write_hex(stream, get_uint(args_ptr), mods, true));
	else if (*str == 'p')
		return (write_ptr(stream, get_ptr(args_ptr), mods));
	return (0);
}
