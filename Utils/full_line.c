/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:53:29 by aaitouna          #+#    #+#             */
/*   Updated: 2023/04/17 03:52:52 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils.h"

void	replace_b_slash(char *ptr)
{
	int	i;

	i = ft_strlen(ptr);
	while (i >= 0 && ptr[i] != '\\' && ptr[i] != '|')
		i--;
	if (is_n_escaped(ptr, '\\', i))
		ptr[i] = 0;
}

char	*get_full_line(char *line)
{
	char	*temp;
	char	*new_line;

	while (!is_complete(line))
	{
		replace_b_slash(line);
		new_line = readline(">");
		if (!new_line)
		{
			return (NULL);
		}
		temp = ft_strjoin(line, new_line);
		free(line);
		free(new_line);
		line = temp;
	}
	return (line);
}

void	syntax_err_print(char *msg, char near, int status)
{
	if (near != 0)
	{
		msg = ft_str_append(msg, '`');
		msg = ft_str_append(msg, near);
		msg = ft_str_append(msg, '`');
	}
	msg = ft_str_append(msg, '\n');
	write(2, msg, ft_strlen(msg));
	set_exit_status(status);
	free(msg);
}

void	toggle_quteflag(char c, int *qute_flag)
{
	if (c == '"' && *qute_flag == 0)
		*qute_flag = 2;
	else if (c == '\'' && *qute_flag == 0)
		*qute_flag = 1;
	else if ((c == '\'' && *qute_flag == 1) || (c == '"' && *qute_flag == 2))
		*qute_flag = 0;
}
