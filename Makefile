# Configuración básica
CFLAGS  = -Wall -Wextra -Werror -g -O0
NAME    = push_swap
LIB_DIR = libft
LIB_NAME = $(LIB_DIR)/libft.a
SRC     = $(wildcard *.c)   # <-- Usa todos los .c del directorio actual
OBJ     = $(SRC:.c=.o)

# Regla principal
all: $(LIB_NAME) $(NAME)

# Compilar la biblioteca primero
$(LIB_NAME):
	@make -C $(LIB_DIR)

# Compilar el programa principal
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIB_DIR) -lft

# Regla para archivos objeto
%.o: %.c
	$(CC) $(CFLAGS) -I$(LIB_DIR) -c $< -o $@

# Limpiar
clean:
	@rm -f $(OBJ)
	@make -C $(LIB_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIB_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
