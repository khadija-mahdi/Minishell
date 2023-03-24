src = main.c \
	parsing/parsing.c\
	parsing/parsing_utils.c\
	parsing/copy_str.c \
	parsing/expand_functions.c \
	parsing/m_node.c \
	parsing/strings_functions.c\
	parsing/files.c\
	parsing/here_doc.c\
	parsing/syntax.c \
	parsing/start.c\
	parsing/garbage.c \
	parsing/paths.c\
	parsing/Signals.c \
	Utils/equals.c \
	Utils/random.c \
	Utils/int_utils.c \
	Utils/status.c \
	Utils/Strings.c parsing/env.c\
	exec/exec.c \
	exec/exuc_utlis.c\
	exec/implement_builtins/echo.c\
	exec/implement_builtins/unset.c\
	exec/implement_builtins/export.c\
	exec/implement_builtins/export_env.c\
	exec/implement_builtins/exit.c\
	exec/implement_builtins/env.c\
	exec/implement_builtins/cd_pwd.c\
	exec/implement_builtins/builtins.c\
	exec/pipes/pipe.c\
	exec/pipes/piping.c\




obj = ${src:.c=.o}

NAME =  minishell

# CFLAGS = -Wall -Werror -Wextra
incldlib = -I/Users/aaitouna/homebrew/opt/readline/include
libreadline = -lreadline -L/Users/kmahdi/homebrew/opt/readline/lib
libft = libft/libft.a

all: $(NAME)

$(NAME) : $(obj) $(libft)
	gcc $(obj) $(libft) $(libreadline) $() -fsanitize=address -g -o $(NAME)

$(libft):
	make bonus --directory=libft

clean_libft:
	make clean  --directory=libft

clean : clean_libft
	rm -rf $(obj) $(mandatory_obj) $(bonus_obj)

fclean : clean clean_libft
	rm -rf $(NAME) $(libft) $(CHECKER)

re : fclean $(NAME)

files = $(shell git diff --name-only HEAD)

commit_and_push: fclean
	git add . && git commit -m "changes $(files)" && git push;
