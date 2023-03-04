/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   implement_builtins.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:27:03 by kmahdi            #+#    #+#             */
/*   Updated: 2023/03/04 16:46:53 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

 void add_export_var(m_node *node, char ac , int len, char **export)
 {
	int i;

	i = 1;
	if(ac == 1)
	{
		export[len] = NULL;

	}
	else
	{
		while(i < ac)
		{
			export[len] = node->arguments[i];
			i++;
			len++;
		}
		export[len] = NULL;
	}
	if (ft_strcmp(node->command ,"export") == 0)
	{
		while(*export)
		{
			printf("%s\n", *export);
			export++;
		}
	}
 }


void sorted_list(char **export, int j)
{
	char *temp;
	if (strcmp(export[j], export[j + 1]) > 0) 
	{
        temp = export[j];
        export[j] = export[j + 1];
        export[j + 1] = temp;
    }
}
char **get_export(m_node *node, char **env, int len, int ac) 
{
    int i;
	int j;
    char *temp;
	char **export;

	export =  malloc((len + ac + 1) * sizeof(char *));
	i = 0;
	while(i < len)
	{
		export[i] = env[i];
		i++;
	}
	i = 0;
    while (i < (len + ac) - 1) 
	{
		j = 0;
		while (j < len - i - 1)
		{
            sorted_list(export, j);
			j++;
		}
		i++;
    }
	add_export_var(node, ac,len, export);
	return (export);
}

void export_command(m_node *node)
{
	char **env;
	int len;
	char **export;
	// char **env;
	int i = 0;
	int ac = 1;

	while(node->arguments[ac])
		ac++;
	len = 0;
	env = get_env(NULL);
    while (env[len])
        len++;
	if (ft_strcmp(node->command ,"export") == 0)
	{
		export = get_export(node,env, len, ac);
				
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
