/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:37:32 by kmahdi            #+#    #+#             */
/*   Updated: 2023/03/04 12:10:19 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

void exit_command(m_node *node)
{
	int status;
	if (strcmp(node->command, "exit") == 0)
	{
		if(node->arguments[2] && node->arguments[1])
		{	
			printf("exit\nbash: exit: too many arguments\n");
			return ;
		}
		else if (!node->arguments[1]) 
			exit_msg("MiniSHell: exit\n", 0);
		else if (node->arguments[1])
		{
			status = ft_atoi(node->arguments[1]);
			if(strcmp(node->arguments[1] , "0") == 0)
				exit_msg("MiniSHell: exit_status_0\n", 0);
			else if (status == 0)
			{
				printf("exit\nMiniSHell: exit: %s: ",node->arguments[1]);
				exit_msg("numeric argument required\n", 255);
			}
			else
				exit_msg("MiniSHell: exit_else\n", status);
		}
	}
}

void env_command(m_node *node)
{
	char **env;
	int index = 0;

	if (ft_strcmp(node->command ,"env") == 0)
	{
		env = get_env(NULL);
		if (env == NULL)
			printf("hiiii\n");
		if (!node->arguments[1])
		{
			while(*env)
			{
				printf("%s\n", *env);
				env++;
			}
		}
		else
			printf("env: %s: No such file or directory\n", node->arguments[1]);
	}
}

void echo_command(m_node *node)
{
	int i;
	if (ft_strcmp(node->command ,"echo") == 0)
	{
		if (!node->arguments[1])
			printf("\n");
		else
		{
			i = 1;
			while(ft_strncmp(node->arguments[i], "-n",2) == 0)
				i++;
			while(node->arguments[i])
				printf("%s ", node->arguments[i++]);
			if(ft_strncmp(node->arguments[1], "-n",2) != 0)
				printf("\n");
		}
	}
}

void pwd_command(m_node *node)
{
	if (ft_strcmp(node->command ,"pwd") == 0)
	{
		char pwd[4096]; // you chould know why 4096 :)
		if (getcwd(pwd, sizeof(pwd)) != NULL)
			printf("%s\n", pwd);
	}
}

void cd_command(m_node *node)
{
	char *path;

	if (ft_strcmp(node->command ,"cd") == 0)
	{
		path = get_path();
		if(!node->arguments[1])
			chdir(getenv("HOME"));
		else
		{			
			struct stat sb;
			if (stat(node->arguments[1], &sb) == 0 && S_ISDIR(sb.st_mode))
				chdir(node->arguments[1]);
			else
				printf("cd: no such file or directory: %s\n",node->arguments[1]);
		}
	}
}