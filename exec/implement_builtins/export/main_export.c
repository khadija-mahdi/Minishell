/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 02:13:06 by kmahdi            #+#    #+#             */
/*   Updated: 2023/04/17 03:04:54 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "export.h"

int	add_or_replace(char **arguments, char **new_arg, int j, int i)
{
	int	been_added;

	been_added = 0;
	while (new_arg && new_arg[j])
	{
		if (is_equal_plus_str(arguments[i]) == 2)
		{	
			if (len_comparison(arguments[i], new_arg[j]))
			{
				new_arg[j] = join_values(new_arg[j], arguments[i]);
				been_added = 1;
			}
		}
		else if (len_comparison(arguments[i], new_arg[j])
			&& is_equal_plus_str(arguments[i]) == 1)
		{
			if (new_arg[j])
				free(new_arg[j]);
			new_arg[j] = ft_strdup(arguments[i]);
			been_added = 1;
		}
		j++;
	}
	return (been_added);
}

char	**get_new_arguments(char **arguments)
{
	char	**new_arg;
	int		i;
	int		j;
	int		been_added;

	new_arg = NULL;
	i = 0;
	while (arguments && arguments[i])
	{
		j = 0;
		been_added = add_or_replace(arguments, new_arg, j, i);
		if (!been_added)
			new_arg = append(new_arg, ft_strdup(arguments[i]));
		i++;
	}
	return (new_arg);
}

char	*join_values(char *s1, char *s2)
{
	char	*re;
	int		j;

	re = NULL;
	j = get_start(s1);
	while (s1 && s1[j])
		re = ft_str_append(re, s1[j++]);
	j = get_start(s2);
	while (s2 && s2[j])
		re = ft_str_append(re, s2[j++]);
	re = m_safe_strjoin(ft_substr(s1, 0, get_start(s1)), re, 3);
	free(s1);
	return (re);
}

void	export_environment(char **export, char **new_args)
{
	char	**tmp;

	tmp = get_new_export(export, new_args);
	free_list(export);
	export = tmp;
	sorted_list(export, size(export));
	get_export(export);
	free_list(export);
}

void	export_command(t_node *node)
{
	char	**export;
	char	**env;
	char	**tmp;
	char	**new_args;

	export = get_export(NULL);
	env = get_env(NULL);
	new_args = get_new_arguments(node->arguments);
	export_environment(export, new_args);
	tmp = get_new_env(env, new_args);
	free_list(env);
	env = tmp;
	free_list(new_args);
	get_env(env);
	free_list (env);
}
