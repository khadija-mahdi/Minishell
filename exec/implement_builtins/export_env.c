/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 00:38:44 by kmahdi            #+#    #+#             */
/*   Updated: 2023/03/23 23:47:29 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

int is_forbiden_char(char *str)
{
	int i = 1;
	while(str[i])
	{
		if(!ft_isalnum(str[i]))
			return(1);
		i++;
	}
	return (0);
}

char	**reset(char **str, char **env)
{
	int		len;
	int		i;
	char	**temp;

	i = 0;
	while (*env)
	{
		i = 0;
		while (str[i])
		{
			len = ft_strlen(str[i]);
			if (!ft_strncmp(*env, str[i], len) && (*env)[len - 1] == '=' )
				remove_env(env);
			else
				i++;
		}
		env++;
	}
	return (temp);
}

void	add_new_env(char **env, char **old_env, char **str)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 1;
	while (old_env[i])
	{
		env[i] = ft_strdup(old_env[i]);
		i++;
	}
	while (str[k] && (!ft_isalpha(str[k][0]) || is_forbiden_char(str[k])))
		k++;
	while (str[k])
	{
		j = 0;
		while (str[k][j])
		{
			if (str[k][j] == '=')
				env[i++] = ft_strdup(str[k]);
			j++;
		}
		k++;
	}
	env[i] = NULL;
}

char	**get_new_env(char **old_env, char **str)
{
	char	**env;

	if (old_env != NULL && !str[1])
		env = get_env(NULL);
	else if (old_env != NULL && str[1])
	{
		env = malloc((size(old_env) + size(str)) * sizeof(char *));
		add_new_env(env, old_env, str);
	}
	return (env);
}

void	export_command(m_node *node, char	**old_export, char	**old_env)
{
	int		i;
	char	**export;
	char	**env;
	char	**name;

	if (ft_strcmp(node->command, "export") == 0)
	{
		i = 0;
		name = get_name(node->arguments);
		if (name)
		{
			env = reset(name, old_env);
			export = reset(name, old_export);
		}
		env = get_new_env(old_env, node->arguments);
		export = get_new_export(old_export, node->arguments);
		if (export == NULL || export == NULL)
			exit_msg("env dosn't exict\n", 7);
		while (export[i] && !node->arguments[1])
			printf("declare -x %s\n", export[i++]);
		get_export(export);
		get_env(env);
	}
}
