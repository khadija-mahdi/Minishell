/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:52:00 by kmahdi            #+#    #+#             */
/*   Updated: 2023/02/25 12:10:27 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

m_node *init_struct(m_node *node, char *input)
{
	if(input[0] == '\0' || input[0] == ' ' || input[0] == '\t')
		exit(0);
	node = malloc(sizeof(node));
	node->arguments = ft_split(input, ' ');
	node->commands = malloc(sizeof(char) * ft_strlen(node->arguments[0]) + 1);
	node->commands = node->arguments[0];
	// for(int i = 0; node->arguments[i]; i++)
	// 	printf("--> %s\n", node->arguments[i]);
	return(node);
}

// void exit_command(m_node *node)
// {	
// 	if ()
// }

// int main(int ac, char **av, char **env)
// {
// 	m_node *node;
// 	char    *input;
// 	char	*program_path;
// 	int		i;

// 	int pid = fork();
// 	i = 0;
	
// 		input = readline("MiniShell-$ ");
// 		program_path = get_path(env, input);
// 		node = init_struct(node, input);
// 		printf("-->%s\n", node->arguments[0]);
// 			// if (ft_strcmp(node->commands,"exit") == 0)
// 			// 	exit_command(node);
// 		// execve(program_path, node->arguments, env);
// }

void pwd_command(char *input)
{
	char pwd[1024];
	if (ft_strcmp(input , "pwd") == 0)
	{
    	if (getcwd(pwd, sizeof(pwd)) != NULL) 
        	printf("%s\n", pwd);
	}
}

#include "minishell.h"


int main(int ac, char **av, char **env)
{
	char    *input = readline("Enter a command: ");
	char	*program_path;
	int i = 0;
	pwd_command(input);
	
	// program_path = get_path(env, input);

	// printf ("%s", program_path);

}

