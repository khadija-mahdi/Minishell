/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_equal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 22:25:36 by kmahdi            #+#    #+#             */
/*   Updated: 2023/04/07 04:20:30 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "export.h"

char	*add_quotes(char *str, int is_env)
{
	char	*new_string;
	int		start;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(str) + 3;
	i = 0;
	j = 0;
	start = get_start(str);
	new_string = malloc(len * sizeof(char));
	while (j < start)
	{
		if (str[j] == '+')
			j++;
		new_string[i++] = str[j++];
	}
	if (is_env == 0)
		new_string[i++] = '\"';
	while (str[start])
		new_string[i++] = str[start++];
	if (is_env == 0)
		new_string[i++] = '\"';
	new_string[i] = '\0';
	return (new_string);
}

char	*the_added_string(char	*n_exp, char **exp, char *n_str, int start)
{
	char	*n_string;
	int		len;
	int		j;
	int		k;

	len = ft_strlen(n_str) + ft_strlen(n_exp) + 3;
	n_string = malloc(len * sizeof(char));
	j = 0;
	while (exp && n_exp && n_exp[j])
		j++;
	k = -1;
	while (++k < j)
		n_string[k] = n_exp[k];
	while (n_str[start])
		n_string[k++] = n_str[start++];
	n_string[k] = '\0';
	return (n_string);
}

char	*add_plus_string(char **export, char *new_str)
{
	int		i;
	int		start;
	int		is_equal;
	char	*new_string;
	char	*new_export;

	i = 0;
	start = 0;
	is_equal = -1;
	new_str = add_quotes(new_str, 1);
	start = get_start(new_str);
	while (export[i])
	{
		if (!ft_strncmp(export[i], new_str, start))
		{
			new_export = ft_strdup(export[i]);
			is_equal = 0;
		}
		i++;
	}
	if (!is_equal && new_export)
		new_string = the_added_string(new_export, export, new_str, start);
	else
		new_string = new_str;
	return (new_string);
}
