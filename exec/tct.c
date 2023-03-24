#include <stdio.h>
#include <string.h>

int check_duplicate(char **str_array, int array_size) 
{
    for (int i = 0; i < array_size; i++) {
        for (int j = i+1; j < array_size; j++) {
            if (strcmp(str_array[i], str_array[j]) == 0) {
                // strings are duplicates
                return 1;
            }
        }
    }
    // no duplicates found
    return 0;
}

int main() {
    char *str_array[] = {"hello", "world", "hello", "openai", "world"};
    int array_size = sizeof(str_array)/sizeof(char *);
    if (check_duplicate(str_array, array_size)) {
        printf("Duplicate strings found\n");
    } else {
        printf("No duplicate strings found\n");
    }
    return 0;
}









































































// char **get_new_env(char **old_env , char **str)
// {
// 	int i ;
// 	int j;
// 	int k;
// 	int l;
// 	static char **env;
// 	l = 0;
// 	i = 1;
// 	k = 1;
// 	if (old_env != NULL  && !str[1])
// 		env = get_env(NULL);
// 	else
// 	{
// 		while(str[i])
// 		{
// 			j = 0;
// 			while(str[i][j])
// 			{
// 				if (str[i][j] == '=')
// 				{
// 					if(old_env != NULL  && str[k])
// 					{
// 						env = malloc((size(old_env) + size(str) ) * sizeof(char *));
// 						while (old_env[l])
// 						{
// 							env[l] = ft_strdup(old_env[l]);
// 							l++;
// 						}
// 						sorted_list(env,size(old_env));
// 						while(str[k])
// 							env[l++] = ft_strdup(str[k++]);
// 						env[l] = NULL;
// 					}
// 				}
// 				j++;
// 			}
// 			i++;
// 		}
		
// 	}
// 	return (env);
// }









// 1. Allocate memory for the new string using malloc() function.
// 2. Copy the contents of the new string into the allocated memory using the strcpy() function.
// 3. Add the new string to the double pointer by assigning the address of the allocated memory to the next available element in the double pointer.

char **check_duplicate(char **env, int size_env) 
{
	int i;
	int j;
	int len;
	char **name;
	char	**va_unset;
	
	name = get_name(env);
	i = 0;
    while (i < size_env) 
	{
		j = i + 1;
        while (  j < size_env) 
		{
			len = ft_strlen(name[i]);
			printf(" %s\n\n char == %c\n", env[i] , env[i][len]);
            if (ft_strncmp(env[i], env[j], len) == 0 && !is_value(env[j]))
			{
				printf("is_duuuun");
            	// va_unset = env + 1;
				// while (*va_unset)
				// {
				// 	*(va_unset - 1) = *va_unset;
				// 	va_unset++;
				// }
				// *(va_unset - 1) = NULL;
			}
			// else
				j++;
        }
		i++;
    }
	printf("no duplicates found");
    return (env);
}