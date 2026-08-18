/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_buffered.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 18:34:59 by dde-fite          #+#    #+#             */
/*   Updated: 2026/08/18 19:44:10 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static inline size_t	buffer_append(
	char *buf,
	size_t *index,
	const char *str,
	size_t len
)
{
	size_t	copied;

	copied = BUFFER_SIZE_PRINTF - *index;
	if (copied > len)
		copied = len;
	ft_memcpy(buf + *index, str, copied);
	*index += copied;
	return (copied);
}

static size_t	buffer_append_str(
	char *buf,
	size_t *index,
	const char *str
)
{
	size_t	len;
	size_t	added;
	size_t	copied;

	len = ft_strlen(str);
	added = 0;
	while (len)
	{
		copied = buffer_append(buf, index, str + added, len);
		added += copied;
		len -= copied;
		if (*index == BUFFER_SIZE_PRINTF)
			break ;
	}
	return (added);
}

int	ft_putstr_fd_buffered(
	const int stream,
	const char *str,
	t_buffer_state state
)
{
	static char		buf[BUFFER_SIZE_PRINTF];
	static size_t	index;
	size_t			added;

	if (state == END)
	{
		if (index)
			write(stream, buf, index);
		index = 0;
		return (0);
	}
	if (!str)
		return (0);
	added = buffer_append_str(buf, &index, str);
	if (index == BUFFER_SIZE_PRINTF)
	{
		write(stream, buf, index);
		index = 0;
	}
	return (added);
}
