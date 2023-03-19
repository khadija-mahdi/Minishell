/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:49:48 by kmahdi            #+#    #+#             */
/*   Updated: 2023/03/19 09:51:46 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

char **unset_env(char **str , char **env)
{
	int len;
	int i;
	char **va_unset;

	while(*env)
	{
		i = 1;
		while (ft_strncmp(*env, str[i], ft_strlen(*env)) == 0)
		{
			printf("unset: '%s' : not a valid identifier\n" ,str[i]);
			i++;
		}
		while(str[i])
		{
			if(!ft_strncmp(*env ,str[i], ft_strlen(str[i])) && (*env)[ft_strlen(str[i])] == '=')
			{	
				va_unset = env + 1;
				while(*va_unset)
				{
					*(va_unset - 1)  = *va_unset;
					va_unset++;
				}
			}
			else
				i++;
			*(va_unset - 1) = NULL;
			
		}
		env++;
	}
	return(env);
}

void unset_command(m_node *node , char **env)
{
	char **new_env;
	if (ft_strcmp(node->command, "unset") == 0)
	{
		new_env = unset_env(node->arguments, env);
		// get_env(new_env);
		get_export(new_env);
	}
	
}
