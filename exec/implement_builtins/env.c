/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 22:43:41 by kmahdi            #+#    #+#             */
/*   Updated: 2023/03/16 02:20:37 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

void env_command(m_node *node)
{
	char **env;
	
	if (ft_strcmp(node->command ,"env") == 0)
	{
		env = get_env(NULL);
		if (env == NULL)
			printf("hiiii\n");
		if (!node->arguments[1])
		{
			while(*env)
			{
				printf("%s\n", *env);
				env++;
			}
		}
		else
			printf("env: %s: No such file or directory\n", node->arguments[1]);
	}
}