/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 22:43:41 by kmahdi            #+#    #+#             */
/*   Updated: 2023/03/23 20:47:21 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

char **update_env(char **env)
{
	char	*old_pwd;
	int		i;
	char **new_env;

	old_pwd = change_env(env);
	if (env != NULL && old_pwd != NULL)
	{
		// printf("old -- > %s\n", old_pwd);
		new_env = malloc((size(env) + 2 ) * sizeof(char *));
		i = 0;
		while (env[i])
		{
			new_env[i] = ft_strdup(env[i]);
			i++;
		}
		new_env[i] = ft_strdup(old_pwd);
		new_env[++i] = NULL;
	}
	return(new_env);
}

void update(char **env)
{
	char **new_env;
	
	new_env = update_env(env);
	get_env(new_env);
	get_export(new_env);
	
}

void	env_command(m_node *node)
{
	char	**env;
	int		i;

	i = 0;
	if (ft_strcmp(node->command, "env") == 0)
	{
		env = get_env(NULL);
		if (env == NULL)
			printf("hiiii\n");
		if (!node->arguments[1])
		{
			i = 0;
			while (env[i])
				printf("%s\n", env[i++]);
		}	
		else
			printf("env: %s: No such file or directory\n", node->arguments[1]);
	}
}
