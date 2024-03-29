/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   underscore_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 01:21:20 by kmahdi            #+#    #+#             */
/*   Updated: 2023/04/16 07:40:27 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "export.h"

void	underscore_export(char **export)
{
	while (export && *export)
	{
		if (!ft_strncmp(*export, "_=", 2))
			remove_env(export);
		else
			export++;
	}
}

int	is_high_shlvl(char **env)
{
	char		*shell_lvl;
	char		*shlvl_value;
	static int	len = 1;
	int			i;

	i = 0;
	shell_lvl = NULL;
	while (env && env[i])
	{
		if (!ft_strncmp(env[i], "SHLVL", 5))
		{
			shell_lvl = ft_strdup(env[i]);
			break ;
		}
		i++;
	}
	if (shell_lvl)
		i = get_start(shell_lvl);
	shlvl_value = ft_substr(shell_lvl, i, ft_strlen(shell_lvl));
	len = ft_atoi(shlvl_value);
	printf("len %d %s \n ", len, shell_lvl);
	free (shell_lvl);
	free (shlvl_value);
	return (len);
}

char	*get_underscore(char **export, char **arguments)
{
	char	*new_under;
	char	*path;
	int		len;

	len = size(arguments);
	path = get_paths(export, arguments[len - 1]);
	new_under = NULL;
	remove_ptr(export, "_=");
	if (path)
		new_under = ft_strjoin("_=", path);
	else
		new_under = ft_strjoin("_=", arguments[len - 1]);
	if (path)
		free(path);
	return (new_under);
}

char	*change_env(char **env)
{
	char	*pwd;
	char	*old_pwd;
	int		is_exist;

	old_pwd = NULL;
	is_exist = -1;
	while (env && *env)
	{
		if (!ft_strncmp(*env, "PWD", 3))
		{
			pwd = *env;
			is_exist = 0;
		}
		env++;
	}
	if (!is_exist)
		old_pwd = ft_strjoin("OLD", pwd);
	else if (is_exist == -1)
		old_pwd = ft_strdup("OLDPWD=");
	return (old_pwd);
}

int	is_underscore(char **export)
{
	while (export && *export)
	{
		if (!ft_strncmp(*export, "_=", 2))
			return (1);
		else
			export++;
	}
	return (0);
}
