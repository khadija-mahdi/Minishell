/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 22:31:49 by kmahdi            #+#    #+#             */
/*   Updated: 2023/03/19 09:04:54 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

void	add_new_export(char **export, char **old_export, char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (old_export[i])
	{
		export[i] = ft_strdup(old_export[i]);
		i++;
	}
	sorted_list(export, size(old_export));
	while (str[j])
		export[i++] = ft_strdup(str[j++]);
	export[i] = NULL;
}

char	**get_new_export(char **old_export, char **str)
{
	char	**export;

	if (old_export != NULL && !str[1])
	{
		export = get_export(NULL);
		sorted_list(export, size(old_export));
	}
	else if (old_export != NULL && str[1])
	{
		export = malloc((size(old_export) + size(str)) * sizeof(char *));
		add_new_export(export, old_export, str);
	}
	return (export);
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
		j = 0;
		while (str[k][j])
		{
			if (str[k][j] == '=')
			{
				env[i++] = ft_strdup(str[k]);
			}
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

int get_value_len(char **str)
{
	int	len;
	int i;

	i = 1;
	len = 0;
	while(str[i])
	{
		if(str[i][len] && str[i][len] != '=')
			len++;
		else
			i++;
	}
	return(len);
}

// void change_env_value(char **env, char **str)
// {
// 	int	i;
// 	int len;

// 	i = 1;
// 	len = get_value_len(str);

// 	while(*env)
// 	{
// 		printf("len ==> %d\n en[len] ===> %s\n str[i] ===> %s\n", len, (*env), str[i]);
// 		while(str[i])
// 		{
// 			if(!ft_strncmp(*env ,str[i], len) && (*env)[len + 1] == '=')
// 			{	
// 				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
				
// 			}
// 			else
// 				i++;
// 		}
// 		env++;
// 	}
// }

void	export_only(m_node *node, char	**old_export, char	**old_env)
{
	int		i;
	char	**export;
	char	**env;

	if (ft_strcmp(node->command, "export") == 0)
	{
		i = 0;
		env = get_new_env(old_env, node->arguments);
		export = get_new_export(old_export, node->arguments);
		if (export == NULL || export == NULL)
			exit_msg("env dosn't exict\n", 7);
		while (export[i] && !node->arguments[1])
		{
			printf("declare -x %s\n", export[i]);
			i++;
		}
		get_export(export);
		get_env(env);
		// change_env_value(env, node->arguments);
		// change_env_value(export, node->arguments);

		
	}
}
