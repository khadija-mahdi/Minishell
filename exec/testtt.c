#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_COMMANDS 10
#define MAX_ARGS 10
#define MAX_INPUT_SIZE 1024

int main(int argc, char* argv[], char **env) {
    char input[MAX_INPUT_SIZE];
    char* commands[MAX_COMMANDS][MAX_ARGS];
    int num_pipes = 0;

    // Parse the input command and split into commands and arguments
    fgets(input, MAX_INPUT_SIZE, stdin);
    char* token = strtok(input, "|");
    while (token != NULL && num_pipes < MAX_COMMANDS)
	{
        int i = 0;
        commands[num_pipes][i++] = token;
        while ((token = strtok(NULL, " \t\n")) != NULL && i < MAX_ARGS) {
            commands[num_pipes][i++] = token;
        }
        commands[num_pipes][i] = NULL;
        num_pipes++;
        token = strtok(NULL, "|");
    }

    // Create pipes and child processes for each command
    int fd[2], fd_in = STDIN_FILENO;
    for (int i = 0; i < num_pipes; i++)
	{
        pipe(fd);
        if (fork() == 0) {
            // Child process
            close(fd[0]);
            dup2(fd_in, STDIN_FILENO);
            if (i < num_pipes - 1) {
                dup2(fd[1], STDOUT_FILENO);
            }
            close(fd_in);
            execve(commands[i][0], commands[i], env);
            perror("execve failed");
            exit(EXIT_FAILURE);
        } else {
            // Parent process
            close(fd[1]);
            fd_in = fd[0];
        }
		num_pipes = 0;
    }

    // Wait for all child processes to finish
    for (int i = 0; i < num_pipes; i++) {
        wait(NULL);
    }

    return 0;
}
