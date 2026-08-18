/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 21:31:15 by dde-fite          #+#    #+#             */
/*   Updated: 2025/12/16 22:53:20 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nbr)
{
	int	i;

	if (nbr < 1)
		return (0);
	i = 1;
	while (i * i < nbr)
		i++;
	if (i * i > nbr && (i * i - nbr > (i - 1) * (i - 1) - nbr))
		return (i - 1);
	return (i);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int			i;

// 	i = 0;
// 	while (i <= 100)
// 	{
// 		printf("ft_sqrt(%d) = %d\n", i, ft_sqrt(i));
// 		i++;
// 	}
// 	return (0);
// }
