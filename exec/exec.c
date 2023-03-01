#include "exec.h"

int ft_strcmp(char *s1, char *s2)
{
	int i = 0;
	
	while(s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{	
		i++;
	}
	return (s1[i] - s2[i]);

}

void	exit_msg(char *msg, int i)
{
	printf("%s", msg);
	exit(i);
}

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
		while (env[index])
			index++;
		if (index != 36)
		{
			printf("env: no such file or directory\n");
			return ;
		}
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
			if(ft_strncmp(node->arguments[1], "-n",2) == 0)
				i = 2;
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

// char *get_name(char **env , int index)
// {
// 	char *env_name;
// 	int i ;
// 	index = 0;

// 	env_name = malloc(ft_strlen(env[index]) + 1);
// 	while(env)
// 	{
// 	while(env[index])
// 	{
// 		i = 0;
// 		if(env[index] && !ft_strcmp(env[index], "="))
// 			break;
// 		env_name[i] = env[index][i];
// 		i++;
// 		index ++;
// 	}
// 	env_name[i] ='\0';
// 	return( env_name);
// 	}
// }
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

void unset_command(m_node *node)
{
	char **env;
	int len;

	env = get_env(NULL);
	len = ft_strlen(node->arguments[1]);
	if (ft_strcmp(node->command ,"unset") == 0)
	{
		while(*env)
		{
			if(!ft_strncmp(*env ,node->arguments[1],len ) && (*env)[len] == '=')
				*env = NULL;
			env++;
		}
		printf("%s unset\n", node->arguments[1]);
	}
}

void	exec(t_list *list)
{
	char **env;
	int len;

	env = get_env(NULL);
	
	if (list == NULL)
		return ;
	m_node *node = (m_node *)list->content;
	if (!node)
		return ;
	if(!node->command || !node->arguments[0])
		return ;
	exit_command(node);
	unset_command(node);
	env_command(node);
	echo_command(node);
	pwd_command(node);
	cd_command(node);
}
 