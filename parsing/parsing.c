/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:32:28 by aaitouna          #+#    #+#             */
/*   Updated: 2023/04/17 03:53:40 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <stdio.h>
#include <unistd.h>

char	*splite_env_val(char *line, char *new_str, t_node *node, int *index)
{
	int		j;
	char	*env_value;
	char	**splited_env_val;
	int		max;

	env_value = NULL;
	j = 0;
	env_value = copy_variable_value(env_value, line, index);
	if (env_value != NULL)
	{
		splited_env_val = split_by_set(env_value, " \t");
		max = size(splited_env_val);
		while (j < max - 1)
		{
			add_arg_t_node(node, m_safe_strjoin(new_str,
					ft_strdup(splited_env_val[j]), 3));
			free(new_str);
			new_str = NULL;
			j++;
		}
		new_str = m_safe_strjoin(new_str, ft_strdup(splited_env_val[j]), 3);
		free_list(splited_env_val);
		free(env_value);
	}
	return (new_str);
}

void	parse(char *line, t_list **list)
{
	int		i;
	t_node	*node;

	if (line == NULL)
		return ;
	node = new_t_node();
	i = 0;
	while (line[i] && line[i] != '|')
	{
		if (is_n_escaped(line, '<', i))
			node->input_file = open_input_file(line, &i,
					node->output_file, node->input_file);
		else if (is_n_escaped(line, '>', i))
			node->output_file = open_output_file(line, &i,
					node->input_file, node->output_file);
		else
			get_input_value(&line[i], node, &i, 0);
	}
	ft_lstadd_back(list, ft_lstnew(node));
	if (line[i] && line[i] == '|')
		parse(&line[++i], list);
}

int	exit_if_null(char *line, t_list **list)
{
	if (!line)
	{
		printf("exit\n");
		clear_resources(line, list);
		return (1);
	}
	return (0);
}

void	tty(void)
{
	char	*line;
	t_list	*list;
	char	*default_prompt;

	list = NULL;
	line = NULL;
	while (1)
	{
		default_prompt = get_prompt_text();
		line = readline(default_prompt);
		free(default_prompt);
		set_interrupted(0);
		if (exit_if_null(line, &list))
			break ;
		if (handle_syntax(line))
		{
			clear_resources(line, &list);
			continue ;
		}
		line = get_full_line(line);
		if (exit_if_null(line, &list))
			break ;
		run_mini(line, &list);
	}
}
