/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:28:00 by aaitouna          #+#    #+#             */
/*   Updated: 2023/04/17 03:53:25 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../includes/minishell.h"
# include "../includes/types.h"

char		*get_path(void);
char		*get_fullpath(char *s);
void		print_working_directory(void);
void		rl_replace_line(const char *s, int i);
void		here_doc_signal(int sig);
void		handle_sigint_n_chld(int sig);
t_node		*new_t_node(void);
void		printf_list(t_list *list);
char		*get_env_name(char *s, int *index);
char		*update_command(char *command);
int			handle_syntax(char *line);
int			is_child_builtins(char *s, char *arg);
int			is_builtin(char *s, char *arg);
int			open_input_file(char *line, int *i, int output, int input);
int			open_output_file(char *line, int *i, int input, int output);
void		toggle_quteflag(char c, int *qute_flag);
int			toggle_flag(char c, int *qute_flag, int *index);
char		*ft_str_append(char *s, char c);
int			here_doc(int flag, char *limiter);
void		handle_here_doc(int fd, char *limiter, int flag);
int			list_append(int **list, int new_pid, int size);
void		parse(char *line, t_list **list);
void		tty(void);
int			is_qute(char *s, int i);
int			is_n_escaped(char *s, char c, int i);
int			is_between_qute(char *line);
int			is_complete(char *line);
char		*copy_variable_value(char *dst, char *src, int *index);
char		*mini_strjoin(char const *s1, char const *s2);
int			is_token_sep(char *c, int i);
char		*concate_str(char *s, char *str, int flag, int *index);
char		*splite_env_val(char *line, char *new_str,
				t_node *node, int *index);
void		add_arg_t_node(t_node *node, char *str);
char		*get_input_value(char *s, t_node *node, int *index, int mode);
char		*copy_string_t_args(char *s, t_node *node, int *index, int mode);
int			spaces_count(char *s);
size_t		string_list_len(char **list);
char		*open_tmp_file(int *fd);
char		**split_by_set(char const *s, char *set);
char		*return_value(int mode, t_node *node, char *new_str);
t_cp_flags	*init_flags(int mode, int *qute_flag, int *index_ptr);
int			size_of_env_parts(char *env_value);
int			on_error_clear(t_cp_flags *cp_flags, char *env_value, char *new_str,
				int *index);
void		reset_qute_flag(t_cp_flags *cp_flags, char *s);
int			return_fd(char *file_name);
void		run_mini(char *line, t_list **list);
void		clear_resources(char *line, t_list **list);
void		run_commands(t_list *list);
int			exit_if_null(char *line, t_list **list);
void		syntax_err_print(char *msg, char near, int status);
#endif
