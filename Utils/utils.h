/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 10:31:09 by kmahdi            #+#    #+#             */
/*   Updated: 2023/04/17 03:52:59 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "../includes/minishell.h"

char	*m_safe_strjoin(char *s1, char *s2, int free_mode);
char	*random_string(int len);
int		is_equal(char *s, char *s2);
char	**append(char **Strings, char *String);
char	*get_relative_path(char *HOME, char *w_directory);
char	*get_prompt_text(void);
int		list_append(int **list, int new_pid, int size);
void	replace_b_slash(char *ptr);
char	*get_full_line(char *line);
int		get_exit_status(void);
void	set_exit_status(int status_val);
void	set_interrupted(int value);
int		is_interrupted(void);
char	*lower_case(char *command);
void	toggle_quteflag(char c, int *qute_flag);
#endif
