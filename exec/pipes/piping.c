/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 18:49:05 by kmahdi            #+#    #+#             */
/*   Updated: 2023/03/25 06:52:20 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

void multiple_pipes(char **commands, t_list *list, char **env) 
{
    int num_commands = 1;
    int i;

	i = 0;
	if (list == NULL)
		return ;
	while (list)
	{
		m_node *node = (m_node *)list->content;
		if (!node)
		{
			printf("node null");
			return ;
		}
		num_commands++;
		list = list->next;
	}
	num_commands--;
    int pipes[2 * (num_commands - 1)];

	i = 0;
    while (i < num_commands-1)
	{
        if (pipe(pipes + i * 2) < 0)
		{
            perror("pipe error");
            return;
        }
		i++;
    }

    int pid;
    int in = 0;
    int out = 1;

	i = 0;
    while (i < num_commands)
	{
		printf("%d\n, %s\n", num_commands, commands[i]);
        if ((pid = fork()) < 0)
		{
            perror("fork error");
            return ;
        }
		else if (pid == 0)
		{
            if (i != 0)
			{
                if (dup2(pipes[in], 0) < 0) {
                    perror("dup2 error");
                    return;
                }
                close(pipes[in]);
            }
            if (i != num_commands - 1) {
                if (dup2(pipes[out], 1) < 0) {
                    perror("dup2 error");
                    exit(1);
                }
                close(pipes[out]);
            }
            char *path = get_paths(env, commands[i]);
            execve(path, commands, env);
            perror("execve error");
            exit(1);
        } else {
            if (i != 0) {
                close(pipes[in]);
            }
            if (i != num_commands-1) {
                close(pipes[out]);
            }
            in += 2;
            out += 2;
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
