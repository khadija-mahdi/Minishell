/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:53:28 by kmahdi            #+#    #+#             */
/*   Updated: 2023/03/26 03:04:24 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

char *change_env(char **env)
{
	char *pwd;
	char *old_pwd;
	
	old_pwd = NULL;
	pwd = getcwd(NULL, 0);
	while(*env && pwd)
	{
		if(!ft_strncmp(*env, "OLDPWD", 6))
		{
			remove_env(env);
			old_pwd = ft_strjoin("OLDPWD=", pwd);
			printf("old_pwd :: ==> %s\n", old_pwd);
		}
		else
			env++;
	}
	return(old_pwd);
}

char	**get_export(char **p)
{
	static char **export;
	
	int i = 0;
	if (p != NULL)
	{
		export = malloc((size(p) + 2) * sizeof(char *));
		while (p[i])
		{
			export[i] = ft_strdup(p[i]);
			i++;
		}
		export[i] = NULL;
	}
	return (export);
}

void	exec(t_list *list)
{
	char **env = get_env(NULL);
	if (list == NULL)
		return ;
	m_node *node = (m_node *)list->content;
	if (!node)
		return ;
	if(!node->command || !node->arguments[0])
		return ;
	printf("%d\n", ft_lstsize(list));
	if (ft_lstsize(list) == 1)
	{
		builtins(node);
		pipe_exuc(node);
	}
	else
		multiple_pipes(node, list, env);
	// handle_signal();
}
