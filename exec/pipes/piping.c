/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khadija-mahdi <khadija-mahdi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 18:49:05 by kmahdi            #+#    #+#             */
/*   Updated: 2023/03/24 02:59:53 by khadija-mah       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"



#define MAX_ARGS 10

 void multiple_pipes(int argc, char *argv[])
{
    int i, j, k, l, status;
    int num_pipes = 0;
    int num_commands = 0;
    int num_args[MAX_ARGS] = {0};
    char *commands[MAX_ARGS][MAX_ARGS] = {NULL};
    int pipes[MAX_ARGS][2];

    // count the number of pipes and commands
	i = 0;
    while (i < argc) 
	{
        if (strcmp(argv[i], "|") == 0) 
		{
            num_pipes++;
            num_commands++;
        } else
            num_args[num_commands]++;
		i++;
    }
    num_commands++;

    // parse the command-line arguments
    j = 0;
    k = 0;
	i = 1;
    while (i < argc) 
	{
        if (strcmp(argv[i], "|") == 0)
		{
            commands[j][k] = NULL;
            j++;
            k = 0;
        } 
		else 
		{
            commands[j][k] = argv[i];
            k++;
        }
		i++;
    }
    commands[j][k] = NULL;

    // create the pipes
	i = 0;
    while (i < num_pipes) 
	{
        if (pipe(pipes[i]) == -1) 
		{
            perror("pipe");
            exit(EXIT_FAILURE);
        }
		i++;
    }

    // execute the commands
	i = 0;
    while (i < num_commands) 
	{
        pid_t pid = fork();

        if (pid == -1)
		{
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pid == 0)
		{
            // child process
            if (i == 0)
			{
                // first command
                dup2(pipes[0][1], STDOUT_FILENO);
            }
			else if (i == num_commands - 1)
			{
                // last command
                dup2(pipes[num_pipes - 1][0], STDIN_FILENO);
            }
			else {
                // intermediate command
                dup2(pipes[i - 1][0], STDIN_FILENO);
                dup2(pipes[i][1], STDOUT_FILENO);
            }

            // close all pipes
			j = 0;
            while (j < num_pipes)
			{
                close(pipes[j][0]);
                close(pipes[j][1]);
				j++;
            }

            // execute the command
            execvp(commands[i][0], commands[i]);
            perror("execvp");
            exit(EXIT_FAILURE);
        }
		i++;
    }

    // close all pipes
	i = 0;
    while (i < num_pipes)
	{
        close(pipes[i][0]);
        close(pipes[i][1]);
		i++;
    }

    // wait for all child processes to finish
	i = 0;
    while (i < num_commands)
	{
        wait(&status);
		i++;
    }

    return 0;
}




