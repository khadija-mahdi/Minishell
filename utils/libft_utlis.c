/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utlis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:36:02 by kmahdi            #+#    #+#             */
/*   Updated: 2023/02/22 15:43:56 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_substr(char const *s, int start, int len)
{
	int		i;
	char	*j;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	j = malloc((len + 1) * sizeof(char));
	if (!j)
		return (NULL);
	i = 0;
	while (s[i + start] && i < len)
	{
		j[i] = s[start + i];
		i++;
	}
	j[i] = '\0';
	return (j);
}

int	ft_words_count(const char *s, char c)
{
	size_t	i;
	int		len;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			len++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (len);
}

int	get_world_len(char const *sm, char c)
{
	int	len;

	len = 0;
	while (sm[len] && sm[len] != c)
		len++;
	return (len);
}

char	**free_stuff(char **k)
{
	int	i;

	i = 0;
	while (k[i])
	{
		free(k[i]);
		i++;
	}
	free(k);
	k = NULL;
	return (k);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**k;

	if (!s)
		return (NULL);
	k = (char **)malloc((ft_words_count(s, c) + 1) * (sizeof(char *)));
	if (!k)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			k[i] = ft_substr(s, 0, get_world_len(s, c));
			if (!k[i])
				return (free_stuff(k));
			s += get_world_len(s, c);
			i++;
		}
	}
	k[i] = 0;
	return (k);
}