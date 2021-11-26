SRC=\
	ft_printf.c \
	ft_print.c \
	ft_parse.c \
	ft_util.c
INC=\
	ft_printf.h
OBJ=$(SRC:.c=.o)
CFLAGS=-Wall -Wextra -Werror -ansi -pedantic
NAME=libftprintf.a

$(NAME): $(INC) $(OBJ) $(NAME)($(OBJ))
re: fclean all
all: $(NAME)
bonus: $(NAME)

$(NAME)(%.o): %.o
	ar rcs $(NAME) $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

%.o: %.c $(INC)
	$(CC) -c $(CFLAGS) -o $@ $<

norm:
	norminette $(SRC) $(INC)
