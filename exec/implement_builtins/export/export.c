/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 22:31:49 by kmahdi            #+#    #+#             */
/*   Updated: 2023/04/16 10:38:24 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "export.h"

int	len_comparison(char *s1, char *s2)
{
	int	index1;
	int	index2;

	index1 = get_name_index(s1);
	index2 = get_name_index (s2);
	if ((index2 - index1) == 0 && !ft_strncmp(s1, s2, index2))
		return (1);
	return (0);
}

void	sorted_list(char **export, int len)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (ft_strcmp(export[j], export[j + 1]) > 0)
			{
				temp = export[j];
				export[j] = export[j + 1];
				export[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

int	is_add_plus_str(char *argument)
{
	int	i;

	i = 0;
	while (argument && argument[i])
	{
		if (argument[i] == '=' && argument[i - 1] == '+')
			return (1);
		i++;
	}
	return (0);
}

void	add_new_export(char **export, char **old_export, char **arguments)
{
	int	i;
	int	j;

	i = -1;
	while (old_export && old_export[++i])
		export[i] = ft_strdup(old_export[i]);
	j = 1;
	while (arguments && arguments[j] && !string_exists(old_export,
			size(old_export), arguments[j], ft_strlen(arguments[j])))
	{
		if (arguments[j] && arguments[j][0] == '#')
			break ;
		if ((!ft_isalpha(arguments[j][0]) || is_forbidden_char(arguments[j])
			|| !is_equal_plus(arguments[j])))
			printf("export: '%s': not a valid identifier\n", arguments[j++]);
		else if (is_equal_plus_str(arguments[j]) == 2)
			export[i++] = add_plus_string(arguments[j++], 0);
		else
			export[i++] = ft_strdup(arguments[j++]);
	}
	export[i] = NULL;
}

char	**get_new_export(char **old_export, char **str)
{
	char	**export;
	char	**clean_ex;

	export = NULL;
	if (old_export)
	{
		export = malloc((size(old_export) + size(str)) * sizeof(char *));
		if (!export)
			exit(1);
		add_new_export(export, old_export, str);
	}
	clean_ex = remove_duplicate(export);
	free_list (export);
	return (clean_ex);
}
