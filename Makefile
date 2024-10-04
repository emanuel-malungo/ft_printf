# Nome da biblioteca
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

# Fonte dos arquivos
SRC = ft_printf.c \
      ft_putnbr.c \
      ft_putpointer.c \
      ft_putstr.c \
      ft_putchar.c \
      ft_putnbr_unsigned.c \
      ft_putnbr_hex.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
