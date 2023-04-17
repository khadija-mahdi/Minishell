src = parsing/parsing.c\
        parsing/parsing_utils.c\
        parsing/copy_str.c \
		parsing/copy_str_helpers.c \
        parsing/expand_functions.c \
        parsing/t_node.c \
        parsing/strings_functions.c\
        parsing/files.c\
        parsing/here_doc.c\
        parsing/syntax/syntax.c\
        parsing/syntax/helper.c\
        parsing/start.c\
        parsing/garbage.c \
        parsing/paths.c \
        parsing/Signals.c \
        parsing/print.c \
        parsing/parsing_helper.c \
        Utils/equals.c\
        Utils/random.c\
        Utils/int_utils.c\
        Utils/status.c\
        Utils/Strings.c\
        parsing/env.c \
        parsing/split_by_set.c\
        Utils/promt.c\
        Utils/full_line.c\
        Utils/her_doc_interrupte.c \
        exec/exec.c \
        exec/exuc_utlis.c\
        exec/implement_builtins/echo.c\
        exec/implement_builtins/unset.c\
        exec/implement_builtins/export/export.c\
        exec/implement_builtins/export/underscore_env.c \
        exec/implement_builtins/export/export_utils.c\
        exec/implement_builtins/export/export_env.c\
        exec/implement_builtins/export/main_export.c\
        exec/implement_builtins/export/reset_export.c\
        exec/implement_builtins/exit.c\
        exec/implement_builtins/env.c\
        exec/implement_builtins/cd_pwd.c\
        exec/implement_builtins/builtins.c\
        exec/pipes/get_path.c \
        exec/pipes/piping.c\
        exec/pipes/utils.c\
        exec/implement_builtins/export//export_equal.c\

main = main/main.c

# Directories
OBJ_DIR := objects

#object files
main_obj                := $(patsubst %.c,$(OBJ_DIR)/%.o,$(main))
obj                             := $(patsubst %.c,$(OBJ_DIR)/%.o,$(src))

#NAMES
NAME :=  minishell
USER := $(USER)
cc = cc
CFLAGS          := -Wall -Werror -Wextra
incldlib        := -I/Users/${USER}/homebrew/opt/readline/include
libreadline     := -lreadline -L/Users/${USER}/homebrew/opt/readline/lib
libft           := libft/libft.a

all:$(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(cc) ${CFLAGS} -c $< -o $@

all: $(NAME)

$(NAME) : $(main_obj)  $(obj) $(libft)
	@ echo "Compiling MINISHELL "
	@ ${cc} $(CFLAGS) $(main_obj) $(obj) $(libft) ${CFLAGS} $(libreadline) $(DUBGGER) -o $(NAME)
	@ echo "\tDone.\n"

$(libft):
	@ make -s bonus --directory=libft

clean_libft:
	@ make clean -s  --directory=libft

clean : clean_libft
	@ echo "Removing object files ."
	@ rm -rf $(main_obj) $(Shell_obj) $(obj) $(mandatory_obj) $(bonus_obj) $(PROGRESSBINARY)
	@ echo "\tDone.\n"

fclean : clean clean_libft
	@ echo "Removing $(NAME) ."
	@ rm -rf $(NAME) $(libft) $(CHECKER) $(B_NAME)
	@ echo "\tDone.\n"

re : fclean all

.PHONY : clean flcean   clean_libft
