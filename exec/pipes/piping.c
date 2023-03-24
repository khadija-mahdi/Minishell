/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 18:49:05 by kmahdi            #+#    #+#             */
/*   Updated: 2023/03/22 17:50:34 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

void	command_one(int fd[], char **env, m_node *node )
{
	int		input;
	char	*program_path;

	input = open(node->arguments[1], O_RDONLY);
	if (input == -1)
		exit_msg("input fd error ! \n", 1);
	if (node->arguments[1][0] == 0)
		exit_msg(" command not found \n", 127);
	program_path = get_paths(env, node->command);
	if (program_path == NULL)
		exit_msg("No such file or directory \n", 1);
	if (dup2(input, 0) < 0 || (dup2(fd[1], 1) < 0))
		exit_msg("Dup error cmd1! \n", 1);
	execve(program_path, node->arguments, env);
}

void	command_two(int fd[], char **env, m_node *node )
{
	char	**list1;
	int		output;
	char	*program_path;

	output = open(node->arguments[4], O_CREAT | O_RDWR | O_TRUNC, 0664);
	if (output == -1)
		exit_msg("input fd error ! \n", 1);
	if (node->arguments[3][0] == 0)
		exit_msg("command not found \n", 127);
	program_path = get_paths(env, node->command);
	if (program_path == NULL)
		exit_msg("No such file or directory \n", 1);
	if (dup2(output, 1) < 0 || dup2(fd[0], 0) < 0)
		exit_msg("Dup error cmd2! \n", 1);
	execve(program_path, node->arguments, env);
}
void	piping(int fd[2], int pid2, char **env, m_node *node)
{
	close(fd[1]);
	pid2 = fork();
	if (pid2 == 0)
		command_two(fd, env, node);
}
void	error_handling(char **av)
{
	if (av[2][0] == '\0' && av[3][0] == '\0' )
	{	
		ft_printf("command not found\n");
		exit_msg("command not found\n", 1);
	}
}

void two_pipes(m_node *node)
{
	int	pid;
	int	pid2;
	int	fd[2];
	char **env;
	env = get_env(NULL);

	pid = 0;
	pid2 = 0;
	error_handling(node->arguments);
	if (pipe(fd) == -1)
	exit_msg("pipe error ! \n", 1);
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		command_one(fd, env, node);
	}
	else
		piping(fd, pid2, env, node);
	waitpid(pid, NULL, 0);
	waitpid(pid2, NULL, 0);
}
