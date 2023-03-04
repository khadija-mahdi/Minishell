/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imple_unset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:49:48 by kmahdi            #+#    #+#             */
/*   Updated: 2023/03/04 14:49:52 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

void unset_command(m_node *node)
{
	char **env;
	int len;
	int i;
	char **va_unset;

	env = get_env(NULL);
	if (ft_strcmp(node->command ,"unset") == 0)
	{
		while(*env)
		{
			i = 1;
			while (ft_strncmp(*env, node->arguments[i], ft_strlen(*env)) == 0)
			{
				printf("unset: '%s' : not a valid identifier\n" ,node->arguments[i]);
				i++;
			}
			while(node->arguments[i])
			{
				if(!ft_strncmp(*env ,node->arguments[i], ft_strlen(node->arguments[i])) && (*env)[ft_strlen(node->arguments[i])] == '=')
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
	}
}