/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 22:31:49 by kmahdi            #+#    #+#             */
/*   Updated: 2023/04/02 06:53:32 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../exec.h"

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

void	add_new_export(char **export, char **old_export, char **str)
{
	int	i;
	int	j;
	int k;
	char **name = get_name(str);

	i = 0;
	while (old_export && old_export[i])
	{
		export[i] = ft_strdup(old_export[i]);
		i++;
	}
	sorted_list(export, size(old_export));
	j = 1;
	while (str && str[j] && !string_exists(old_export, size(old_export), str[j], ft_strlen(str[j])))
	{
		if (name && name[j] && (!ft_isalpha(name[j][0]) || is_forbidden_char(name[j]) || !is_equal_plus(name[j])))
			printf("export: '%s': not a valid identifier\n", str[j]);
		if (str && str[j])
		{
			k = 0;
			while (str && str[j] && str[j][k])
			{
				if (str[j][k] == '=' && str[j][k - 1] == '+')
				{
					export[i++] = ft_strdup(add_plus_string(old_export, str[j++], 0));
					break ;
				}
				k++;
			}
			export[i++] = ft_strdup(str[j]);
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
	export = reset_forbidden_env(export);
	export = remove_duplicate(export);
	return (export);
}
