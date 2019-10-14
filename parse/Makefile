NAME= parse.a
SRC= cam_check.c check_tools.c errors.c filereader.c ft_norm.c light_check.c obj_check.c parse_file.c stock_obj.c stock_obj2.c stock_scene.c vect_check.c 
OBJ= $(SRC:.c=.o)
LIBFT=../libft/libft.a
INC = -I ../includes

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ): %.o : %.c
	gcc -c $< $(INC)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
