

int main() {
    char* input;
    while ((input = readline("> ")) != NULL) {
        if (strcmp(input, "exit") == 0) {
            free(input);
            exit(0);
        } else if (strncmp(input, "exit ", 5) == 0) {
            char* endptr;
            long status = strtol(input + 5, &endptr, 10);
            if (errno != ERANGE && endptr != input + 5 && *endptr == '\0') {
                free(input);
                exit((int)status);
            }
        }
        printf("You entered: %s\n", input);
        add_history(input);
        free(input);
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s VARIABLE=VALUE\n", argv[0]);
        exit(1);
    }

    char *var = argv[1];
    char *value = strchr(var, '=');

    if (value == NULL) {
        printf("Invalid argument: %s\n", var);
        exit(1);
    }

    *value++ = '\0';

    // Find the variable in the environment
    char **env = environ;
    while (*env != NULL) {
        if (strncmp(*env, var, strlen(var)) == 0 && (*env)[strlen(var)] == '=') {
            break;
        }
        env++;
    }

    if (*env == NULL) {
        // Variable not found in the environment, so we need to add it
        int num_env = env - environ;
        environ = realloc(environ, sizeof(char *) * (num_env + 2));
        environ[num_env] = strdup(var);
        environ[num_env + 1] = NULL;
    } else {
        // Variable already exists in the environment, so we need to modify it
        free(*env);
        *env = strdup(var);
    }

    for (char **env = environ; *env != NULL; env++) {
        printf("%s\n", *env);
    }

    return 0;
}






