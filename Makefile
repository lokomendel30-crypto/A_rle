NAME = rle
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c \
      ft_strlen.c \
      ft_is_digit.c \
      ft_rle_compress.c \
      ft_rle_decompress.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c rle.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re































































































































































