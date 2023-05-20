NAME = libftprintf.a
LIB = ft_printf.h
CC = gcc
CFLAGS = -Wall -Werror -Wextra
AR = ar -rcs
SRC = ft_printf.c \
	  ft_putchar_pf.c \
		ft_puthexa_pf.c \
	  ft_putnbr_pf.c \
		ft_putptr_pf.c \
	  ft_putstr_pf.c \
		ft_putunint_pf.c

OBJ = $(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ) $(LIB)

$(NAME): 	$(OBJ) $(LIB)
	$(AR) $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re