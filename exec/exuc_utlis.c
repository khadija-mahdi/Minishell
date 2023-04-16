/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exuc_utlis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmahdi <kmahdi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 06:08:19 by kmahdi            #+#    #+#             */
/*   Updated: 2023/04/16 07:37:57 by kmahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1 && s2 && s1[i] && s2[i] && s1[i] == s2[i])
	{	
		i++;
	}
	return (s1[i] - s2[i]);
}

void	exit_msg(char *msg, int i)
{
	printf("%s", msg);
	printf("killing by %d \n", i);
	exit(i);
}

int	f_isdigit(int c)
{
	if (c >= '0' && c <= '8')
		return (1);
	return (0);
}

int	ft_is_alnum(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) \
		|| (c >= 48 && c <= 57) || c == '_')
		return (1);
	return (0);
}

int	comparison(char *s1, char *s2)
{
	int	index1;
	int	index2;

	index1 = get_name_index(s1);
	index2 = get_name_index (s2);
	if (index1 == -1)
		index1 = ft_strlen(s1);
	if (index2 == -1)
		index2 = ft_strlen(s2);
	if ((index2 - index1) == 0 && !ft_strncmp(s1, s2, index2))
		return (1);
	return (0);
}
