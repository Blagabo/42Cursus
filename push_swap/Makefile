NAME = push_swap
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
MKDIR = mkdir -p

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes
LIBFT_DIR = includes/libft
LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF_DIR = includes/ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

SRC_FILES = ft_push.c \
ft_reverse_rotate.c \
ft_rotate.c \
ft_swap.c \
main.c \
parsing.c \
sorting.c \
utils.c
SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF)
	@echo "Building $(NAME)"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(FT_PRINTF)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "Compiling $<"
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(OBJ_DIR):
	@echo "Creating directory $(OBJ_DIR)"
	$(MKDIR) $(OBJ_DIR)

$(LIBFT):
	@echo "Building libft"
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	@echo "Building ft_printf"
	$(MAKE) -C $(FT_PRINTF_DIR)

clean:
	@echo "Cleaning object files"
	$(RM) $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	@echo "Cleaning all"
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
