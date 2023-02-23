/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:11:07 by kmahdi            #+#    #+#             */
/*   Updated: 2023/02/22 18:45:02 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	path(char *paths, char **full_path, char *av)
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
			program = ft_strjoin("/", av);
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

char *get_command_path(char *input, char **env)
{
int		i;
	char	*full_path;
	char	*paths;

	i = 0;
	full_path = NULL;
	if (access(input, F_OK) == 0)
		return (input);
	while (env[i])
	{
		paths = (ft_strnstr(env[i++], "PATH=", 5));
		path(paths, &full_path, input);
	}
	return (full_path);
}

char *get_path(char **env , char *input)
{
	char	*program_path;
	char	**list ;
	list = ft_split(input, ' ');
	program_path = get_command_path(list[0], env);
	return(program_path);
}

//get_path return the path of commands splited py space  or (null) if the input is not command !!
// get command path return full path that is had the pathe of command !!
// paths == the env after "PATH="
// my path = env with "path="