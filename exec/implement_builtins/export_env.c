/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 00:38:44 by kmahdi            #+#    #+#             */
/*   Updated: 2023/03/30 06:28:01 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"
int is_nbr_alpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||( c == '_' || c == '=' )|| (c >= '0' && c <= '9' ))
		return (1);
	return (0);
}
int is_equal_plus(char *str)
{
	int i;

	i = 1;
	while (str[i])
	{
		if (str[i] == '+')
		{
			printf("%c\n", str[i + 1]);
			if (str[i + 1] == '=' && is_nbr_alpha(str[i + 2]))
				return (1);
			return(0);
		}
		i++;
	}
	return (1);
}
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

int is_value(char *str)
{
	int i;
	
	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (i);
		i++;
	}
	return (0);
}

char	**reset(char **env, char **str)
{
	int		len;
	int		i;
	int		j;
	char	**temp;

	i = 0;
	j = 0;
	while (*env)
	{
	
		i = 0;
		while (str[i])
		{
			len = is_value(str[i]);
			if (!ft_strncmp(*env, str[i], len) && is_value(str[i]))
			{
				printf("removing %s ......>\n", *env);
				remove_env(env);
			}
			else
				i++;
		}
		env++;
	}
	// free(*env);
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
	while (str[k])
	{
		if (!ft_isalpha(str[k][0]) || is_forbiden_char(str[k]) || !is_equal_plus(str[k]))
			k++;
		else if (str[k])
		{
			j = 0;
			while (str[k][j])
			{
				if (str[k][j] == '=')
				{
					env[i++] = ft_strdup(str[k]);
					break ;
				}
				j++;
			}
			k++;
		}
	}
	env[i] = NULL;
	// free_list(old_env);
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

char **remove_duplicate(char **arguments)
{
    int len;
	char **new_arguments;
    int i;
	int	 j;
    int k;
	int index;
	
	len = 0;
    while (arguments[len]) 
        len++;
    	i = 0;
    while (i < len - 1)
	{
		j = i + 1;
        while (j < len)
		{
            if (ft_strcmp(arguments[i], arguments[j]) == 0)
			{
				k = j;
                while (k < len - 1)
				{
                    arguments[k] = arguments[k + 1];
					k++;
                }
             	len--;
                j--;
            }
			j++;
        }
		i++;
    }
    new_arguments = malloc((len+1) * sizeof(char*));
    index = 0;
    	i = 0;
    while (i < len)
	{
        if (arguments[i])
		{
            new_arguments[index] = arguments[i];
            index++;
        }
		i++;
    }
    new_arguments[len] = NULL;
    return new_arguments;
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
		exit_msg("env dosn't exict\n", 7);
	while (export[i] && !node->arguments[1])
		printf("declare -x %s\n", export[i++]);
	get_export(export);
	get_env(env);
	free_list (export);
	free_list (env);
}
