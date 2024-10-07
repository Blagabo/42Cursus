# Nombre de los ejecutables
SERVER = server
CLIENT = client

# Directorios de las librerías
LIBFT_DIR = ./libft
PRINTF_DIR = ./ft_printf

# Librerías
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

# Archivos fuente
SRC_CLIENT = client.c
SRC_SERVER = server.c

# Archivos objeto
OBJS_CLIENT = $(SRC_CLIENT:.c=.o)
OBJS_SERVER = $(SRC_SERVER:.c=.o)

# Variables de compilación
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

# Compilar todo
all: $(LIBFT) $(PRINTF) $(SERVER) $(CLIENT)

# Compilar libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Compilar ft_printf
$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

# Compilar el servidor
$(SERVER): $(OBJS_SERVER) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) -o $(SERVER) $(OBJS_SERVER) $(LIBFT) $(PRINTF)

# Compilar el cliente
$(CLIENT): $(OBJS_CLIENT) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) -o $(CLIENT) $(OBJS_CLIENT) $(LIBFT) $(PRINTF)

# Regla para compilar archivos .c a .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpiar archivos objeto
clean:
	$(RM) $(OBJS_CLIENT) $(OBJS_SERVER)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean

# Limpiar todo
fclean: clean
	$(RM) $(SERVER) $(CLIENT)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean

# Reconstruir todo
re: fclean all

# Especificar que estas reglas no son archivos
.PHONY: all clean fclean re
