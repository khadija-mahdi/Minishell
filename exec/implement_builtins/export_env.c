/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 00:38:44 by kmahdi            #+#    #+#             */
/*   Updated: 2023/04/02 03:44:15 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

char	**get_name(char **argument)
{
	char	**name;
	int		start;
	int		i;
	int		j;

	i = 0;
	j = 0;
	name = NULL;
	if (argument[i])
	{
		name = malloc(size(argument) * sizeof(char *));
		while (argument[i])
		{
			start = 0;
			while (argument[i][start] != '=' && argument[i][start])
				start++;
			if (argument[i][start] == '=')
				start++;
			name[j] = ft_substr(argument[i], 0, start);
			i++;
			j++;
		}
		name[j] = NULL;
	}
	return (name);
}


int is_equal_plus(char *argument)
{
	int len;
	int index;

	len = 0;
	index = 0;
	while(argument && argument[len] && argument[len] != '=')
		len++;
	while(index < len)
	{
		if (argument[index] == '+')
		{
			if (argument[index + 1] == argument[len])
				return (1);
			return(0);
		}
		index++;
	}
	return (1);
}
int is_forbidden_char(char *argument)
{
	int len;
	int index;

	len = 0;
	index = 0;
	while(argument && argument[len] && argument[len] != '=')
		len++;
	while(index < len)
	{
		if(!ft_isalnum(argument[index]))
			return(1);
		index++;
	}
	return (0);
}

int is_value(char *argument)
{
	int i;
	
	i = 0;
	while (argument && argument[i])
	{
		if (argument[i] == '=')
			return (i);
		i++;
	}
	return (0);
}

char **reset_forbidden_env(char **name)
{
	char **env = name;
	while (name && *name)
	{
		if ((!ft_isalpha(*name[0]) || is_forbidden_char(*name) || !is_equal_plus(*name)))
			remove_env(name);
		else
			name++;
	}
	return (env);
	
}

char	**reset(char **env, char **argument)
{
	int		len;
	int		i;
	int		j;
	char	**temp;

	i = 0;
	j = 0;
	while (env && *env)
	{
	
		i = 0;
		while (argument && argument[i])
		{
			len = is_value(argument[i]);
			if (!ft_strncmp(*env, argument[i], len) && is_value(argument[i]))
				remove_env(env);
			else
				i++;
		}
		env++;
	}
	return (temp);
}

void	add_new_env(char **env, char **old_env, char **arguments)
{
	int	i;
	int	j;
	int	k;
	char **name = get_name(arguments);

	i = 0;
	k = 1;
	while (old_env && old_env[i])
	{
		env[i] = ft_strdup(old_env[i]);
		i++;
	}
	while (arguments && arguments[k])
	{
		if (arguments && arguments[k])
		{
			j = 0;
			while (arguments && arguments[k] && arguments[k][j])
			{
				if (arguments[k][j] == '=' && arguments[k][j- 1] != '+')
				{
					env[i++] = ft_strdup(arguments[k]);
					break ;
				}
				else if (arguments[k][j] == '=' && arguments[k][j - 1] == '+' && arguments[k][j - 1])
				{
					env[i++] = ft_strdup(add_plus_string(old_env, arguments[k], 1));
					break ;
				}
				j++;
			}
			k++;
		}
		else
			k++;
	}
	env[i] = NULL;
	// free_list(old_env);
}

char	**get_new_env(char **old_env, char **arguments)
{
	char	**env;

	if (old_env != NULL && !arguments[1])
		env = get_env(NULL);
	else if (old_env != NULL && arguments[1])
	{
		env = malloc((size(old_env) + size(arguments)) * sizeof(char *));
		add_new_env(env, old_env, arguments);
	}
	env = reset_forbidden_env(env);
	return (env);
}

int	get_start(char *argument)
{
	int	start;

	start = 0;
	while (argument && argument[start] && argument[start] != '=')
		start++;
	if (argument[start] == '=')
		start++;
	return (start);
}

char **remove_duplicate(char **export)
{
    int len;
	int j ;
	char **new_export;
	int index;

	
	int i = 0;
    while (export && export[i])
	{
		j = i + 1;
		len = get_start(export[i]);
        while (export && export[j])
		{
            if (ft_strncmp(export[i], export[j], len) == 0)
				remove_env(export + i);
			else
				j++;
        }
		
			i++;
    }
    return (new_export);
}


void	export_command(m_node *node, char	**old_export, char	**old_env)
{
	int		i;
	char	**export;
	char	**env;
	i = 0;

	if (node->arguments)
	{
		env = reset(old_env, node->arguments);
		export = reset(old_export, node->arguments);
	}
	env = get_new_env(old_env, node->arguments);
	export = get_new_export(old_export, node->arguments);
	export = remove_duplicate(export);
	env = remove_duplicate(env);
	if (export == NULL || export == NULL)
		exit_msg("env doesn't exist\n", 7);
	while (export && node->arguments&& export[i] && !node->arguments[1])
	{
		if (is_value(export[i]))
			printf("declare -x %s\n", add_quotes(export[i], 0));
		else
			printf("declare -x %s\n", export[i]);
		i++;
	}
	get_export(export);
	get_env(env);
}

