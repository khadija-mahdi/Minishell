/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 00:38:44 by kmahdi            #+#    #+#             */
/*   Updated: 2023/04/17 02:00:03 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "export.h"

char	*shell_level(void)
{
	char		*lvl_sh;
	char		*str;

	str = ft_itoa(g__helper.sh_lvl);
	lvl_sh = NULL;
	if (g__helper.sh_lvl >= 1000)
		g__helper.sh_lvl = 1;
	lvl_sh = m_safe_strjoin("SHLVL=", str, 2);
	return (lvl_sh);
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
	while (old_env && old_env[++i])
		env[i] = ft_strdup(old_env[i]);
	k = 1;
	while (arguments && arguments[k])
	{
		if (arguments[k][0] == '#')
			break ;
		if ((!ft_isalpha(arguments[k][0]) || is_forbidden_char(arguments[k])
			|| !is_equal_plus(arguments[k])))
			k++;
		else if (is_equal_plus_str(arguments[k]) == 1)
			env[i++] = ft_strdup(arguments[k++]);
		else if (is_equal_plus_str(arguments[k]) == 2)
			env[i++] = add_plus_string(arguments[k++], 1);
		else
			k++;
	}
	env[i] = NULL;
}

char	**get_new_env(char **old_env, char **arguments)
{
	char	**env;
	char	**clean_env;

	env = NULL;
	if (old_env != NULL)
	{
		env = malloc((size(old_env) + size(arguments) + 1) * sizeof(char *));
		if (!env)
			exit(1);
		add_new_env(env, old_env, arguments);
	}
	clean_env = remove_duplicate(env);
	free_list(env);
	return (clean_env);
}

int	get_name_index(char *s1)
{
	int	i;

	i = 0;
	while (s1 && s1[i])
	{
		if (s1[i] == '+' || s1[i] == '=')
			return (i);
		i++;
	}
	return (-1);
}
