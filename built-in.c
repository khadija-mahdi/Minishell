/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built-in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:12:59 by kmahdi            #+#    #+#             */
/*   Updated: 2023/02/23 16:13:32 by kmahdi           ###   ########.fr       */


/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


// void builtins_command(m_node *node, char *input)
// {
// 	int i;

// 	i = 1;
// 		if(ft_strcmp(node->commands,"echo") == 0)
// 		{
// 			while (node->arguments[i])
// 				printf("%s ", node->arguments[i++]);
// 			if(ft_strcmp(node->arguments[2],"-n") != 0)
// 				printf("\n");
				
// 		}
// 		else if (ft_strcmp(node->commands,"exit") == 0)
// 		{

// 			while (node->arguments[i])
// 			{

// 				if(node->arguments[1] == '\0')
// 					exit_msg("exit\n", 0);
// 				else if (ft_isdigit(node->arguments[1][i]))
// 				{
// 					int n  = ft_atoi(node->arguments[1]);
// 					exit_msg("exit\n" ,n);
// 				}
// 				else if(!ft_isdigit(node->arguments[1][i]))
// 				{
// 					printf("exit\n %s: numeric argument required\n", node->arguments[1]);
// 					exit(127);
// 				}
// 				else
// 					printf("exit\n exit: too many arguments\n");
// 			}
// 		}
// 		else
// 			printf("%s", "command not found !!");
// 		printf("%s\n", node->arguments[2]);
// }
	// char pwd[1024];
	// int i = 0;
	// if (ft_strcmp(input , "pwd") == 0)
	// {
	// 	if (getcwd(pwd, sizeof(pwd)) != NULL) 
    //     	printf("%s\n", pwd);
	// }
	// else if (ft_strcmp(input , "exit") == 0 && !input[i])
	// 	exit_msg( "exit",255);
	// else 
	// 			printf("%s: command not found\n", input);


// void exit_command(char *input)
// {
	
// 	if (ft_strcmp(input , "exit") == 0 && !input[i])
// 		exit_msg( "exit",255);
// 	else 
// 				printf("%s: command not found\n", input);
// 	// else
// 	// {
		
// 	// 	while(input[i])
// 	// 	{
			
				

			
// 	// 	}
// 	// }
// }

