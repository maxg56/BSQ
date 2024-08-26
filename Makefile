NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror


SRCDIR = srcs
INCDIR = includes

SRC = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c

OBJ = $(SRC:.c=.o)

all: $(NAME)


$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "Library $(NAME) created."


%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "Object files removed."


fclean: clean
	@rm -f $(NAME)
	@echo "Library $(NAME) removed."

re: fclean all

.PHONY: all clean fclean re
