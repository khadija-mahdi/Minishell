/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 22:31:49 by kmahdi            #+#    #+#             */
/*   Updated: 2023/03/31 07:04:27 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

int	string_exists(char **export, int n, char *argument, int len)
{
	int	i;

	i = 0;
	while (i < n)
	{
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

char *add_qoutes(char *str, int is_env)
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
	if (is_env == 0)
		new_string[i++] = '\"';
	while(str[start])
		new_string[i++] = str[start++];
	if (is_env == 0)
		new_string[i++] = '\"';
	new_string[i] = '\0';
	return (new_string);
}

char *add_plus_string(char **export , char *new_str, int is_env)
{
	int i;
	int j ;
	int start;
	int len;
	int is_equal;
	char *new_string;
	
	i = 0;
	start = 0;
	int k = 0;
	is_equal = -1;
	while((new_str[start] != '=') && new_str[start])
		start++;
	printf(" new_str[start] = %c\n", new_str[start]);
	new_str= add_qoutes(new_str, is_env);
	while (export[i])
	{
		if (!ft_strncmp(export[i], new_str, start))
		{
			printf("export : %s\n", export[i]);
			is_equal = 0;
			break ;
		}
		i++;
	}
	j = 0;
	int n = 0;
	if (!is_equal && export[i])
	{
		len = ft_strlen(new_str) + ft_strlen(export[i]) + 3;
		new_string = malloc(len * sizeof(char));
		k = 0;
		while (export[i][j] && export[i][j] != '\"')
			j++;
		if (export[i][j] == '\"' && is_env == 0)
			j++;
		while(k < j)
			new_string[k++] = export[i][n++];
		while(export[i][j] && export[i][j] != '\"')
		{
			if(export[i][j] == '+')
				j++;
			new_string[k++] = export[i][j++];
		}
		if (new_str[start] == '\"')
			start++;
		while(new_str[start])
			new_string[k++] = new_str[start++];
		new_string[k] = '\0';
	}
	else
		new_string = new_str;
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
	while (old_export && old_export[i])
	{
		export[i] = ft_strdup(old_export[i]);
		i++;
	}
	sorted_list(export, size(old_export));
	while (str && str[j] && !string_exists(old_export, size(old_export), str[j], ft_strlen(str[j])))
	{
		while (str && str[j] && (!ft_isalpha(str[j][0]) || is_forbiden_char(str[j]) || !is_equal_plus(str[j])))
			printf("export: '%s': not a valid identifier\n", str[j++]);
		if (str && str[j])
		{
			k = 0;
			while (str && str[j] && str[j][k])
			{
				if (str[j][k] == '=' && str[j][k - 1] != '+')
				{
					export[i++] = ft_strdup(add_qoutes(str[j], 0));
					break ;
				}
				else if (str[j][k] == '=' && str[j][k - 1] == '+')
				{
					export[i++] = ft_strdup(add_plus_string(old_export, str[j], 0));
					break ;
				}
				else
					export[i++] = ft_strdup(str[j]);
				printf("here !! %d\n", is_equal++);
				k++;
			}
		}
		j++;
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
