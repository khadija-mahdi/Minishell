/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 22:43:41 by kmahdi            #+#    #+#             */
/*   Updated: 2023/04/17 00:05:49 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

char	**remove_var(char **env, char *var)
{
	char	**new_env;
	int		i;

	i = -1;
	new_env = NULL;
	while (env && env[++i])
	{
		if (ft_strncmp(env[i], var, ft_strlen(var)))
			new_env = append(new_env, ft_strdup(env[i]));
	}
	return (new_env);
}

char	**change_old_pwd(char **env, char **new_env, char *old_pwd, char *pwd)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = remove_var(env, "OLDPWD");
	env = tmp;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PWD", 2))
		{
			new_env[i] = ft_strdup(pwd);
			if (pwd)
				free(pwd);
		}
		else
			new_env[i] = ft_strdup(env[i]);
		i++;
	}
	new_env[i] = ft_strdup(old_pwd);
	new_env[++i] = NULL;
	free(old_pwd);
	free_list(env);
	return (new_env);
}

char	**update_env(char **env)
{
	char	*old_pwd;
	char	*pwd;
	char	*n_pwd;
	char	**new_env;

	new_env = NULL;
	old_pwd = change_env(env);
	n_pwd = getcwd(NULL, 0);
	pwd = ft_strjoin("PWD=", n_pwd);
	if (old_pwd || pwd)
	{
		new_env = malloc((size(env) + 2) * sizeof(char *));
		if (!new_env)
			exit(1);
		new_env = change_old_pwd(env, new_env, pwd, old_pwd);
	}
	free(n_pwd);
	return (new_env);
}

void	update(char **env)
{
	char	**new_env;

	new_env = update_env(env);
	free_list(get_env(NULL));
	free_list(get_export(NULL));
	get_env(new_env);
	get_export(new_env);
	free_list(new_env);
}

void	env_command(t_node *node, char **env)
{
	int		i;

	i = 0;
	env = underscore_value(env, node);
	env = remove_duplicate(env);
	get_env (env);
	if (env == NULL)
		perror("env");
	if (!node->arguments[1])
	{
		while (env && env[i] && is_value(env[i]))
			printf("%s\n", env[i++]);
	}
	else
		printf("env: %s: No such file or directory\n", node->arguments[1]);
}
