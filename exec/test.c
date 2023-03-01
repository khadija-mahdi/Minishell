#include <stdio.h>
#include <string.h>

extern char **environ;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <variable>\n", argv[0]);
        return 1;
    }

    char **p = environ;
    while (*p != NULL) {
        if (strncmp(*p, argv[1], strlen(argv[1])) == 0 && (*p)[strlen(argv[1])] == '=') {
            // Found the variable, remove it by shifting the rest of the array down
            char **q = p;
        
        }
        p++;
    }

    printf("%s unset\n", argv[1]);

    return 0;
}


char *get_name(char **env, int index)
{
	char *env_name;
	int i ;

	env_name = malloc(ft_strlen(env[index]) + 1);
	while(env)
	{
		i = 0;
		while(env[index] && ft_strcmp(env[index], "="))
		{
			env_name[i] = env[index][i];
			i++;
		}
		index ++;
	}
	return( env_name);
}
