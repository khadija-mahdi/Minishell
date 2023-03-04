#ifndef EXEC_H
# define EXEC_H

#include "../minishell.h"
# include <curses.h>
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <termcap.h>
# include <termios.h>
# include <unistd.h>

int 	ft_strcmp(char *s1, char *s2);
void	exit_msg(char *msg, int i);
void	exit_command(m_node *node);
void	env_command(m_node *node);
void 	echo_command(m_node *node);
void 	cd_command(m_node *node);
void 	unset_command(m_node *node);
void	exec(t_list *list);
void 	pwd_command(m_node *node);
void	ft_swap(int *a, int *b);
void export_command(m_node *node);
void print_list(char **str);


# endif