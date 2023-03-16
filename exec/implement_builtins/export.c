/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 22:31:49 by kmahdi            #+#    #+#             */
/*   Updated: 2023/03/16 03:51:25 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

void sorted_list(char **export, int len)
{
	char *temp;
	int i;
	int j;
	
	i = 0;
    while (i < len  - 1) 
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (strcmp(export[j], export[j + 1]) > 0) 
			{
				temp = export[j];
				export[j] = export[j + 1];
				export[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

char	**get_export(char **env)
{
	static char **export;
	int i = 0;
	if (env != NULL)
	{
		export = malloc((size(env) + 1) * sizeof(char *));
		while (env[i])
		{
			export[i] = ft_strdup(env[i]);
			i++;
		}
		export[i] = NULL;
	}
	sorted_list(export,size(env));
	return (export);
}

void export_only(m_node *node)
{
	
	if (ft_strcmp(node->command ,"export") == 0 && !node->arguments[1])
	{
		char **export;
		char **env;
		
		env = get_env(NULL);
		export = get_export(env);
		if (export == NULL)
			exit_msg("hiiii\n", 7);
		while(*export)
		{
			printf("declare -x %s\n", *export);
			export++;
		}
	}
}

void add_string(char **ptr, char *str, int len)
{
	char **new_ptr;
	int i;
	
    new_ptr = malloc((len + 1) * sizeof(char*));  // Allocate space for new pointer
	i = 0;
    while ( i < len)
	{
        new_ptr[i] = (*ptr)[i];  // Copy old strings
		i++;
    }
    new_ptr[len] = malloc(ft_strlen(str) + 1);  // Allocate space for new string
    strcpy(new_ptr[len], str);  // Copy new string
    free(*ptr);  // Free old pointer
    *ptr = new_ptr;  // Set new pointer
}

void export_command(m_node *node)
{
	if (ft_strcmp(node->command ,"export") == 0 && node->arguments[1])
	{
		char **env;
		char **export;
		char **new ;
		int i;
		
		int ac = size(node->arguments);
		int len_env = size(env);
		i = 1;

		env = get_env(NULL);
		len_env = size(env);
		char **ptr = malloc(ac * sizeof(char*));  // Allocate space for new arguments
		
		while(node->arguments[i])
		{
			add_string(&env, node->arguments[i], len_env);
			i++;
		}
		// if (ft_strcmp(node->command ,"export") == 0)
		// {
		// 	export = get_export(env);
		// 	if (!node->arguments[1])
		// 	{
		// 		while (*export)
		// 		{
		// 			printf("%s\n", *export);
		// 			export++;
		// 		}
		// 	}
					
		// }
	}
}

// void export_only(m_node *node)
// {
	
// }