/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd_buffered.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 19:35:08 by dde-fite          #+#    #+#             */
/*   Updated: 2026/08/18 19:45:43 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd_buffered(
	const int stream,
	const char c
)
{
	char	str[2];

	str[0] = c;
	str[1] = '\0';
	return (ft_putstr_fd_buffered(stream, str, CONTINUE));
}
