/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 22:45:41 by kmahdi            #+#    #+#             */
/*   Updated: 2023/03/15 23:34:24 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"


void pwd_command(m_node *node)
{
	if (ft_strcmp(node->command ,"pwd") == 0)
	{
		char pwd[4096]; // you chould know why 4096 :)
		if (getcwd(pwd, sizeof(pwd)) != NULL)
			printf("%s\n", pwd);
	}
}

char **cd_tilde(m_node *node, struct stat sb)
{
	char **dir;
	int i;

	if(node->arguments[1][1] == '/')
	{
		i = 0;
		while(node->arguments[1][i])
		{
			if(node->arguments[1][i] == '~')
				i++;
			dir = ft_split(node->arguments[1], '/');
			i++;
		}
	}
	return(dir);
}

void cd_command(m_node *node)
{
	char **dir;
	char **env = get_env(NULL);
	char pwd[4096];

	if (ft_strcmp(node->command ,"cd") == 0)
	{
		if(!node->arguments[1] || !strcmp(node->arguments[1], "~"))
			chdir(getenv("HOME"));
		else
		{			
			struct stat sb;
			if(node->arguments[1][0] == '~')
			{
				dir = cd_tilde(node, sb);
				while(*dir)
				{
					if (stat(*dir, &sb) == 0 && S_ISDIR(sb.st_mode))
							chdir(*dir);
					dir++;
				}
			}
			else if (stat(node->arguments[1], &sb) == 0 && S_ISDIR(sb.st_mode))
			{
				// if (getcwd(pwd, sizeof(pwd)) != NULL)
				// {
					// while(*env)
					// {
					// 	if(!strncmp(*env , "OLDPWD=", 8 ) && *pwd)
					// 	{
					// 		*env = ft_substr(pwd,8, ft_strlen(pwd) - 1);
					// 		printf("%s\n", *env);
					// 		break ;
					// 	}
					// 	env++;
					// }
				// }
				chdir(node->arguments[1]);
				
			}
			else
				printf("cd: no such file or directory: %s\n",node->arguments[1]);
		}
	}
}
