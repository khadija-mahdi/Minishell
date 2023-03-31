
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
#include <stdlib.h>
#include <string.h>

size_t	size(char **ptr)
{
	size_t	i;

	i = 0;
	if (!ptr)
		return (0);
	while (ptr[i])
		i++;
	return (i);
}

char	**get_env(char **p)
{
	static char **env;
	int i = 0;
	if (p != NULL)
	{
		env = malloc((size(p) + 1) * sizeof(char *));
		while (p && p[i])
		{
			env[i] = strdup(p[i]);
			i++;
		}
		env[i] = NULL;
	}
	return (env);
}
int main(int ac, char **av, char **env)
{
	char **s = get_env(NULL);

	while(s && *s)
	{
		printf("%s\n", *s);
		s++;
	}
}