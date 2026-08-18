/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 07:52:48 by dde-fite          #+#    #+#             */
/*   Updated: 2026/08/18 07:53:09 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_fprintf(const int stream, const char *str, ...)
{
	va_list	args;
	int		ret;

	va_start(args, str);
	ret = ft_vfprintf(stream, str, args);
	va_end(args);
	return (ret);
}
