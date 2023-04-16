/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:10:46 by aaitouna          #+#    #+#             */
/*   Updated: 2023/04/14 09:51:14 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_str_append(char *s, char c)
{
	int		i;
	int		len;
	char	*new_str;

	i = 0;
	len = ft_strlen(s);
	new_str = malloc((len + 3) * sizeof(char));
	if (!new_str)
		exit (0);
	while (i < len)
	{
		new_str[i] = s[i];
		i++;
	}
	new_str[i++] = c;
	new_str[i] = 0;
	if (s != NULL)
		free(s);
	return (new_str);
}

char	*concate_str(char *s, char *str, int flag, int *index)
{
	if (s[0] == '\\')
	{
		if (flag == 1)
			str = ft_str_append(str, s[0]);
		else if (flag == 2 && ft_strchr(">\"\\\'$", s[1]))
			str = ft_str_append(str, s[1]);
		else if (flag == 2 && !ft_strchr(">\"\\\'$", s[1]))
			str = ft_str_append(str, s[0]);
		else if (flag == 0 && ft_strchr(">\"\\\'$", s[1]))
			str = ft_str_append(str, s[1]);
		if (s[1] && ft_strchr(">\"\\\'$", s[1]) && flag != 1)
			(*index)++;
	}
	else if (s[0] == '\n')
	{
		if (flag == 1)
			str = ft_str_append(str, s[0]);
	}
	else
		str = ft_str_append(str, s[0]);
	return (str);
}

int	handle_expanding(t_cp_flags *cp_flags, char **new_str,
		t_node *node, char *s)
{
	char	*env_value;

	env_value = NULL;
	if (*cp_flags->qute_flag == 0 && cp_flags->mode == 0)
		*new_str = splite_env_val(s, *new_str, node, cp_flags->index);
	else
	{
		env_value = NULL;
		env_value = copy_variable_value(env_value, s, cp_flags->index);
		if (*cp_flags->qute_flag == 2 && env_value == NULL)
			env_value = ft_str_append(env_value, 0);
		if (env_value != NULL)
		{
			if (size_of_env_parts(env_value) > 1
				&& *cp_flags->qute_flag == 0)
				return (on_error_clear(cp_flags, env_value,
						*new_str, cp_flags->index));
			*new_str = m_safe_strjoin(*new_str, env_value, 3);
		}
		reset_qute_flag(cp_flags, s);
	}
	free(cp_flags);
	return (0);
}

char	*copy_string_t_args(char *s, t_node *node, int *index, int mode)
{
	int		qute_flag;
	char	*new_str;

	qute_flag = 0;
	new_str = NULL;
	while (s[*index] != 0 && (is_token_sep(s, *index) || qute_flag))
	{
		if (toggle_flag(s[*index], &qute_flag, index))
		{
			if (qute_flag != 0 && mode == 1)
				new_str = ft_str_append(new_str, 0);
			continue ;
		}
		if (is_n_escaped(s, '$', *index) && qute_flag != 1 && mode != 2)
		{
			if (handle_expanding(init_flags(mode, &qute_flag, index),
					&new_str, node, s) == -1)
				return (NULL);
		}
		else
			new_str = concate_str(&s[*index], new_str, qute_flag, index);
		(*index)++;
	}
	return (return_value(mode, node, new_str));
}
