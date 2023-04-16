/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:49:48 by kmahdi            #+#    #+#             */
/*   Updated: 2023/04/16 06:38:20 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

int	is_forbidden_unset(char *str)
{
	int	index;

	index = 1;
	while (str[index])
	{
		if (!ft_is_alnum(str[index]))
			return (1);
		index++;
	}
	return (0);
}

char	**unset_arguments(char **env, char **str)
{
	char	**new_env;
	int		i;
	int		j;
	int		duplicate;

	i = -1;
	new_env = NULL;
	while (env && env[++i])
	{
		j = 1;
		duplicate = 0;
		while (str && str[j])
		{
			if ((!ft_strncmp(env[i], str[j], ft_strlen(str[j]))
					&& env[i][ft_strlen(str[j])] == '='))
			{
				duplicate = 1;
				break ;
			}
			j++;
		}
		if (!duplicate)
			new_env = append(new_env, ft_strdup(env[i]));
	}
	return (new_env);
}

char	**unset_env(char **env, char **str)
{
	char	**tmp;
	int		i;

	i = 1;
	while (str && str[i])
	{
		if ((str && str[i]) && (!ft_isalpha(str[i][0])
			|| (is_forbidden_unset(str[i]))))
			printf("unset: '%s' : not a valid identifier\n", str[i]);
		i++;
	}
	tmp = unset_arguments(env, str);
	free_list(env);
	return (tmp);
}

void	unset_command(t_node *node, char **env)
{
	char	**new_env;

	free_list(get_export(NULL));
	new_env = unset_env(env, node->arguments);
	get_env(new_env);
	get_export(new_env);
	free_list(new_env);
}
