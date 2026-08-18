/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_buffered.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 23:25:08 by dde-fite          #+#    #+#             */
/*   Updated: 2026/08/18 19:49:24 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

void	ft_putnbr_fd_buffered(int n, int fd)
{
	if (n == INT_MIN)
	{
		ft_putnbr_fd_buffered(INT_MIN / 10, fd);
		ft_putnbr_fd_buffered(-(INT_MIN % 10), fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd_buffered(fd, '-');
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr_fd_buffered(n / 10, fd);
		ft_putchar_fd_buffered(fd, (n % 10) + '0');
	}
	else
		ft_putchar_fd_buffered(fd, n + '0');
}

// int	main(void)
// {
// 	ft_putnbr_fd(3435, 1);
// 	ft_putchar_fd('\n', 1);
// 	ft_putnbr_fd(0, 1);
// 	ft_putchar_fd('\n', 1);
// 	ft_putnbr_fd(-52, 1);
// 	ft_putchar_fd('\n', 1);
// 	ft_putnbr_fd(INT_MAX, 1);
// 	ft_putchar_fd('\n', 1);
// 	ft_putnbr_fd(INT_MIN, 1);
// 	ft_putchar_fd('\n', 1);
// 	ft_putnbr_fd(0, 1);
// 	ft_putchar_fd('\n', 1);
// 	ft_putnbr_fd(10000, 1);
// 	ft_putchar_fd('\n', 1);
// }
