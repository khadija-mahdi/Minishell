/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:53:28 by kmahdi            #+#    #+#             */
/*   Updated: 2023/04/07 11:59:51 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

char	**get_export(char **p)
{
	static char	**export;
	int			i;

	i = 0;
	if (p != NULL)
	{
		export = malloc((size(p) + 1) * sizeof(char *));
		while (p && p[i])
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
	char	**env;
	m_node	*node;
	int		num_commands;

	env = get_env(NULL);
	if (list == NULL)
		return ;
	node = (m_node *)list->content;
	if (!node)
		return ;
	if (!node->command || !node->arguments[0])
		return ;
	num_commands = ft_lstsize(list);
	if (num_commands >= 709)
	{
		printf("fork: Resource temporarily unavailable\n");
		return ;
	}
	if (num_commands == 1 && is_builtin(node->command))
		builtins(node);
	else
		multiple_pipes(node, list, num_commands);
}
