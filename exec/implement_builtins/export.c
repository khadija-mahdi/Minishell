/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 22:31:49 by kmahdi            #+#    #+#             */
/*   Updated: 2023/03/30 07:13:34 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

int	string_exists(char **export, int n, char *argument)
{
	int	i;
	int	len;

	i = 0;
	while (i < n)
	{
		len = ft_strlen(argument);
		if (strncmp(export[i], argument, len) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	is_plus_equal(char *arguments)
{
	int i;
	
	i = 0;
	while(arguments[i])
	{
		if (arguments[i] == '+' && arguments[i + 1] == '=')
			return (1);
		i++;
	}
	return (0);
}

char *add_qoutes(char *str)
{
	int start;
	int len;
	int i;
	int j;
	char *new_string;

	start = 0;
	len = ft_strlen(str)  + 3;
	i = 0;
	j = 0;
	while(str[start] != '=' && str[start])
		start++;
	if (str[start] == '=')
		start++;
	new_string = malloc(len * sizeof(char));
	while(j < start)
	{
		if(str[j] == '+')
			j++;
		new_string[i++] = str[j++];
	}
	new_string[i] = '\"';
	i++;
	while(str[start])
		new_string[i++] = str[start++];
	new_string[i] = '\"';
	new_string[++i] = '\0';
	return (new_string);
}

char *add_plus_string(char *str , char *new_str)
{
	int start;
	int len;
	int end;
	int i;
	int j;
	char *new_string;

	start = 0;
	end = 0;
	len = ft_strlen(str) + ft_strlen(new_str) + 3;
	i = 0;
	j = 0;
	while(str[start] != '=' && str[start])
		start++;
	if (str[start] == '=')
		start++;
	while (new_str[end] && new_str[end] != '=')
		end++;
	if (new_str[end] == '=')
		end++;
	new_string = malloc(len * sizeof(char));
	while(j < start)
	{
		if(str[j] == '+')
			j++;
		new_string[i++] = str[j++];
	}
	new_string[i] = '\"';
	i++;
	while(str[start])
		new_string[i++] = str[start++];
	while(new_str[end])
		new_string[i++] = new_str[end++];
	new_string[i] = '\"';
	new_string[++i] = '\0';
	return (new_string);
	
}

void	add_new_export(char **export, char **old_export, char **str)
{
	int	i;
	int	j;
	int k;
	int is_equal;

	i = 0;
	j = 1;
	is_equal = -1;
	while (old_export[i])
	{
		export[i] = ft_strdup(old_export[i]);
		i++;
	}
	sorted_list(export, size(old_export));
	while (str[j] && !string_exists(old_export, size(old_export), str[j]))
	{
		if ((!ft_isalpha(str[j][0]) || is_forbiden_char(str[j]) || !is_equal_plus(str[j])))
			printf("export: '%s': not a valid identifier\n", str[j++]);
		else if (str[j])
		{
			k = 0;
			while (str[j][k])
			{
				if (str[j][k] == '=' && str[j][k - 1] != '+')
				{
					export[i] = ft_strdup(add_qoutes(str[j]));
					break ;
				}
				else if (str[j][k] == '=' && str[j][k - 1] == '+')
				{
					export[i] = ft_strdup(add_plus_string(export[i], str[j]));
					break ;
				}
				export[i] = ft_strdup(str[j]);
				k++;
			}
			j++;
		}
		i++;
	}
	export[i] = NULL;
	// free_list (old_export);
}

char	**get_new_export(char **old_export, char **str)
{
	char	**export;
	
	if (old_export != NULL && !str[1])
	{
		export = get_export(NULL);
		sorted_list(export, size(old_export));
	}
	else if (old_export != NULL && str[1])
	{
		export = malloc((size(old_export) + size(str)) * sizeof(char *));
		add_new_export(export, old_export, str);
	}
	return (export);
}
