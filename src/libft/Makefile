NAME = libft.a

CCFLAGS = -Wall -Werror -Wextra

CCOMPILER = cc

SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c


UTILS = ft_strncpy.c ft_atol.c ft_lstsort_int.c


UTILSOBJ = $(UTILS:.c=.o)

OBJ = $(SRC:.c=.o)

HEADER = libft.h

BONUSFILES = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
ft_lstclear.c ft_lstiter.c ft_lstmap.c

BONUSOBJ = $(BONUSFILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(UTILSOBJ)
	ar rcs $(NAME) $(OBJ) $(UTILSOBJ)

%.o: %.c
	${CC} ${CCFLAGS} -c -o $@ $^

bonus: $(BONUSOBJ)
	ar rcs $(NAME) $(BONUSOBJ)

clean:
	rm -f $(OBJ) $(BONUSOBJ) $(UTILSOBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
