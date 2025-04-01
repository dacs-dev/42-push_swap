CFLAGS  = -Wall -Wextra -Werror -g -O0
NAME    = push_swap
CHEKER    = checker
LIB_DIR = libft
LIB_NAME = $(LIB_DIR)/libft.a
SRC     = main.c push_swap.c sort.c sort_utils.c operations.c utils.c swap.c \
rotate.c reverse_rotate.c lst_indexed_ext.c lst_indexed.c indexes_utils.c cost.c
CHECKER_SRC = checker.c checker_aux.c get_next_line.c get_next_line_utils.c \
sort_utils.c operations.c utils.c swap.c rotate.c reverse_rotate.c \
lst_indexed_ext.c lst_indexed.c indexes_utils.c cost.c
OBJ = $(SRC:.c=.o)
CHECKER_OBJ = $(CHECKER_SRC:.c=.o)


all: $(LIB_NAME) $(NAME) $(CHEKER)

$(LIB_NAME):
	@make -C $(LIB_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIB_DIR) -lft

$(CHEKER): $(CHECKER_OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIB_DIR) -lft

bonus: $(CHEKER)

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIB_DIR) -c $< -o $@

clean:
	@rm -f $(OBJ) $(CHECKER_OBJ)
	@make -C $(LIB_DIR) clean

fclean: clean
	@rm -f $(NAME) $(CHEKER)
	@make -C $(LIB_DIR) fclean

re: fclean all

.PHONY: all clean fclean re