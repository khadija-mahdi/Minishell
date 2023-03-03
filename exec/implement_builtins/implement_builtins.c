/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   implement_builtins.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:27:03 by kmahdi            #+#    #+#             */
/*   Updated: 2023/03/03 18:56:29 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"


void unset_command(m_node *node)
{
	char **env;
	int len;
	int i;

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
					*env  = *env + 1;
					env++;
				}
				else
					i++;
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