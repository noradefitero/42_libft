NAME		= libft.a
CC = cc
CFLAGS = -Wall -Wextra -Iinclude -march=native
CLINKFLAGS = -fno-semantic-interposition -fno-plt
ARFLAGS = rcs
ifdef DEBUG
    CFLAGS += -g -fdiagnostics-color=always -O0
else
    CFLAGS += -Werror -O3
endif

BUILD = build
SRCS = \
	src/char/ft_isalnum.c \
	src/char/ft_isalpha.c \
	src/char/ft_isascii.c \
	src/char/ft_isdigit.c \
	src/char/ft_isprint.c \
	src/char/ft_issign.c \
	src/char/ft_isspace.c \
	src/char/ft_tolower.c \
	src/char/ft_toupper.c \
	src/conversions/ft_atoi.c \
	src/conversions/ft_atol.c \
	src/conversions/ft_itoa.c \
	src/io/ft_putchar_fd.c \
	src/io/ft_putendl_fd.c \
	src/io/ft_putnbr_fd.c \
	src/io/ft_putstr_fd.c \
	src/io/gnl/get_next_line.c \
	src/io/ft_printf/argument_getters.c \
	src/io/ft_printf/ft_fprintf.c \
	src/io/ft_printf/ft_printf.c \
	src/io/ft_printf/ft_vfprintf.c \
	src/io/ft_printf/ft_vprintf.c \
	src/io/ft_printf/writers_switch.c \
	src/io/ft_printf/conversions/char_conversion.c \
	src/io/ft_printf/conversions/hex_conversion.c \
	src/io/ft_printf/conversions/int_conversion.c \
	src/io/ft_printf/conversions/ptr_conversion.c \
	src/io/ft_printf/conversions/str_conversion.c \
	src/io/ft_printf/conversions/uint_conversion.c \
	src/io/ft_printf/utils/number_helpers.c \
	src/io/ft_printf/utils/printing_helpers.c \
	src/io/ft_printf/utils/variadic_wrappers.c \
	src/lists/ft_lstadd_back.c \
	src/lists/ft_lstadd_front.c \
	src/lists/ft_lstclear.c \
	src/lists/ft_lstdelone.c \
	src/lists/ft_lstiter.c \
	src/lists/ft_lstlast.c \
	src/lists/ft_lstmap.c \
	src/lists/ft_lstnew.c \
	src/lists/ft_lstsize.c \
	src/math/ft_abs.c \
	src/math/ft_maxnbr.c \
	src/math/ft_maxsize.c \
	src/math/ft_minnbr.c \
	src/math/ft_minsize.c \
	src/math/ft_nbrlen.c \
	src/math/ft_sqrt.c \
	src/memory/ft_bzero.c \
	src/memory/ft_calloc.c \
	src/memory/ft_memchr.c \
	src/memory/ft_memcmp.c \
	src/memory/ft_memcpy.c \
	src/memory/ft_memmove.c \
	src/memory/ft_memset.c \
	src/string/ft_split.c \
	src/string/ft_strchr.c \
	src/string/ft_strdup.c \
	src/string/ft_strisdigit.c \
	src/string/ft_striteri.c \
	src/string/ft_strjoin.c \
	src/string/ft_strlcat.c \
	src/string/ft_strlcpy.c \
	src/string/ft_strlen.c \
	src/string/ft_strmapi.c \
	src/string/ft_strncmp.c \
	src/string/ft_strndup.c \
	src/string/ft_strndup_ssize.c \
	src/string/ft_strnstr.c \
	src/string/ft_strrchr.c \
	src/string/ft_strtrim.c \
	src/string/ft_substr.c
OBJS = $(patsubst %.c,$(BUILD)/%.o,$(SRCS))



all: $(NAME)

$(NAME): $(OBJS)
	@ar $(ARFLAGS) $(NAME) $(OBJS)

$(BUILD)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re