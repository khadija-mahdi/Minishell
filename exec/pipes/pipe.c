/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:13:13 by kmahdi            #+#    #+#             */
/*   Updated: 2023/03/22 18:24:11 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

int is_builtins(m_node *node)
{
	if (ft_strcmp(node->command ,"cd") == 0)
		return(1);
	else if (ft_strcmp(node->command ,"echo") == 0)
		return(1);
	else if (ft_strcmp(node->command ,"pwd") == 0)
		return(1);
	else if (ft_strcmp(node->command ,"export") == 0)
		return(1);
	else if (ft_strcmp(node->command ,"unset") == 0)
		return(1);
	else if (ft_strcmp(node->command ,"exit") == 0)
		return(1);
	else if (ft_strcmp(node->command ,"env") == 0)
		return(1);
	else
		return(0);
}
void	path(char *paths, char **full_path, char *command)
{
	char	**my_paths;
	char	*program;
	int		j;

	j = 0;
	if (paths)
	{
		my_paths = ft_split(paths + 5, ':');
		while (my_paths[j])
		{
			program = ft_strjoin("/", command);
			*full_path = ft_strjoin(my_paths[j++], program);
			free(program);
			if (access(*full_path, F_OK) == 0)
				break ;
			free(*full_path);
			*full_path = NULL;
		}
		free_list(my_paths);
	}
}

char *get_command_path(char *command, char **env)
{
	int		i;
	char	*full_path;
	char	*paths;

	i = 0;
	full_path = NULL;
	if (access(command, F_OK) == 0)
		return (command);
	while (env[i])
	{
		paths = (ft_strnstr(env[i++], "PATH=", 5));
		path(paths, &full_path, command);
	}
	return (full_path);
}

 char *get_paths(char **env , char *command)
{
	char	*program_path;
	char	**list ;
	list = ft_split(command, ' ');
	program_path = get_command_path(list[0], env);
	return(program_path);
}
void pipe_exuc(m_node *node) 
{
	char **env = get_env(NULL);
	char	*program_path;
	pid_t pid;
	
	program_path = get_paths(env, node->command);
	if(!is_builtins(node))
	{
		pid = fork();
		if(!pid)
			execve(program_path, node->arguments, env);
		waitpid(pid, NULL, 0);
	}
}


// }

//get_path return the path of commands splited py space  or (null) if the command is not command !!
// get command path return full path that is had the pathe of command !!
// paths == the env after "PATH="
// my path = env with "path="


//echo
// cd
//pwd
//export--> x
//unset--> x
//env
//exit --> x