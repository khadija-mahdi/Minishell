/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   implement_builtins.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadija-mahdi <khadija-mahdi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:27:03 by kmahdi            #+#    #+#             */
/*   Updated: 2023/03/03 22:44:44 by khadija-mah      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

void unset_command(m_node *node)
{
	char **env;
	int len;
	int i;
	char **va_unset;

	env = get_env(NULL);
	if (ft_strcmp(node->command ,"unset") == 0)
	{
		while(*env)
		{
			i = 1;
			while (ft_strncmp(*env, node->arguments[i], ft_strlen(*env)) == 0)
			{
				printf("unset: '%s' : not a valid identifier\n" ,node->arguments[i]);
				i++;
			}
			while(node->arguments[i])
			{
				if(!ft_strncmp(*env ,node->arguments[i], ft_strlen(node->arguments[i])) && (*env)[ft_strlen(node->arguments[i])] == '=')
				{	
					va_unset = env + 1;
					while(*va_unset)
					{
						*(va_unset - 1)  = *va_unset;
						va_unset++;
					}
				}
				else
					i++;
				*(va_unset - 1) = NULL;
				
			}
			env++;
		}
	}
}

char **get_export(char **env, int len) 
{
    int i;
	int j;
    char *temp;
	char **export;

	i = 0;
    while (i < len - 1) 
	{
		j = 0;
		while (j < len - i - 1)
		{
            if (strcmp(env[j], env[j + 1]) > 0) {
                temp = env[j];
                env[j] = env[j + 1];
                env[j + 1] = temp;
            }
			j++;
		}
		i++;
    }
	export = env;
	return (export);
}


void export_command(m_node *node)
{
	char **env;
	int len;
	char **export;
	char *name;
	char *value;
	int start = 0;
	char **new_env;
	int i = 0;

	len = 0;
	env = get_env(NULL);
    while (env[len])
        len++;
	export = get_export(env, len);
	if (ft_strcmp(node->command ,"export") == 0)
	{
		if(!node->arguments[1])
		{
			while(*export)
			{
				printf("%s\n", *export);
				export++;
			}
		}
		else
		{
			while (node->arguments[1][start] != '=' && node->arguments[1][start])
				start++;
			
			name = ft_substr(node->arguments[1], 0, start);
			value = ft_substr(node->arguments[1] , start , ft_strlen(node->arguments[1]));
			// printf("name --> %s value ---> %s\n" ,name , value);
			if(ft_strcmp(node->arguments[1], "=")== 0)
			{
				new_env = malloc((len + 2) * sizeof(char *));
				while(i < len)
				{
					new_env[i] = env[i];
					i++;
				}
				new_env[len] = node->arguments[1];
    			new_env[len + 1] = NULL;
				env = new_env;
				free_list(new_env);
			}
		}	
	}

}


void	exec(t_list *list)
{
	char **env;
	int len;

	env = get_env(NULL);
	
	if (list == NULL)
		return ;
	m_node *node = (m_node *)list->content;
	if (!node)
		return ;
	if(!node->command || !node->arguments[0])
		return ;
	exit_command(node);
	unset_command(node);
	env_command(node);
	export_command(node);
	echo_command(node);
	pwd_command(node);
	cd_command(node);
}