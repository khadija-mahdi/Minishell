/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 18:49:05 by kmahdi            #+#    #+#             */
/*   Updated: 2023/04/16 09:22:59 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

void	exec_commands(char *path, t_node *node, char **env)
{
	if (path == NULL )
	{
		ft_putstr_fd(node->command, 2);
		write(2, " :command not found \n", 22);
		exit (127);
	}
	else
	{
		execve(path, node->arguments, env);
		perror("execve");
	}
	exit(1);
}

void	redirection(t_node *node)
{
	if (node->output_file != NONE && node->output_file != NO_FILE
		&& node->output_file != ERROR)
	{
		if (dup2(node->output_file, 1) < 0)
			exit_msg("DUP", 1);
	}
	if (node->input_file != NONE && node->input_file != NO_FILE
		&& node->input_file != ERROR)
	{
		if (dup2(node->input_file, 0) < 0)
			exit_msg("DUP", 1);
	}
}

void	child_proccess(t_node *node, char **env)
{
	char	*path;

	if (!node->command)
	{
		ft_putstr_fd(node->command, 2);
		write(2, " :command not found \n", 22);
		exit (127);
	}
	redirection(node);
	if (is_builtins(node->command))
		path = NULL;
	else
		path = get_paths(env, node->arguments[0]);
	if (is_child_builtins(node->command, node->arguments[1]))
	{
		child_builtins(node);
		exit (0);
	}
	else
		exec_commands(path, node, env);
}

void	parent_proccess(int num_commands, int pipes[2], int in)
{
	int	status;

	while (num_commands--)
		wait(&status);
	close(pipes[0]);
	close(in);
	if (WIFEXITED(status))
		set_exit_status(WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		set_exit_status(128 + WTERMSIG(status));
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, SIG_IGN);
}

void	multiple_pipes(t_node *node, t_list *list, int num_commands)
{
	int		pipes[2];
	int		i;
	int		in;

	in = -1;
	i = 0;
	while (list)
	{
		node = (t_node *) list->content;
		pipe(pipes);
		if (node->command && is_builtin(node->command, node->arguments[1]))
		{
			if (num_commands == 1)
				builtins(node);
		}
		else
		{
			if (fork() == 0)
			{
				signal(SIGQUIT, SIG_DFL);
				signal(SIGINT, SIG_DFL);
				dup2(in, 0);
				close(pipes[0]);
				if (i < num_commands - 1)
				{
					dup2(pipes[1], 1);
					close (pipes[1]);
				}
				child_proccess(node, get_env(NULL));
			}
			else
			{
				signal(SIGINT, handle_sigint_n_chld);
				signal(SIGQUIT, child_quit);
			}
		}
		close(pipes[1]);
		if (in != -1)
			close(in);
		in = pipes[0];
		list = list->next;
		i++;
	}
	parent_proccess(num_commands, pipes, in);
}
