/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 05:00:34 by kmahdi            #+#    #+#             */
/*   Updated: 2023/04/02 06:39:15 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../exec.h"

int	is_value(char *argument)
{
	int	i;
	
	i = 0;
	while (argument && argument[i])
	{
		if (argument[i] == '=')
			return (i);
		i++;
	}
	return (0);
}

int	get_start(char *argument)
{
	int	start;

	start = 0;
	while (argument && argument[start] && argument[start] != '=')
		start++;
	if (argument[start] == '=')
		start++;
	return (start);
}

char	**get_name(char **argument)
{
	char	**name;
	int		start;
	int		index;

	index = 0;
	name = NULL;
	if (argument[index])
	{
		name = malloc(size(argument) * sizeof(char *));
		while (argument[index])
		{
			start = 0;
			while (argument[index][start] != '=' && argument[index][start])
				start++;
			if (argument[index][start] == '=')
				start++;
			name[index] = ft_substr(argument[index], 0, start);
			index++;
		}
		name[index] = NULL;
	}
	return (name);
}

int is_equal_plus(char *argument)
{
	int	len;
	int	index;

	len = 0;
	index = 0;
	while (argument && argument[len] && argument[len] != '=')
		len++;
	while (index < len)
	{
		if (argument[index] == '+')
		{
			if (argument[index + 1] == argument[len])
				return (1);
			return (0);
		}
		index++;
	}
	return (1);
}
int is_forbidden_char(char *argument)
{
	int len;
	int index;

	len = 0;
	index = 0;
	while(argument && argument[len] && argument[len] != '=')
		len++;
	while(index < len)
	{
		if(!ft_isalnum(argument[index]))
			return(1);
		index++;
	}
	return (0);
}