/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 05:13:18 by kmahdi            #+#    #+#             */
/*   Updated: 2023/04/16 07:41:03 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "export.h"

int	string_exists(char **export, int n, char *argument, int len)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (strncmp(export[i], argument, len) == 0
			&& is_equal_plus_str(argument) != 2)
			return (1);
		i++;
	}
	return (0);
}

char	**reset_forbidden_env(char **name)
{
	char	**env;

	env = name;
	while (name && *name)
	{
		if ((!ft_isalpha(*name[0]) || is_forbidden_char(*name)
				|| !is_equal_plus(*name)))
			remove_env(name);
		else
			name++;
	}
	return (env);
}

char	**reset(char **env, char **argument)
{
	char	**new_env;
	int		i;
	int		j;
	int		duplicate;

	i = 1;
	new_env = NULL;
	while (env && env[++i])
	{
		j = i + 1;
		duplicate = 0;
		while (env[j])
		{
			if (comparison(env[i], env[j])
				&& is_equal_plus_str(argument[i]) == 1)
			{
				duplicate = 1;
				break ;
			}
			j++;
		}
		if (!duplicate)
			new_env = append(new_env, strdup(env[i]));
	}
	return (new_env);
}

char	**remove_duplicate(char **export)
{
	char	**new_export;
	int		i;
	int		j;
	int		duplicate;

	i = 0;
	new_export = NULL;
	while (export && export[i])
	{
		j = i + 1;
		duplicate = 0;
		while (export && export[j])
		{
			if (comparison(export[i], export[j]))
			{
				duplicate = 1;
				break ;
			}
			j++;
		}
		if (!duplicate)
			new_export = append(new_export, ft_strdup(export[i]));
		i++;
	}
	return (new_export);
}

char	**remove_duplicate_old(char **export)
{
	char	**new_export;
	int		len;
	int		j;
	int		i;

	i = 0;
	new_export = export;
	while (export && export[i])
	{
		j = i + 1;
		len = get_start(export[i]);
		while (export && export[j])
		{
			if (comparison(export[i], export[j]))
				remove_env(export + i);
			else
				j++;
		}
		i++;
	}
	return (new_export);
}
