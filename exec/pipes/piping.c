/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 18:49:05 by kmahdi            #+#    #+#             */
/*   Updated: 2023/04/17 03:14:27 by kmahdi           ###   ########.fr       */
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
		execve(path, node->arguments, env);
	if (!is_equal(node->command, "."))
	{
		write(2, ".: filename argument required \n"
			".: usage: . filename [arguments]\n", 65);
		exit (2);
	}
	perror("execve");
	exit(1);
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

void	signles_child_command(t_process	*prss, t_node *node, int n_cmd, int *i)
{
	pid_t	id;

	id = fork();
	if (id == -1)
		costume_err("fork: Resource temporarily unavailable\n", 1);
	if (id == 0)
	{
		signal(SIGQUIT, SIG_DFL);
		signal(SIGINT, SIG_DFL);
		dup2(prss->in, 0);
		close(prss->pipes[0]);
		if (*i < n_cmd - 1)
		{
			dup2(prss->pipes[1], 1);
			close (prss->pipes[1]);
		}
		child_proccess(node, get_env(NULL));
	}
	else
	{
		signal(SIGINT, handle_sigint_n_chld);
		signal(SIGQUIT, child_quit);
	}
}

void	multiple_pipes(t_node *node, t_list *list, int num_commands)
{
	t_process	process;
	int			i;

	process.in = -1;
	i = 0;
	while (list)
	{
		node = (t_node *) list->content;
		pipe(process.pipes);
		if (node->command && is_builtin(node->command, node->arguments[1]))
		{
			if (num_commands == 1)
				builtins(node);
		}
		else
			signles_child_command(&process, node, num_commands, &i);
		close(process.pipes[1]);
		if (process.in != -1)
			close(process.in);
		process.in = process.pipes[0];
		list = list->next;
		i++;
	}
	parent_proccess(num_commands, process.pipes, process.in);
}
