/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built-in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:12:59 by kmahdi            #+#    #+#             */
/*   Updated: 2023/02/22 18:50:24 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void pwd_command(char *input)
{
	char pwd[1024];
	if (ft_strcmp(input , "pwd") == 0)
	{
    	if (getcwd(pwd, sizeof(pwd)) != NULL) 
        	printf("%s\n", pwd);
	}
}

