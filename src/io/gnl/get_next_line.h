/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 20:50:02 by dde-fite          #+#    #+#             */
/*   Updated: 2026/08/18 07:30:55 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                         GET_NEXT_LINE by dde-fite                          */
/* ************************************************************************** */

/* ************************ PREPROCESSOR STATEMENTS ************************* */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE_GNL
#  define BUFFER_SIZE_GNL 1024
# endif

# include "libft.h"

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <sys/select.h>

char	*get_next_line(int fd);

#endif /* GET_NEXT_LINE_H */