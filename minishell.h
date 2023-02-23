/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:51:52 by kmahdi            #+#    #+#             */
/*   Updated: 2023/02/22 18:44:09 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

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

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 434
# endif

// typedef struct s_data{

// }				t_data;

char	*get_next_line(int fd);
int		ft_printf(const char *format, ...);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, int start, int len);
char	*ft_strdup(const char *s1);
int		ft_strcmp(char *s1, char *s2);
void	exit_msg(char *msg, int i);
void	free_list(char **list);
char	*ft_strnstr(const char *haystack, const char *needle, int len);
void	path(char *paths, char **full_path, char *av);
char *get_command_path(char *input, char **env);
char *get_path(char **env, char *input);
void pwd_command(char *input);

#endif
