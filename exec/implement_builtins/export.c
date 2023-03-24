/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 22:31:49 by kmahdi            #+#    #+#             */
/*   Updated: 2023/03/24 00:01:12 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exec.h"

char	**get_name(char **str)
{
	char	**name;
	int		start;
	int		i;
	int		j;

	i = 1;
	j = 0;
	name = NULL;
	if (str[i])
	{
		name = malloc(size(str) + sizeof(char *));
		while (str[i])
		{
			start = 0;
			while (str[i][start] != '=' && str[i][start])
				start++;
			if (str[i][start] == '=')
				start++;
			name[j] = ft_substr(str[i], 0, start);
			i++;
			j++;
		}
		name[j] = NULL;
	}
	return (name);
}

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

void	add_new_export(char **export, char **old_export, char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (old_export[i])
	{
		export[i] = ft_strdup(old_export[i]);
		i++;
	}
	sorted_list(export, size(old_export));
	while (str[j] && (!ft_isalpha(str[j][0]) || is_forbiden_char(str[j])))
		j++;

	while (str[j] && !string_exists(old_export, size(old_export), str[j]))
		export[i++] = ft_strdup(str[j++]);
	export[i] = NULL;
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
