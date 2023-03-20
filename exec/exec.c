/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:53:28 by kmahdi            #+#    #+#             */
/*   Updated: 2023/03/19 18:49:52 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

char	**get_export(char **p)
{
	static char **export;
	int i = 0;
	if (p != NULL)
	{
		export = malloc((size(p) + 1) * sizeof(char *));
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
	if (list == NULL)
		return ;
	m_node *node = (m_node *)list->content;
	if (!node)
		return ;
	if(!node->command || !node->arguments[0])
		return ;
	builtins(node);
	// pipe_exuc(node);
	// handle_signal();
}
