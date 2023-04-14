/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:32:21 by aaitouna          #+#    #+#             */
/*   Updated: 2023/04/13 10:20:26 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "syntax.h"

int	find_file_name(char *ptr)
{
	int	i;

	i = 0;
	while (ptr[i] && ptr[i] == ' ')
	{
		i++;
	}
	if (ptr[i] == 0)
		return (0);
	else if (ft_strchr(">;|<\n", ptr[i]))
		return (ptr[i]);
	return (-1);
}

char	check_redirections_syntax(char *line)
{
	int	i;
	int	val;

	i = 0;
	val = -1;
	if (is_n_escaped(line, '>', i))
	{
		if (is_n_escaped(line, '>', i + 1))
			i++;
		if (ft_strchr(">;|<\n", line[i + 1]) || line[i + 1] == 0)
			return (line[i]);
		val = find_file_name(&line[i + 1]);
	}
	if (is_n_escaped(line, '<', i))
	{
		if (is_n_escaped(line, '<', i + 1))
			i++;
		else if (is_n_escaped(line, '>', i + 1))
			i++;
		if (ft_strchr(">;|<\n", line[i + 1]) || line[i + 1] == 0)
			return (line[i + 1]);
		val = find_file_name(&line[i + 1]);
	}
	return (val);
}

char	check_syntax(char *line, int *pos)
{
	int		pipe_flag;
	char	element_err;
	int		i;
	int		qute_flag;

	i = 0;
	qute_flag = 0;
	pipe_flag = 0;
	i += spaces_count(line);
	if (line[i] == '|' || line[i] == ';')
		return (line[i]);
	while (line[i])
	{
		*pos = i;
		if (toggle_flag(line[i], &qute_flag, &i))
			continue ;
		update_pipe(&pipe_flag, line, qute_flag, i);
		if (pipe_flag == 2)
			return (line[i]);
		element_err = check_redirections_syntax(&line[i]);
		if (!qute_flag && element_err != -1)
			return (element_err);
		i++;
	}
	return (type(qute_flag, pos));
}

int	syntax_here_doc(int flag, char *limiter)
{
	int		fd;
	int		pid;
	char	*file_name;

	file_name = open_tmp_file(&fd);
	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, here_doc_signal);
		handle_here_doc(fd, limiter, flag);
	}
	close(fd);
	signal(SIGINT, SIG_IGN);
	free(limiter);
	free(file_name);
	return (pid);
}

void	manage_here_doc(char *line, int pos)
{
	int	i;
	int	status;
	int	canceled;
	int	pid;

	canceled = 0;
	if (line == NULL)
		return ;
	i = 0;
	while (i < pos)
	{
		if (is_n_escaped(line, '<', i)
			&& is_n_escaped(line, '<', i + 1) && !canceled)
		{
			i += 2;
			pid = syntax_here_doc(is_between_qute(&line[i]),
					get_input_value(&line[i], NULL, &i, 2));
			waitpid(pid, &status, 0);
			if (WEXITSTATUS(status) != 0 && WEXITSTATUS(status) == M_SIG_INT)
				canceled = 1;
		}
		else
			i++;
	}
	signal(SIGINT, handle_sigint);
}
