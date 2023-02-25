#include "../minishell.h"
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

// void exit_command(m_node *node)
// {
// 	if (ft_strcmp(node->command, "exit") == 0)
// 		exit_msg("MiniSHell: exit\n", 0);
// 	if (ft_isdigit(node->arguments[1][0]))

	
// }

void	exec(t_list *list)
{
	int i;
	int status;

	i = 1;
	if (list == NULL)
		return ;
	while (list)
	{
		m_node *node = (m_node *)list->content;
		if (!node)
			return ;
		if (strcmp(node->arguments[0], "exit") == 0) 
		{
            if (node->arguments[1] != NULL) 
                status = ft_atoi(node->arguments[0]);
			else if(node->arguments[2] != NULL)
			{
				printf("exit\nbash: exit: too many arguments");
				return ;
			}
			else if(!ft_isdigit(node->arguments[2][i]) && node->arguments[2] != NULL)
			{
				printf("exit\nbash: exit: too many arguments");
				return ;
			}
            else 
                status = 0;

			// exit_msg("MiniSHell: exit\n", status);
		}
		// else
		// {
		// 	int status = ft_atoi(node->arguments[2]);
		// 	exit_msg("MiniSHell: exit_status\n", status);
		// }
		i++;
		list = list->next;
		}
}
// {
	// int i = 0;
	// m_node *node  = (m_node *)list->content;
	// char **path = get_env(NULL); // cpy path;
	// while(node->arguments[i])
	// 	i++;X
	// if (!node->command || !node->arguments)
	// 	return ;
	// if (i == 1)
	// {
	// 	int is_status = node->arguments[2];
	// 	printf("%s\n", node->arguments[2]);
	// 	if (ft_strcmp(node->command, "exit") == 0)
	// 	{
	// 		exit_msg("MiniSHell: exit\n", 0);
	// 	}
	// }
// }
	
	// else if (!ft_isdigit(node->arguments[1][0] && node->arguments[1]))
	// {
	// 	printf("exit\nMiniSHell: exit: %s: ",node->arguments[1]);
	// 	exit_msg("numeric argument required", 255);
	// }
	// else
	// 	printf("MiniSHell: exit\n");
 