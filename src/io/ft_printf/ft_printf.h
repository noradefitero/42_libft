/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 21:48:15 by dde-fite          #+#    #+#             */
/*   Updated: 2026/08/19 05:48:34 by dde-fite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                           FT_PRINTF by dde-fite                            */
/* ************************************************************************** */

/* ************************ PREPROCESSOR STATEMENTS ************************* */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# ifndef BUFFER_SIZE_PRINTF
#  define BUFFER_SIZE_PRINTF 1024
# endif

# include "libft.h"

# include <stdarg.h>
# include <stdint.h>
# include <stdbool.h>
# include <limits.h>
# include <unistd.h>

/* ******************** STRUCTS, TYPES, OTHER STATEMENTS ******************** */

typedef struct s_modifiers
{
	bool	plus;
	bool	minus;
	bool	blank;
	bool	hash;
	int		width;
	bool	zero;
	int		precision;
	bool	is_precision;
}	t_modifiers;

typedef uint8_t	t_buffer_state;

# define CONTINUE 0
# define END      1

/* ****************************** MAIN PROTOYPE ***************************** */
int				ft_printf(const char *format, ...);
int				ft_fprintf(const int stream, const char *format, ...);
int				ft_vprintf(const char *format, va_list ap);
int				ft_vfprintf(const int stream, const char *format, va_list ap);
/* ************************************************************************** */

int				ft_putstr_fd_buffered(
					const int stream,
					const char *str,
					t_buffer_state state
					);
int				ft_putchar_fd_buffered(
					const int stream,
					const char c
					);
void			ft_putnbr_fd_buffered(int n, int fd);

/* **************************** ARGUMENT GETTERS **************************** */
const char		*get_flags(t_modifiers *mods, const char *str);
const char		*get_width(t_modifiers *mods, const char *str);
const char		*get_precision(t_modifiers *mods, const char *str,
					va_list *args_ptr);

/* ************************** INTERRUPTION WRITERS ************************** */
int				write_switch(
					const int stream,
					const char *str,
					t_modifiers *mods,
					va_list *args_ptr);
int				write_char(const int stream, char c, t_modifiers *mods);
int				write_int(const int stream, int nbr, t_modifiers *mods);
unsigned int	write_uint(
					const int stream,
					unsigned int nbr,
					t_modifiers *mods
					);
int				write_str(const int stream, char *str, t_modifiers *mods);
int				write_hex(
					const int stream,
					unsigned int nbr,
					t_modifiers *mods,
					bool uppercase
					);
int				write_ptr(const int stream, void *ptr, t_modifiers *mods);

/* ********************************  UTILS ********************************* */

static inline void	fill_char(const int stream, char c, unsigned int nbr)
{
	while (nbr-- > 0)
	{
		ft_putchar_fd_buffered(stream, c);
	}
}

static inline void	fill_width(const int stream, unsigned int pd, bool zeroes)
{
	if (zeroes)
		fill_char(stream, '0', pd);
	else
		fill_char(stream, ' ', pd);
}

char			manage_sign(int nbr, unsigned int *u_nbr, t_modifiers *mods);

/* **************************** VARIADIC GETTERS **************************** */
int				get_int(va_list *args_ptr);
unsigned int	get_uint(va_list *args_ptr);
char			get_char(va_list *args_ptr);
char			*get_str(va_list *args_ptr);
void			*get_ptr(va_list *args_ptr);

#endif /* FT_PRINTF */