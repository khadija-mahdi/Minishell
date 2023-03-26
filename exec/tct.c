 #include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "exec.h"

// size_t	size(char **ptr)
// {
// 	size_t	i;

// 	i = 0;
// 	if (!ptr)
// 		return (0);
// 	while (ptr[i])
// 		i++;
// 	return (i);
// }

void pipes(int argc, char *argv[], char **env) 
{
    char **commands;
    int num_commands = 0;
    int i;

	i = 1;
    while  (i < argc)
	{
        commands[num_commands] = argv[i];
		num_commands++;
		i++;
    }
    commands[num_commands] = NULL;
    num_commands = size(commands);

    int pipes[2 * (num_commands - 1)];

	i = 0;
    while (i < num_commands-1)
	{
        if (pipe(pipes + i * 2) < 0)
		{
            perror("pipe error");
            return;
        }
		i++;
    }

    int pid;
    int in = 0;
    int out = 1;

	i = 0;
    while (i < num_commands)
	{
        if ((pid = fork()) < 0)
		{
            perror("fork error");
            return ;
        }
		else if (pid == 0)
		{
            if (i != 0)
			{
                if (dup2(pipes[in], 0) < 0) {
                    perror("dup2 error");
                    return;
                }
                close(pipes[in]);
            }
            if (i != num_commands-1) {
                if (dup2(pipes[out], 1) < 0) {
                    perror("dup2 error");
                    exit(1);
                }
                close(pipes[out]);
            }
            char *path = get_paths(env, commands[i]);
            execve(path, commands, env);
            perror("execve error");
            exit(1);
        } else {
            if (i != 0) {
                close(pipes[in]);
            }
            if (i != num_commands-1) {
                close(pipes[out]);
            }
            in += 2;
            out += 2;
        }
		i++;
	}
	i = 0;
    while (i < num_commands)
	{
        wait(NULL);
		i++;
    }
}

int main(int ac, char **av, char **env)
{
	pipes(ac, av, env);
}