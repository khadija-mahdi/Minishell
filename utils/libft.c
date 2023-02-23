/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:39:16 by kmahdi            #+#    #+#             */
/*   Updated: 2023/02/22 17:47:18 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	i = 0;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (dst == 0 && src == 0)
		return (0);
	if (dst == src)
		return (dst);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*dst;

	len = ft_strlen(s1) + 1;
	dst = malloc(len * sizeof(char));
	if (!dst)
		return (NULL);
	ft_memcpy(dst, s1, len);
	return (dst);
}
int ft_strcmp(char *s1, char *s2)
{
	int i = 0;
	
	while(s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{	
		i++;
	}
	return (s1[i] - s2[i]);

}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] && s2[i]) && i <= n - 1)
	{
		if ((unsigned char)s1[i] == (unsigned char)s2[i])
		i++;
		else
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	if (i > n - 1)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
char	*ft_strnstr(const char *haystack, const char *needle, int len)
{
	if (*needle && len == 0)
		return (0);
	if (!*needle)
		return ((char *) haystack);
	while (*haystack && len >= ft_strlen(needle))
	{
		if (*haystack == *needle
			&& !ft_strncmp(haystack, needle, ft_strlen(needle)))
			return ((char *) haystack);
		haystack++;
		len--;
	}
	return (0);
}
