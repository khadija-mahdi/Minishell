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
void	unset(char **str, char **env);
void 	cd_command(m_node *node);
// void 	unset_command(m_node *node);
void	exec(t_list *list);
void 	pwd_command(m_node *node);
void	ft_swap(int *a, int *b);
// void 	export_only(m_node *node);
void	export_only(m_node *node, char	**old_export, char	**old_env);
long	long ft_my_atoi(const char *nptr);
void 	export_command(m_node *node);
void 	print_list(char **str);
int		f_isdigit(int c);
char	**get_new_export(char **env , char **str);
void	builtins(m_node *node);
void	pipe_exuc(m_node *node);
char 	*get_paths(char **env , char *command);
void	two_pipes(m_node *node);
int		is_builtins(m_node *node);
void	handle_signal();
void 	sigint_ctrl_C(int sig);
char 	**get_new_env(char **old_env , char **str);
void	sorted_list(char **export, int len);
void	unset_command(m_node *node , char **env);
char **unset_env(char **str , char **env);

# endif

