NAME = minishell

# CFLAGS = -Wall -Wextra -Werror 

SRC = utils/get_next_line.c  utils/get_next_line_utils.c  main.c\
	utils/libft.c utils/libft_utlis.c error_handling.c get_path.c\
	built-in.c

OBJ = $(SRC:.c=.o)

$(RM) = rm -f 

all: $(NAME)

$(NAME): $(OBJ) 
	$(CC) $(CFLAGS) $(OBJ) -lreadline -fsanitize=address -g   -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

push: fclean
	git add . && git commit -m "push" && git push

re: fclean all
