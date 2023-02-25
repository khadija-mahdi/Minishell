/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitouna <aaitouna@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:03:18 by aaitouna          #+#    #+#             */
/*   Updated: 2023/02/25 10:04:46 by aaitouna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	n;

	n = ft_strlen(s);
	ptr = malloc(n + 2);
	if (ptr == NULL)
		return (NULL);
	if (n == 0)
	{
		*ptr = 0;
		return (ptr);
	}
	ft_strlcpy(ptr, s, n + 1);
	return (ptr);
}
