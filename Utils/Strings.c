/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 20:23:34 by aaitouna          #+#    #+#             */
/*   Updated: 2023/04/16 10:31:36 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

size_t	size(char **ptr)
{
	size_t	i;

	i = 0;
	if (!ptr)
		return (0);
	while (ptr[i])
		i++;
	return (i);
}

char	**append(char **Strings, char *String)
{
	int		i;
	int		len;
	char	**new_strings;

	i = 0;
	if (Strings == NULL)
		len = 0;
	else
		len = size(Strings);
	new_strings = malloc((len + 2) * sizeof(char *));
	while (i < len)
	{
		new_strings[i] = ft_strdup(Strings[i]);
		i++;
	}
	new_strings[i++] = String;
	new_strings[i] = NULL;
	if (Strings != NULL)
		free_list(Strings);
	return (new_strings);
}

char	*m_safe_strjoin(char *s1, char *s2, int free_mode)
{
	char	*str;

	if (!s1)
		s1 = ft_strdup("");
	if (!s2)
		s2 = ft_strdup("");
	str = ft_strjoin(s1, s2);
	if (free_mode == 1 || free_mode == 3)
		free(s1);
	if (free_mode == 2 || free_mode == 3)
		free(s2);
	return (str);
}

char	*lower_case(char *command)
{
	int	i;

	i = 0;
	if (!command)
		return (NULL);
	while (command[i])
	{
		command[i] = ft_tolower(command[i]);
		i++;
	}
	return (command);
}
