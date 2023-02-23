/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:04:43 by kmahdi            #+#    #+#             */
/*   Updated: 2023/02/22 15:34:19 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


int	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*j;

	j = (char *)s;
	i = 0;
	while (j[i])
	{
		if (j[i] == (char)c)
		{
			return (j + i);
		}
		i++;
	}
	if ((char) c == '\0')
		return (j + i);
	return (0);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*j;

	j = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		j[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*s;

	if (count && size > SIZE_MAX)
		return (0);
	s = malloc(count * size);
	if (!s)
		return (NULL);
	ft_bzero (s, count * size);
	return (s);
}
char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	char	*j;

	if (!s1 || !s2)
		return (NULL);
	i = 0 ;
	j = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!j)
		return (NULL);
	while (s1[i])
	{
		j[i] = s1[i];
		i++;
	}
	i = 0 ;
	while (s2[i])
	{
		j[ft_strlen(s1) + i] = s2[i];
		i++;
	}
	j[ft_strlen(s1) + i] = '\0';
	return (j);
}