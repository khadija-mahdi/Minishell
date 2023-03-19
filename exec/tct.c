

























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
