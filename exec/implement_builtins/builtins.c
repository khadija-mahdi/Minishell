/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:53:24 by kmahdi            #+#    #+#             */
/*   Updated: 2023/04/15 09:54:11 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

void	print_export(char **export, char **new_args)
{
	char	*value;
	int		i;

	i = 0;
	while (export && export[i] && !new_args[1])
	{
		if (is_value(export[i]) && !is_underscore(export))
		{
			value = add_quotes(export[i], 0);
			printf("declare -x %s\n", value);
			free(value);
		}
		else
			printf("declare -x %s\n", export[i]);
		i++;
	}
}

char	**underscore_value(char **env, t_node *node)
{
	char	*new_value;
	char	**new_env;
	int		i;

	i = 0;
	new_env = NULL;
	new_value = get_underscore(env, node->arguments);
	while (env[i])
		new_env = append(new_env, ft_strdup(env[i++]));
	new_env = append(new_env, ft_strdup(new_value));
	free(new_value);
	return (new_env);
}

void	builtins(t_node *node)
{
	char	**env;
	char	**export;

	export = get_export(NULL);
	env = get_env(NULL);
	if (!strcmp(node->command, "exit") || !strcmp(node->command, "EXIT"))
		exit_command(node);
	if (!ft_strcmp(node->command, "cd") || !ft_strcmp(node->command, "CD"))
		cd_command(node);
	if (!ft_strcmp(node->command, "export")
		|| !ft_strcmp(node->command, "EXPORT"))
		export_command(node, export, env);
	if (!ft_strcmp(node->command, "unset")
		|| !ft_strcmp(node->command, "UNSET"))
		unset_command(node, env);
}

void	child_builtins(t_node *node)
{
	char	**export;
	char	**new_args;
	char	**env;

	new_args = get_new_arguments(node->arguments);
	export = get_export(NULL);
	env = get_env(NULL);
	if (!ft_strcmp(node->command, "export")
		|| !ft_strcmp(node->command, "EXPORT"))
		print_export(export, new_args);
	if (!ft_strcmp(node->command, "echo") || !ft_strcmp(node->command, "ECHO"))
		echo_command(node);
	if (!ft_strcmp(node->command, "env") || !ft_strcmp(node->command, "ENV"))
		env_command(node, env);
	if (!ft_strcmp(node->command, "pwd") || !ft_strcmp(node->command, "PWD"))
		pwd_command();
}
