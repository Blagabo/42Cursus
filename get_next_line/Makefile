NAME = get_next_line.a
LIB = get_next_line.h
CC = gcc
CFLAGS = -Wall -Werror -Wextra
AR = ar -rcs
SRC = get_next_line.c \
 			get_next_line_utils.c

OBJ = $(SRC:.c=.o)

all:	$(NAME)

$(NAME): 	$(OBJ) $(LIB)
	$(AR) $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re