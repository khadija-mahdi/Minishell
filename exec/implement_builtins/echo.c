/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:37:32 by kmahdi            #+#    #+#             */
/*   Updated: 2023/03/18 17:06:09 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"



int is_newline(char *str)
{
	int i ;
	i = 2;
	while(str[i] && str[i] == 'n')
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
	
}

void echo_command(m_node *node)
{
	int i;
	if (ft_strcmp(node->command ,"echo") == 0)
	{
		if (!node->arguments[1])
			printf("\n");
		else
		{
			i = 1;
			while(ft_strncmp(node->arguments[i], "-n",2) == 0 && is_newline(node->arguments[i]))
				i++;
			while(node->arguments[i])
				printf("%s ", node->arguments[i++]);
			if((node->arguments[1][0] != '-' && !is_newline(node->arguments[1])))
				printf("\n");
		}
	}
}

