/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 18:49:05 by kmahdi            #+#    #+#             */
/*   Updated: 2023/03/26 03:22:41 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

void multiple_pipes(m_node *node, t_list *list, char **env) 
{
    int num_commands = ft_lstsize(list);
    int i;
    char *path;
    int pipes[2];
    int in = 0;
	i = 0;
    while (list)
	{
        pipe(pipes);
        node = (m_node *) list->content;
		if (fork() == 0)
		{
            close(pipes[0]);
            dup2(in, 0);
            if (i < num_commands - 1)
                dup2(pipes[1], 1);
            close (in);
            path = get_paths(env, node->arguments[0]);
            execve(path, node->arguments, env);
            perror("execve error");
            exit(1);
        }
        else
        {
            close(pipes[1]);
            in = pipes[0];
            list = list->next;
        }
		i++;
	}
	i = 0;
    while (i < num_commands)
	{
        wait(NULL);
		i++;
    }
}
