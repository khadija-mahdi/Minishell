/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 00:38:44 by kmahdi            #+#    #+#             */
/*   Updated: 2023/04/07 08:20:35 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "export.h"

char	**the_new_env(char **env, m_node *node)
{	
	char	*new_under;
	char	**new_env;
	char	*sh_lvl;
	char	*pwd;
	int		i;

	new_under = get_underscore(env, node);
	sh_lvl = shell_level(node, env);
	pwd = pwd_env(env);
	i = 0;
	new_env = malloc((size(env) + 4) * sizeof(char *));
	while (env[i])
	{
		new_env[i] = ft_strdup(env[i]);
		i++;
	}
	new_env[i] = ft_strdup(sh_lvl);
	new_env[++i] = ft_strdup(new_under);
	new_env[++i] = ft_strdup(pwd);
	new_env[++i] = NULL;
	free(new_under);
	return (new_env);
}

int	is_equal_plus_str(char *arg)
{
	int	i;

	i = 0;
	while (arg && arg[i])
	{
		if (arg[i] == '=' && arg[i - 1] != '+')
			return (1);
		else if (arg[i] == '=' && arg[i - 1] == '+')
			return (2);
		i++;
	}
	return (0);
}

void	add_new_env(char **env, char **old_env, char **arguments)
{
	int	i;
	int	k;

	i = -1;
	k = 1;
	while (old_env && old_env[++i])
		env[i] = ft_strdup(old_env[i]);
	while (arguments && arguments[k])
	{
		if (arguments[k][0] == '#')
			break ;
		if (is_equal_plus_str(arguments[k]) == 1)
			env[i++] = ft_strdup(arguments[k]);
		else if (is_equal_plus_str(arguments[k]) == 2)
			env[i++] = ft_strdup(add_plus_string(old_env, arguments[k]));
		k++;
	}
	env[i] = NULL;
}

char	**get_new_env(char **old_env, char **arguments)
{
	char	**env;

	env = NULL;
	if (old_env != NULL && !arguments[1])
		env = get_env(NULL);
	else if (old_env != NULL)
	{
		env = malloc((size(old_env) + size(arguments)) * sizeof(char *));
		add_new_env(env, old_env, arguments);
	}
	env = reset_forbidden_env(env);
	env = remove_duplicate(env);
	return (env);
}
